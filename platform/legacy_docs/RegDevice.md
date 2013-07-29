h1. RegDevice

<pre>
endpoint: users/regdevice
args:
udid: STRING
push_token: STRING
os_name: STRING
name: STRING [Optional]
brand: STRING [Optional]
model: STRING [Optional]
os_version: STRING [Optional]

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/143/regdevice?token=b64f49553d5c441652e95697a2c5949e udid='xxxxxxxasdfdfsadf' push_token='yyysadfasdfafdsfsdfasdfasdfasdfyyxy' os_name='iOS' os_version='6.0' brand='Apple' model='iPhone 4' name="Leask's iPhone"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.5
Set-Cookie: PHPSESSID=eto44af0n9l6nm21b6hgflt0e1; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Tue, 28 Aug 2012 06:05:04 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "os_name": "iOS", 
        "os_version": "6.0", 
        "push_token": "yyysadfasdfafdsfsdfasdfasdfasdfyyxy", 
        "udid": "xxxxxxxasdfdfsadf", 
        "user_id": 143
    }
}

</pre>