h1. GetAvailableBackgrounds

<pre>
endpoint: Backgrounds/getAvailableBackgrounds

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get http://api.local.exfe.com/v2/Backgrounds/getAvailableBackgrounds
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.6
Set-Cookie: PHPSESSID=r5cl9815rbi42jkm7o789sbit6; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Sun, 09 Sep 2012 07:29:47 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "backgrounds": [
            "daisy.jpg", 
            "goldenpine.jpg", 
            "gyangze.jpg", 
            "hongkong.jpg", 
            "lantern.jpg", 
            "manhattan.jpg", 
            "mountains.jpg", 
            "paris.jpg", 
            "pier39.jpg", 
            "RedRiverValley.jpg", 
            "sydney.jpg", 
            "westlake.jpg", 
            "zhujiajiao.jpg"
        ]
    }
}
</pre>