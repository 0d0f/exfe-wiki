h1. Signout

<pre>
POST:
device_token: string
uuid            : string
os_name    : string

example: 
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/143/signout?token=b64f49553d5c441652e95697a2c5949e udid='xxxxxxxasdfdfsadf' os_name='iOS' 
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.5
Set-Cookie: PHPSESSID=ijsqmvoq04ts5973f88j9n5i56; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Thu, 30 Aug 2012 08:03:52 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "os_name": "iOS", 
        "udid": "xxxxxxxasdfdfsadf", 
        "user_id": 143
    }
}
</pre>