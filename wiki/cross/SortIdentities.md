h1. SortIdentities

<pre>
endpoint: users/sortIdentities

args/get:
    token: 当前用户token

args/post:
    identity_order: json 数组，需要排序的身份id

returns:
    identity_order: 身份顺序

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/Users/208/sortIdentities?token=764ca290b978ddc65e1364e50b36925722f2803f201b70903346c3858c42c202 identity_order='[500, 498, 331, 499]'
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.6
Set-Cookie: PHPSESSID=m7qrt204kfe267ale8a5pdm5q4; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Thu, 20 Sep 2012 18:47:07 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "identity_order": [
            500, 
            498, 
            331, 
            499
        ]
    }
}

</pre>
