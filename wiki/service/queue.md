# exfe队列

## 说明

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