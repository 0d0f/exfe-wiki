# 队列服务

## 说明

队列以redis为基础，分为服务端server和客户端client。

 - 服务端任务

    - 维护redis队列，接受队列的入队消息，并根据任务的ontime信息维护是否触发任务。

    - 任务触发，发送消息给客户端。

    - 如果任务失败，根据失败的ontime消息重新设置队列，并维护时间调度。

 - 客户端任务

    - 如果有任务，由客户端放入队列，并做相应设置，最后发消息通知服务端做任务调度。

    - 如果接收到任务消息，从相应队列取出消息（可以一次取出多个消息）并处理

        - 如果处理成功，将相应的任务数从队列里清除，不用通知服务端

        - 如果失败，则发送失败消息给服务端，服务端需要根据失败消息的ontime重新维护任务队列。

## 接口

 - 操作对象

    - push channel

        redis名字：

            prefix..":action:push"

        此channel监听客户端的push请求，有此请求的时候，需要重新调度触发队列。

    - timer

        redis名字：

            prefix..":timer", Sorted Set

        member为队列的key，score为要出发的时间（unix timestamp in second）

    - queue key

        redis名字：

            prefix..":queue:"..key, List

        分key的队列，存储key下的任务数据

    - queue key data

        redis名字：

            prefix..":queue:"..key..":data", Set

        存储key队列相关的数据，由客户端指定，并由客户端操作。当队列内任务全部移除时，清空此数据。

    - locker

        redis名字：

            prefix..":queue:"..key..":locker", Set

        当存在locker的时候，不能读取对应key队列的数据。locker会带有expire设置，数据为客户端拉数据时提交的超时秒数。

    - overwrite

        redis名字：

            prefix..":queue:"..key..":overwrite", Set

        当存在overwrite的时候，下次push忽略always/once的设置，总是复写key队列对应的触发时间。

        当任务失败时，设置overwrite。这样当有新任务进来时，按照新任务的设定触发时间，而不考虑重试任务的时间设置。

    - start

        redis名字：

            prefix..":queue:"..key..":start", Set

        当任务开始时，设置此对象为任务开始时间。当任务被get时，清除此对象。如果在一定时间内没有worker对此queue做get动作，则清除整条队列。

 - 动作

    - Push 参数：key, task, data, ontime, overwrite

        客户端发起

            - 向对应的queue key队列RPUSH数据task

            - 写入queue key data相关数据data

            - 如果overwrite参数为always或者queue key队列有对应的overwrite对象，用ontime覆盖timer内key对应的值

            - 发送消息给push channel。

    - Get 参数：key，number，timeout，random

        任务端发起

            - 需要先试图在queue key对应的locker存储一个random（如果有不能覆盖原值），并对locker设置timeout，如果存储成功视为成功锁住queue key。

            - 锁成功后

                - 删除queue对应的start对象

                - 设置queue key的overwrite对象

                - 设置queue key的调度时间为timeout之后

                - 从queue key用LRANGE取顶部number条task并处理。

        如果在timeout时间内处理成功，调用Complete动作；如果处理不成功或者超过timeout时间，调用Release动作。

    - Complete 参数：key，number

        任务端发起，如果queye key没有locker对象，视为操作无效。

            - 移除queue key对应的overwrite对象

            - 从queue key内LTRIM顶部的number条task

            - 如果queue key内没有task，清除queue key data并移除queue key在timer内的值

            - 最后移除queue key对应的locker对象。

    - Release 参数：key, ontime

        任务端发起

            - 清除queue key对应的locker对象。

            - 如果有ontime，则将queue key在timer内对应的时间设为ontime

        如果遇到timeout，queue key的locker对象会自动清除，相当于执行了release操作。

    - Schedule

        任务端发起

            - 查看已经start的queue是否过期，如果过期，干掉整条queue

            - 查看timer是否有到期的queue

                - queue没有到期，返回距离下一个将要到期的queue的时间

                - 有queue到期

                    - 设置queue对应的start时间为当前时间

                    - 返回queue对应的key

    - Wait 参数：timeout

        任务端发起

            - 等待一段时间timeout。

            - 如果push channel有信号，立刻停止等待。




假设队列服务架设在本机127.0.0.1的23334端口。接口：

    http://127.0.0.1:23334/v3/queue/{merge_key}/{method}/{service}

参数merge_key是合并的key，所有merge_key，method，service三项一样的队列请求，在队列时间到达后会一并发送给service作处理。如果不需要合并，merge_key需要以“-”开头。

参数method表示队列时间到达后，发送给service时的http动作。一般为POST。

参数service是队列时间到达后，发送到的服务地址。地址需要先进行url base64

 - POST

    ## 功能

        将POST内容存入队列。

    ## 参数

        参数ontime表示此队列到达时间timestamp，到达此时间时，该条队列里的值将交给service处理。

        参数update表示是否修改已有的队列时间ontime，always表示总是用新的ontime替换现有队列的值，once表示只在新队列时使用ontime值。

            http://127.0.0.1:23334/v3/queue/{merge_key}/{method}/{service}?update={update}&ontime={ontime}

    ## 内容

        {...} // 入队的数据

    ## 例子

     - 发送摘要邮件：

        接收者identity id为789，cross id为123。在1366614150时发送。

            curl "http://127.0.0.1:23334/v3/queue/cross123_789/POST/aHR0cDovLzEyNy4wLjAuMToyMzMzMy92My9ub3RpZmllci9jcm9zcy9kaWdlc3Q=?update=always&ontime=1366614150" -d '{
                "to": {"identity_id": 789, ...},
                "cross_id": 123,
                "updated_at": "2013-04-24 00:00:00"
            }'

 - DELETE

    ## 功能

        删除指定队列内现存的所有内容。

    ## 例子

        删除所有接收者identity id为789，cross id为123要发送的内容。

            curl "http://127.0.0.1:23334/v3/queue/cross123_789/POST/aHR0cDovLzEyNy4wLjAuMToyMzMzMy92My9ub3RpZmllci9jcm9zcy9kaWdlc3Q=" -X DELETE