h1. ForgotPassword

<pre>
endpoint: users/ForgotPassword
args: external_username, provider

example:

leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/forgotpassword provider="email" external_username="i@leaskh.com"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.4
Set-Cookie: PHPSESSID=pa7qlfoi0d8o89hnq8b7b4o912; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Mon, 23 Jul 2012 05:37:28 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "action": "VERIFYING", 
        "identity": {
            "avatar_filename": "http://www.gravatar.com/avatar/5b53fb71b6f36f46fe9cb14eb5acd56f?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fget%3Fprovider%3Demail%26external_id%3Di%40leaskh.com", 
            "bio": "", 
            "connected_user_id": 207, 
            "created_at": "2012-05-17 15:56:42", 
            "external_id": "i@leaskh.com", 
            "external_username": "i@leaskh.com", 
            "id": 324, 
            "name": "Leask", 
            "nickname": "", 
            "provider": "email", 
            "type": "identity", 
            "updated_at": null
        }
    }
}
</pre>