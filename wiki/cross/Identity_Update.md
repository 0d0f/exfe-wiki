h1. Update  public


method: post,
endpoint: api.local.exfe.com/v2/identities/[identities_id]/update?token=[string]
args: token, name, bio
return: identity object

<pre>
leask@Flora:~/Downloads> http -f post api.local.exfe.com/v2/identities/233/update?token=sadfsadfsdafsdf bio="ok"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.3.13
Set-Cookie: PHPSESSID=q4vq2u9f1lt748lcqrpqc7i804; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Thu, 31 May 2012 10:36:54 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "identity": {
            "avatar_filename": "http://img.local.exfe.com/8/6f/86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
            "bio": "ok", 
            "connected_user_id": 143, 
            "created_at": "2012-05-08 18:37:59", 
            "external_id": "tester_leonard@0d0f.com", 
            "external_username": "tester_leonard@0d0f.com", 
            "id": 233, 
            "name": "\u6566\u5b57", 
            "nickname": "", 
            "provider": "email", 
            "type": "identity", 
            "updated_at": "2012-05-31 18:36:54"
        }
    }
}
</pre>