h1. getRegistrationFlag

<pre>

method: get,
endpoint: api.local.exfe.com/v2/users/getRegistrationFlag
args: external_username, provider



return:
SIGN_UP, SIGN_IN, VERIFY, AUTHENTICATE

example:

leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get api.local.exfe.com/v2/users/GetRegistrationFlag?external_username=tester_leonard@0d0f.com\&provider=email
HTTP/1.1 200 OK
X-Powered-By: PHP/5.3.13
Set-Cookie: PHPSESSID=i30mk61qbbbsbosvvmf6ddp9b4; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Thu, 24 May 2012 07:18:41 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "identity": {
            "avatar_filename": "http://img.local.exfe.com/8/6f/86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
            "bio": "I am a physicist at CalTech and live with my best friend Sheldon.", 
            "connected_user_id": 143, 
            "created_at": "2012-05-08 18:37:59", 
            "external_id": "tester_leonard@0d0f.com", 
            "external_username": "tester_leonard@0d0f.com", 
            "id": 233, 
            "name": "Leonard Hofstadter", 
            "nickname": "", 
            "provider": "email", 
            "type": "identity", 
            "updated_at": null
        }, 
        "registration_flag": "SIGN_IN"
    }
}
</pre>