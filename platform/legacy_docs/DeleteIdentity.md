h1. DeleteIdentity

<pre>
endpoint: users/deleteIdentity
args/get:
    token: string user token
args/post:
    identity_id: integer
return:
    identity_id: integer
    user_id: integer

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/208/deleteIdentity?token=764ca290b978ddc65e1364e50b3692572ecd909a376724af3dd0f1b7f11872de identity_id=498
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.6
Set-Cookie: PHPSESSID=2bnatc68lev0ruo8a560on7v26; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Wed, 19 Sep 2012 07:32:12 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "identity_id": 498, 
        "user_id": 208
    }
}
</pre>