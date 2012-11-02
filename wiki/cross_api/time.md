## Time API:
end point: api.exfe.com/v2/time

### recognize
  - method: post
  - args:
    * time_string: string
    * timezone: string
  - returns:
    * crosstime: object
  - example:

<pre>
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/time/recognize time_string='tomorrow' timezone='+08:00 CST'
HTTP/1.1 200 OK
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Content-Type: application/json; charset=UTF-8
Date: Wed, 31 Oct 2012 08:58:36 GMT
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Pragma: no-cache
Server: lighttpd/1.4.31
Set-Cookie: PHPSESSID=3pm9brrvcbic9vsh5m8j153cd1; path=/; domain=.exfe.com
Transfer-Encoding: chunked
X-Powered-By: PHP/5.4.7

{
    "meta": {
        "code": 200
    },
    "response": {
        "cross_time": {
            "begin_at": {
                "date": "2012-11-01",
                "date_word": "",
                "id": 0,
                "time": "",
                "time_word": "",
                "timezone": "+08:00 CST",
                "type": "EFTime"
            },
            "id": 0,
            "origin": "tomorrow",
            "outputformat": 0,
            "type": "CrossTime"
        }
    }
}
</pre>

