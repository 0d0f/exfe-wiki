h1. For Gobus

<pre>
Identity Update:
method: post,
endpoint: /v2/Gobus/UpdateIdentity
args: id, provider, external_id, name, nickname, bio, avatar_filename, external_username
return: http 200 / http 500
</pre>


<pre>
Post conversation:
method: post,
endpoint: /v2/Gobus/PostConversation
args: per_user_hash, content, external_id, provider, time, cross_id
example:

http -f post api.local.exfe.com/v2/Gobus/PostConversation cross_id="11a" content="Hello 你好" external_id="tester_leonard@0d0f.com" "provider"="email" time="2012-07-06 06:52:56"
HTTP/1.1 200 OK

http -f post api.local.exfe.com/v2/Gobus/PostConversation iom="aa" content="Hello 你好" external_id="tester_leo" "provider"="twitter" time="Wed July 06 06:52:56 +0000 2012"
HTTP/1.1 200 OK
</pre>


<pre>
Notification Callback:
method: post
endpoint: /v2/Gobus/NotificationCallback
args:
    {
        "recipient" : [object],
        "error"     : [string]
    }
example:

echo '{"recipient":{"external_username":"xxxxxxxasdfdfsadf","provider":"iOS"},"error":"asd"}' | http api.local.exfe.com/v2/Gobus/NotificationCallback
HTTP/1.1 200 OK
</pre>


<pre>
Revoke Identity:
method: post
endpoint: /v2/Gobus/RevokeIdentity
args:
    {
        "id"                : [integer],
        "external_username" : [string],
        "provider"          : [string]
    }
example:

echo '{"id":1,external_username":"leaskh","provider":"twitter"}' | http post local.exfe.com/v2/gobus/revokeIdentity
HTTP/1.1 200 OK
identity[json]
</pre>


<pre>
GetCrossById:
method: get
endpoint: /v2/Gobus/GetCrossById
args: id(uint64)
return: cross json(http 200) / [empty](http 404)
example:

http api.local.exfe.com/v2/Gobus/GetCrossById?id=100307
HTTP/1.1 200 OK
</pre>


Response:
200: 正常
400: 需要反馈给用户的错误
500: 不需要反馈用户，记log丢弃的错误
