# 拆分服务

## 说明

配合队列使用的多recipient拆分服务，可以将一次请求的多个recipient拆到data的to子句里。

假设service架设在127.0.0.1的23333端口。

	http://127.0.0.1:23333/v3/splitter

POST内容：

	{
        "recipients": [{...},{...}], // 多个recipient对象
        "merge_key": "...", // 拆分后的请求入队时的merge key，见queue参数merge_key
        "method": "...", // 拆分后的请求入队时的method，见queue参数method
        "service": "...", // 拆分后的请求入队时的service，见queue参数service
        "type": "always", // 拆分后的请求入队时的type，见queue参数type
        "ontime": 1366614150, // 拆分后的请求入队时的ontime，见queue参数ontime
        "data": {...} // 其它数据。拆分时会将recipients拆分，分别插入data的to字段，再存入队列。
    }

## 例子：

 - 发送digest，其中包括identity id为789。

 	curl "http://127.0.0.1:23333/v3/splitter" -d '{
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
