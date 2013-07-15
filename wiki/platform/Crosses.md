# Crosses
    author: Leask Huang
    created date: 2013-06-06
    updated date: 2013-07-15


## Check Invitation Token
* endpoint: /v2/crosses/checkinvitationtoken
* POST args:
    - invitation_token: [str:length = 32]
* returns:
    - 200: valid: [bol]
    - 400: no_token


## Get Free Identities // Works only with Wechat identities currently
* endpoint: /v2/crosses/[int:cross_id]/freeidentities
* QUERY args:
    - token: [str:cross_access_token] // ONLY ACCEPT Smith's cross token
* returns:
    - 200: [array:identities]
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized
    - 403: forbidden
    - 404: not_found
    - 500: server_error
* example:

        #!bash
        $ http api.leask.0d0f.com/v2/crosses/100640/freeidentities?token=d8bfe4936feaeaca678cd1d7c140f1c77d28de3e60e7b1bdaaa275c1a006917d
        {
            "meta": {
                "code": 200
            },
            "response": {
                "identities": [
                    {
                        "avatar": {
                            "320_320": "http://a0.twimg.com/profile_images/3686752338/96c8c19a08e2bee5c912f80f6f59b7d3_reasonably_small.jpeg",
                            "80_80": "http://a0.twimg.com/profile_images/3686752338/96c8c19a08e2bee5c912f80f6f59b7d3_reasonably_small.jpeg",
                            "original": "http://a0.twimg.com/profile_images/3686752338/96c8c19a08e2bee5c912f80f6f59b7d3_reasonably_small.jpeg"
                        },
                        "avatar_filename": "http://a0.twimg.com/profile_images/3686752338/96c8c19a08e2bee5c912f80f6f59b7d3_reasonably_small.jpeg",
                        "bio": "break the wall or bring the war",
                        "connected_user_id": 644,
                        "created_at": "2013-04-25 15:23:44 +0000",
                        "external_id": "10065202",
                        "external_username": "Leaskh",
                        "free": true,
                        "id": 668,
                        "locale": "",
                        "name": "Leask Huang",
                        "nickname": "",
                        "order": 999,
                        "provider": "twitter",
                        "timezone": "Asia/Shanghai",
                        "type": "identity",
                        "unreachable": false,
                        "updated_at": "2013-07-10 05:35:21 +0000"
                    },
                    {
                        "avatar": {
                            "320_320": "https://graph.facebook.com/554148635/picture?width=320&height=320",
                            "80_80": "https://graph.facebook.com/554148635/picture?width=80&height=80",
                            "original": "https://graph.facebook.com/554148635/picture?width=2048&height=2048"
                        },
                        "avatar_filename": "https://graph.facebook.com/554148635/picture?width=80&height=80",
                        "bio": "http://www.facebook.com/Leaskh",
                        "connected_user_id": 632,
                        "created_at": "2013-04-02 14:17:52 +0000",
                        "external_id": "554148635",
                        "external_username": "Leaskh",
                        "free": true,
                        "id": 638,
                        "locale": "",
                        "name": "Leask Huang",
                        "nickname": "",
                        "order": 999,
                        "provider": "facebook",
                        "timezone": "Asia/Shanghai",
                        "type": "identity",
                        "unreachable": false,
                        "updated_at": "2013-07-11 18:58:23 +0000"
                    }
                ]
            }
        }


## Mark A Free Identity As My Identity // Works only with Wechat identities currently
* endpoint: /v2/crosses/[int:cross_id]/freeidentities/[int:identity_id]/itsme
* QUERY args:
    - token: [str:cross_access_token] // ONLY ACCEPT Smith's cross token
* returns:
    - 200: [str:cross_access_token]
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized
    - 403: forbidden
    - 404: not_found
    - 500: server_error
* example:

        #!bash
        $ http api.leask.0d0f.com/v2/crosses/100640/freeidentities/638/itsme?token=d8bfe4936feaeaca678cd1d7c140f1c77d28de3e60e7b1bdaaa275c1a006917d
        {
            "meta": {
                "code": 200
            },
            "response": {
                "cross_access_token": "0a9ae2a5a94320ad5da772ba8a1b62e6745fe157545ef59433adf256a98a3e1d"
            }
        }
