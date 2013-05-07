# OAuth
    author: Leask Huang
    created date: 2013-02-26
    updated date: 2013-05-05


## ReverseAuth
* endpoint: /oauth/reverseauth
* POST args:
    - provider: [string]
    - oauth_token: [string]
    - oauth_token_secret: [string] // twitter needed
    - oauth_expires: [string] // facebook needed
* returns:
    - oauth_signin:

            #!javascript
            {
                "user_id" : [int],
                "token" : [string],
                "name" : [string],
                "password" : [bol]
            }

    - identity: [object:identity]
    - provider: [string]
    - identity_status: [string:new/connected/revoked/verifying]
    - twitter_following: [bol] // twitter only

* demo:

        #!bash
        http -f post http://panda.0d0f.com/oauth/ReverseAuth provider='facebook' oauth_token='BAAGK4vkbwaIBAP8zzYca1gqfhEvg1KtPtFuPayQb69UK8JZCHTMPHS6KCUdUDeS9JlSJzwWeSlkImNNGXidBt0TbCDZBx3E1O2fSUtroJpCmbNlw3ZAi9rKXiFzI0XnHIbXb6qZAeKSpBjsuTeF7BuQtPqvTjKN1bKGpkgQp3GGyQh9kl8HXYjWdtawz0kEjXHZCBEEGV8DlW0ZCkf3fO6' oauth_expires=1372061029
        {
            "data": {
                "identity": {
                    "avatar_filename": "https://graph.facebook.com/554148635/picture?type=large",
                    "bio": "",
                    "connected_user_id": 379,
                    "created_at": "2013-04-02 14:17:52 +0000",
                    "external_id": "554148635",
                    "external_username": "leaskh",
                    "id": 638,
                    "name": "Leask Huang",
                    "nickname": "",
                    "order": 5,
                    "provider": "facebook",
                    "type": "identity",
                    "unreachable": false,
                    "updated_at": "2013-04-02 14:17:52 +0000"
                },
                "identity_status": "connected",
                "oauth_signin": {
                    "name": "Leask Huang",
                    "password": true,
                    "token": "83b51dc311b4bd3ff700fd69a4956afa301313b29f011a251f767fbdcaf60247",
                    "user_id": 379
                },
                "provider": "facebook"
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
