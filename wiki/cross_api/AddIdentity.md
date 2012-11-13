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
leask@Flora:~/Documents/Working/exfe/wiki/wiki:master*> http -f post api.local.exfe.com/v2/users/208/addIdentity?token=8ffe646aba87e9f746f5502d6d43dfce596a4d3aa785561cafadbb8ac4a29990 external_username='xxx@leaskh.com' provider='email'
HTTP/1.1 200 OK
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Content-Type: application/json; charset=UTF-8
Date: Tue, 13 Nov 2012 04:02:07 GMT
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Pragma: no-cache
Server: lighttpd/1.4.31
Set-Cookie: PHPSESSID=mhun6ajik552qhre4kp22jajn1; path=/; domain=.exfe.com
Transfer-Encoding: chunked
X-Powered-By: PHP/5.4.8

{
    "meta": {
        "code": 200
    },
    "response": {
        "action": "VERIFYING",
        "identity": {
            "avatar_filename": "http://img.local.exfe.com/e/77/80_80_e77180a5f0d3f6022f2629b58dd83734.png",
            "bio": "",
            "connected_user_id": 208,
            "created_at": "2012-09-19 06:43:41 +0000",
            "external_id": "xxx@leaskh.com",
            "external_username": "xxx@leaskh.com",
            "id": 498,
            "name": "xxx",
            "nickname": "",
            "order": 0,
            "provider": "email",
            "status": "VERIFYING",
            "type": "identity",
            "updated_at": "2012-10-22 07:00:20 +0000"
        }
    }
}

leask@Flora:~/Documents/Working/exfe/wiki/wiki:master*> http -f post api.local.exfe.com/v2/users/208/addIdentity?token=8ffe646aba87e9f746f5502d6d43dfce596a4d3aa785561cafadbb8ac4a29990 provider='twitter'
HTTP/1.1 200 OK
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Content-Type: application/json; charset=UTF-8
Date: Tue, 13 Nov 2012 04:02:20 GMT
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Pragma: no-cache
Server: lighttpd/1.4.31
Set-Cookie: PHPSESSID=alp9sh3crvk0at3nie42ojoi32; path=/; domain=.exfe.com
Transfer-Encoding: chunked
X-Powered-By: PHP/5.4.8

{
    "meta": {
        "code": 200
    },
    "response": {
        "action": "VERIFYING",
        "identity": null,
        "url": "https://api.twitter.com/oauth/authenticate?oauth_token=VA59PkDsNqnLeroeEcGy0vgw1IaDv5tYqbhSNaWSJ0"
    }
}
</pre>
