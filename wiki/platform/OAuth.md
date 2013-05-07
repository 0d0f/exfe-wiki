# OAuth
    author: Leask Huang
    created date: 2013-05-06
    updated date: 2013-05-07


## ReverseAuth
* endpoint: /oauth/reverseauth
* POST args:
    - provider: [string]
    - oauth_token: [string]
    - oauth_token_secret: [string] // twitter needed
    - oauth_expires: [string] // facebook needed
* success returns:
    - user_id: [int]
    - token: [string]
* failed returns:
    - 400: invalid_token
    - 400: no_provider
    - 400: unsupported_provider
* twitter demo:

        #!bash
        http -f post http://panda.0d0f.com/oauth/reverseauth provider='twitter' oauth_token='10065202-MPscyFW22D7v8ow68BsJPFzRJvbaU9aBENVhPWQSk' oauth_token_secret='aMcSO80OOKiSNlHibV4KhFMu4FF4bw3KW39ivTKt0'

        {
            "meta": {
                "code": 200
            },
            "response": {
                "token": "fcfad293ef334ecbf8dd5ca811eb96b4301313b29f011a251f767fbdcaf60247",
                "user_id": 379
            }
        }

* facebook demo:

        #!bash
        http -f post http://panda.0d0f.com/oauth/ReverseAuth provider='facebook' oauth_token='BAAGK4vkbwaIBAP8zzYca1gqfhEvg1KtPtFuPayQb69UK8JZCHTMPHS6KCUdUDeS9JlSJzwWeSlkImNNGXidBt0TbCDZBx3E1O2fSUtroJpCmbNlw3ZAi9rKXiFzI0XnHIbXb6qZAeKSpBjsuTeF7BuQtPqvTjKN1bKGpkgQp3GGyQh9kl8HXYjWdtawz0kEjXHZCBEEGV8DlW0ZCkf3fO6' oauth_expires=1372061029

        {
            "meta": {
                "code": 200
            },
            "response": {
                "token": "a5e2ef0d7a14207528e2e5ae5cda80c9301313b29f011a251f767fbdcaf60247",
                "user_id": 379
            }
        }














///////////////////////////////////////// OLD /////////////////////////////////


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
