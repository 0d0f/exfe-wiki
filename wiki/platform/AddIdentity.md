## AddIdentity
    author: Leask Huang
    created date: 2013-05-28
    updated date: 2013-05-28

# Add Identity
* endpoint: users/addIdentity
* QUERY args:
    - token: [str:user_token]
* POST args OPTION A:
    - external_username: [string]
    - provider: [string]
    - device: [string]
    - device_callback: [str:url]
* POST args OPTION B (reverse auth):
    - provider: [string]
    - oauth_token: [string]
    - oauth_token_secret: [string]
    - oauth_expires: [string]
* return:
    - action: [string:VERIFYING]
    - identity: [object:identity]
    - url: [str:url]
* example:

        #!bash
        $ http -f post api.panda.0d0f.com/v2/users/208/addIdentity?token=8ffe646aba87e9f746f5502d6d43dfce596a4d3aa785561cafadbb8ac4a29990 external_username='xxx@leaskh.com' provider='email'
        {
            "meta": {
                "code": 200
            },
            "response": {
                "action": "VERIFYING",
                "identity": {
                    "avatar_filename": "http://img.local.exfe.com/e/77/80_80_e77180a5f0d3f6022f2629b58dd83734.png",
                    "bio": "",
                    "connected_user_id": 208,
                    "created_at": "2012-09-19 06:43:41 +0000",
                    "external_id": "xxx@leaskh.com",
                    "external_username": "xxx@leaskh.com",
                    "id": 498,
                    "name": "xxx",
                    "nickname": "",
                    "order": 0,
                    "provider": "email",
                    "status": "VERIFYING",
                    "type": "identity",
                    "updated_at": "2012-10-22 07:00:20 +0000"
                }
            }
        }

        $ http -f post api.panda.0d0f.com/v2/users/208/addIdentity?token=8ffe646aba87e9f746f5502d6d43dfce596a4d3aa785561cafadbb8ac4a29990 provider='twitter'
        {
            "meta": {
                "code": 200
            },
            "response": {
                "action": "VERIFYING",
                "identity": null,
                "url": "https://api.twitter.com/oauth/authenticate?oauth_token=VA59PkDsNqnLeroeEcGy0vgw1IaDv5tYqbhSNaWSJ0"
            }
        }

        $ http -f post api.leask.0d0f.com/v2/users/addidentity?token=50c5e5b47ef77b8d8daa2d7fda2f8b56301313b29f011a251f767fbdcaf60247 provider='twitter' oauth_token='10065202-MPscyFW22D7v8ow68BsJPFzRJvbaU9aBENVhPWQSk' oauth_token_secret='aMcSO80OOKiSNlHibV4KhFMu4FF4bw3KW39ivTKt0'
        {
            "meta": {
                "code": 200
            },
            "response": {
                "identity": {
                    "avatar_filename": "http://img.twitter.com/e/77/80_80_e77180a5f0d3f6022f2629b58dd83734.png",
                    "bio": "",
                    "connected_user_id": 208,
                    "created_at": "2012-09-19 06:43:41 +0000",
                    "external_id": "1231231312",
                    "external_username": "leaskh",
                    "id": 498,
                    "name": "Leask Huang",
                    "nickname": "",
                    "order": 0,
                    "provider": "twitter",
                    "status": "CONNECTED",
                    "type": "identity",
                    "updated_at": "2012-10-22 07:00:20 +0000"
                }
            }
        }
