h1. Oauth signin

<pre>
endpoint: oauth/TwitterAuthenticate
method: get

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get local.exfe.com/oauth/TwitterAuthenticate
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.4
Set-Cookie: PHPSESSID=68djhq7hciahmjmf79gc0f6uo1; path; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-type: text/html
Transfer-Encoding: chunked
Date: Mon, 30 Jul 2012 07:19:03 GMT
Server: lighttpd/1.4.31

{"meta":{"code":200},"response":{"redirect":"https/\/api.twitter.com\/oauth\/authenticate?oauth_token=eaIszDapB6I8UvjfDf0pGOOmEnGZUNqMeIa5Xs6HYs"}}
</pre>


<pre>
endpoint: oauth/Authenticate
method: get
args:
    provider (twitter / facebook / ...)

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get local.exfe.com/oauth/Authenticate?provider=twitter
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.4
Set-Cookie: PHPSESSID=68djhq7hciahmjmf79gc0f6uo1; path; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-type: text/html
Transfer-Encoding: chunked
Date: Mon, 30 Jul 2012 07:19:03 GMT
Server: lighttpd/1.4.31

{"meta":{"code":200},"response":{"redirect":"https/\/api.twitter.com\/oauth\/authenticate?oauth_token=eaIszDapB6I8UvjfDf0pGOOmEnGZUNqMeIa5Xs6HYs"}}
</pre>
