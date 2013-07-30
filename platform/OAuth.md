# OAuth
    author: Leask Huang
    created date: 2013-05-06
    updated date: 2013-05-07


## Authenticate
* endpoint: oauth/Authenticate
* QUERY args:
    - provider : [str:twitter/facebook/google/dropbox/instagram/flickr]
* returns:
    - redirect : [str:url]
* demo:
        #!bash
        http -f post http://panda.0d0f.com/oauth/Authenticate?provider=twitter
        {
            "meta": {
                "code":200
            },
            "response": {
                "redirect":"https/\/api.twitter.com\/oauth\/authenticate?oauth_token=eaIszDapB6I8UvjfDf0pGOOmEnGZUNqMeIa5Xs6HYs"
            }
        }


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
        http -f post http://panda.0d0f.com/oauth/reverseauth provider='facebook' oauth_token='BAAGK4vkbwaIBAP8zzYca1gqfhEvg1KtPtFuPayQb69UK8JZCHTMPHS6KCUdUDeS9JlSJzwWeSlkImNNGXidBt0TbCDZBx3E1O2fSUtroJpCmbNlw3ZAi9rKXiFzI0XnHIbXb6qZAeKSpBjsuTeF7BuQtPqvTjKN1bKGpkgQp3GGyQh9kl8HXYjWdtawz0kEjXHZCBEEGV8DlW0ZCkf3fO6' oauth_expires=1372061029

        {
            "meta": {
                "code": 200
            },
            "response": {
                "token": "a5e2ef0d7a14207528e2e5ae5cda80c9301313b29f011a251f767fbdcaf60247",
                "user_id": 379
            }
        }
