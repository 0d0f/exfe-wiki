# Users

    author: Leask Huang
    created date: 2012-10-06
    updated date: 2013-07-12


## Signin / Signup
* endpoint: /v2/users/signin
* POST args:
    - external_username: [str:external_username]
    - provider: [str:provider]
    - password: [str:password] // encoded by utf8 && length >= 4
* returns:
    - 200: {"user_id" : [int:user_id], "token" : [str:token]}
    - 400: no_external_username, external_username must be provided
    - 400: no_password, password must be provided
    - 400: no_provider, provider must be provided
    - 400: unsupported_provider, We are not supporting this kind of provider currently.
    - 400: weak_password, password must be longer than four
    - 403: failed, {"registration_flag" : [str:registration_flag]}
    - 500: failed, failed while signing up new user


## Setup
* endpoint: /v2/users/setup
* QUERY args:
    - token: [str:user_token]
* POST args:
    - name: [str:user / identity name]
    - password: [str:password] // encoded by utf8 && length >= 4
    - identity_id: [int:identity_id]
* returns:
    - 200:

            #!javascript
            {
                "authorization" : {
                    "user_id" : [str:user_id],
                    "token"   : [str:user_token]
                }
            }

    - 400: no_password, password must be provided
    - 400: weak_password, password must be longer than four
    - 401: invalid_token, Invalid Token


## Reset Password
* endpoint: /v2/users/resetpassword
* POST args:
    - token: [str:verification_token]
    - name: [str:user_name]
    - password: [str:password] // encoded by utf8 && length >= 4
* returns:
    - 200:

            #!javascript
            {
                "authorization" : {
                    "user_id" : [str:user_id],
                    "token"   : [str:user_token]
                }
            }

    - 400: no_password, password must be provided
    - 400: weak_password, password must be longer than four
    - 401: invalid_token, Invalid Token


## Set Password
* endpoint: /v2/users/setpassword
* * QUERY args:
    - token: [str:user_token]
* POST args:
    - current_password: [str:password] // optional
    - new_password: [str:password] // encoded by utf8 && length >= 4
* returns:
    - 200:

            #!javascript
            {
                "user_id" : [str:user_id],
                "token"   : [str:user_token]
            }

    - 400: no_new_password
    - 400: weak_password
    - 401: no_signin
    - 401: authenticate_timeout
    - 500: failed


## Add Identity
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
    - 200:
        * action: [string:VERIFYING]
        * identity: [object:identity]
        * url: [str:url]
    - 401: no_signin
    - 400: no_external_username
    - 400: unknow_provider
    - 400: invalid_oauth_token', '');
    - 400: duplicate
    - 500: failed
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


## Merge Identities
* endpoint: /v2/users/mergeidentities
* args OPTION A:
    * description: merge identities by two user tokens
    * QUERY:
        - token: [str:user_token]
    * POST:
        - browsing_identity_token: [str:user_token]
        - identity_ids: [json_array:identity_ids]
* args OPTION B:
    * description: merge identities by merge / verification token
    * POST:
        - token: [str:merge / verification token]
        - identity_ids: [json_array:identity_ids]
* args OPTION C:
    * description: merge identities by user token and invitation token
    * QUERY
        - token: [str:user_token]
    * POST:
        - refere: [str:authenticate_callback_url]
        - invitation_token: [str:invitation_token]
* returns:
    - 200 case 1: 成功 / 部分成功(部分成功将来在v3将返回206)
        * status: [array:identities] // 合并结果
        * mergeable_user: [object:user] // 仍可继续合并的用户及其身份
    - 200 case 2: 成功 / 部分成功(部分成功将来在v3将返回206)
        * action: [str: VERIFYING / REDIRECT]
        * url: [str:url] // only action === 'REDIRECT'
    - 400: error_browsing_identity_token
    - 400: error_invitation_token
    - 400: no_identity_ids
    - 400: error_user_status
    - 401: no_signin
    - 500:server_error
* example:

        #!bash
        http -f post api.local.exfe.com/v2/users/208/mergeIdentities?token=764ca290b978ddc65e1364e50b36925787c831802f62b83e8aafcf9dcbb9aa06 browsing_identity_token='8ec8efd1910c08dac8cc9301a14a2008bf3e9e13b054df6f64b122d76ef5fa3b' identity_ids='[499,500]'

        {
            "meta": {
                "code": 200
            },
            "response": {
                "mergeable_user": {
                    "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=yyy",
                    "bio": "",
                    "default_identity": {
                        "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=yyy",
                        "bio": "",
                        "connected_user_id": 305,
                        "created_at": "2012-09-19 09:23:08 +0000",
                        "external_id": "yyy@leaskh.com",
                        "external_username": "yyy@leaskh.com",
                        "id": 499,
                        "name": "yyy",
                        "nickname": "",
                        "provider": "email",
                        "status": "CONNECTED",
                        "type": "identity",
                        "updated_at": "2012-09-19 09:23:08 +0000"
                    },
                    "id": 305,
                    "identities": [
                        {
                            "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=e",
                            "bio": "",
                            "connected_user_id": 305,
                            "created_at": "2012-07-25 09:53:25 +0000",
                            "external_id": "e@leaskh.com",
                            "external_username": "e@leaskh.com",
                            "id": 364,
                            "name": "e",
                            "nickname": "",
                            "provider": "email",
                            "status": "CONNECTED",
                            "type": "identity",
                            "updated_at": "2012-07-25 09:53:25 +0000"
                        }
                    ],
                    "name": "Syxnx",
                    "timezone": "+08:00",
                    "type": "user"
                },
                "status": {
                    "499": {
                        "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=Leask",
                        "bio": "",
                        "connected_user_id": -540,
                        "created_at": "0000-00-00 00:00:00 +0000",
                        "external_id": "aa@leaskh.com",
                        "external_username": "aa@leaskh.com",
                        "id": 540,
                        "name": "Leask",
                        "nickname": "",
                        "order": 0,
                        "provider": "email",
                        "status": "VERIFYING",
                        "type": "identity",
                        "updated_at": "0000-00-00 00:00:00 +0000"
                    },
                    "500": {
                        "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=Leask",
                        "bio": "",
                        "connected_user_id": -540,
                        "created_at": "0000-00-00 00:00:00 +0000",
                        "external_id": "aa@leaskh.com",
                        "external_username": "aa@leaskh.com",
                        "id": 540,
                        "name": "Leask",
                        "nickname": "",
                        "order": 0,
                        "provider": "email",
                        "status": "VERIFYING",
                        "type": "identity",
                        "updated_at": "0000-00-00 00:00:00 +0000"
                    }
                }
            }
        }
