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
X-Powered-By: PHP/5.4.3
Set-Cookie: PHPSESSID=di4lbiuk17vmfre8fri8ocg451; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Content-Length: 0
Date: Thu, 07 Jun 2012 07:06:31 GMT
Server: lighttpd/1.4.30

http -f post api.local.exfe.com/v2/Gobus/PostConversation iom="aa" content="Hello 你好" external_id="tester_leo" "provider"="twitter" time="Wed July 06 06:52:56 +0000 2012"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.3
Set-Cookie: PHPSESSID=di4lbiuk17vmfre8fri8ocg451; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Content-Length: 0
Date: Thu, 07 Jun 2012 07:06:31 GMT
Server: lighttpd/1.4.30
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
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Content-Type: application/json; charset=UTF-8
Date: Wed, 14 Nov 2012 13:34:38 GMT
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Pragma: no-cache
Server: lighttpd/1.4.31
Set-Cookie: PHPSESSID=q4a2u0src7pebh12hhn2f7b3h1; path=/; domain=.exfe.com
Transfer-Encoding: chunked
X-Powered-By: PHP/5.4.8
</pre>

<pre>
Revoke Identity:
method: post
endpoint: /v2/Gobus/RevokeIdentity
args:
    {
        "external_username" : [string],
        "provider"          : [string]
    }
example:

echo '{"external_username":"leaskh","provider":"twitter"}' | http post local.exfe.com/v2/gobus/revokeIdentity
HTTP/1.1 200 OK
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Content-Type: application/json; charset=UTF-8
Date: Tue, 27 Nov 2012 08:59:22 GMT
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Pragma: no-cache
Server: lighttpd/1.4.31
Set-Cookie: PHPSESSID=65mc68nifjm281ohv8skcogvo2; path=/; domain=.exfe.com
Transfer-Encoding: chunked
X-Powered-By: PHP/5.4.8
</pre>



Response:
200: 正常
400: 需要反馈给用户的错误
500: 不需要反馈用户，记log丢弃的错误
