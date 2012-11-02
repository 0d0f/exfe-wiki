## AddIdentity

<pre>
endpoint: users/addIdentity
args/get:
    token: string / user token
args/post:
    external_username : string
    provider : string
return:
    identity : object

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/208/addIdentity?token=764ca290b978ddc65e1364e50b3692575c9460c764a1dd6a798d78db93aec13e external_username='xxx@leaskh.com' provider='email'
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.6
Set-Cookie: PHPSESSID=c84cb2ngo9jqagcahtacen7g57; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Wed, 19 Sep 2012 06:43:40 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    },
    "response": {
        "identity": {
            "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=xxx",
            "bio": "",
            "connected_user_id": -498,
            "created_at": "2012-09-19 06:43:41 +0000",
            "external_id": "xxx@leaskh.com",
            "external_username": "xxx@leaskh.com",
            "id": 498,
            "name": "xxx",
            "nickname": "",
            "provider": "email",
            "status": "VERIFYING",
            "type": "identity",
            "updated_at": "2012-09-19 06:43:41 +0000"
        }
    }
}
</pre>
