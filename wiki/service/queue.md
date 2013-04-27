# exfe队列

## 说明

假设队列服务架设在本机127.0.0.1的23334端口。接口：

    http://127.0.0.1:23334/v3/queue/{merge_key}/{method}/{service}?update={update}&ontime={ontime}

参数merge_key是合并的key，所有merge_key，method，service三项一样的队列请求，在队列时间到达后会一并发送给service作处理。如果不需要合并，merge_key需要以“-”开头，为了能分散服务器压力，即便不需要合并的merge_key，最好也能根据请求不同有不一样的值，最简单的做法是使用提交时的时间戳前面加“-”，比如“-1366614150”。

参数method表示队列时间到达后，发送给service时的http动作。一般为POST。

参数service是队列时间到达后，发送到的服务地址。此地址不包含schema部分。

参数ontime表示此队列到达时间timestamp，到达此时间时，该条队列里的值将交给service处理。

参数update表示是否修改已有的队列时间ontime，always表示总是用新的ontime替换现有队列的值，once表示只在新队列时使用ontime值。

POST内容：

    {...} // 入队的数据

## 例子：

 - 发送摘要邮件：

    接收者identity id为789，cross id为123。在1366614150时发送。

        curl "http://127.0.0.1:23334/v3/queue/cross123_789/POST/127.0.0.1:23333/v3/notifier/cross/digest?update=always&ontime=1366614150" -d '{
            "to": {"identity_id": 789, ...},
            "cross_id": 123,
            "updated_at": "2013-04-24 00:00:00"
        }'

 - 需要Splitter拆分发送给多个Recipient，之后下发摘要邮件：

    立刻发送（ontime为0），拆分后的其中一个请求和上一个例子一样。具体参见splitter的文档。

        curl "http://127.0.0.1:23334/v3/queue/-1366614139/POST/127.0.0.1:23333/v3/splitter?update=always&ontime=1366614139" -d '{
            "recipients": [{"identity_id": 789, ...},{...}],
            "merge_key": "cross123",
            "method": "POST",
            "service": "127.0.0.1:23333/v3/notifier/cross/digest",
            "type": "always",
            "ontime": 1366614150,
            "data": {
                "cross_id": 123,
                "updated_at": "2013-04-24 00:00:00"
            }
        }'
