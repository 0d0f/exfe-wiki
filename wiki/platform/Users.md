# Users

    author: Leask Huang
    created date: 2012-10-06
    updated date: 2013-05-31


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
    * description: merge identities by merge token
    * POST:
        - identity_ids: [json_array:identity_ids]
* args OPTION C:
    * description: merge identities by user token and invitation token
    * QUERY
        - token: [str:user_token]
    * POST:
        - invitation_token: [str:invitation_token]
* returns:
    - 200: 成功 / 部分成功(部分成功将来在v3将返回206)
        * status: [array:identities] // 合并结果
        * mergeable_user: [object:user] // 仍可继续合并的用户及其身份
    - 400: error_browsing_identity_token
    - 400: error_invitation_token
    - 400: no_identity_ids
    - 400: error_user_status
    - 401: no_signin
    - 500:server_error
* demo:

        #!javascript
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

