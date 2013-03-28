h1. SetupUserByInvitationToken

<pre>
endpoint: users/SetupUserByInvitationToken
method: POST
args: invitation_token, name, password

example:

leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/SetupUserByInvitationToken invitation_token="2324fe281b38146df7489734e72e7847" name="bill" password="00000"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.4
Set-Cookie: PHPSESSID=25imru39k5j0t80id788fdfdv1; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Tue, 24 Jul 2012 10:20:28 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "signin": {
            "token": "2d406486c3a69d03b426dedb8e5d58ea", 
            "user_id": 283
        }
    }
}

</pre>