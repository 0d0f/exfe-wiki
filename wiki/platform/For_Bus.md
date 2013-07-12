# For Bus
    author: Leask Huang
    created date: 2013-02-26
    updated date: 2013-05-30


## Response:
* 200: 正常
* 3xx: 其他状态
* 4xx: 必须反馈给用户的错误
* 5xx: 无须反馈给用户的错误


## Identity Update
* endpoint: /v3/bus/updateidentity
* POST args:
    - id: [int]
    - provider: [string]
    - external_id: [string]
    - name: [string]
    - nickname: [string]
    - bio: [string]
    - avatar_filename: [string]
    - external_username: [string]
* return:
    - 200:
        * data
            * identity_id: [int:identity_id]
    - 500: identity_error
    - 500: internal_server_error


## Add Friends
* endpoint: /v3/bus/addfriends
* POST args:

        #!javascript
        {
            "user_id" : [int:user_id]
            "identities" : [array:identity_object]

        }

* returns:
    - 200:
        * data
            * user_id: [int:user_id]
    - 500: no_input
    - 500: json_error
    - 500: internal_server_error


## Notification Callback
* endpoint: /v3/bus/notificationcallback
* POST args:
    - BODY:

            #!javascript
            {
                "recipient" : [object:recipient],
                "error" : [string:reason]
            }

* returns:
    - 200:
        * data: [object:recipient]
    - 500: no_input
    - 500: json_error
    - 500: identity_not_found
    - 500: unknow_provide


## Publish X
* endpoint: /v3/bus/publishx
* POST args:
    - BODY:

            #!javascript
            {
                cross_id: [int:cross_id],
                exfee_id: [int:exfee_id],
                user_id: [int:user_id],
                identity_id: [identity_id]
            }

* returns:
    - 200:
        * data
            * cross_id: [int:cross_id]
    - 500: input_error
    - 500: internal_server_error


## Revoke Identity
* endpoint: /v3/bus/revokeidentity
* POST args:
    - BODY: [json:identity]
* returns:
    - 200:
        * data: [object:identity]
    - 404: identity_not_found
    - 500: no_input


## Get Cross By Id
* endpoint: /v3/bus/Crosses/[int:cross_id]
* GET args:
    - user_id: [int]
    - updated_at: [str:time]
* returns:
    - 200:
        * data: [object:cross]
    - 304: not_modified
    - 403: forbidden
    - 404: cross_not_found


## Get Exfee By Id
* endpoint: /v3/bus/Exfees/[int:exfee_id]
* GET args:
    - user_id: [int]
* returns:
    - 200:
        * data: [object:exfee]
    - 403: forbidden
    - 404: exfee_not_found


## Gather
* endpoint: /v3/bus/gather
* POST args:
    - BODY: [json:cross]
* returns:
    - 200:
        * data: [object:cross]
    - 206:
        * data
            * cross_id: [int:cross_id]
        * warning: [object:{code, type, message}]
    - 400: cross_error, with details
    - 500: identity_error
    - 500: user_error
    - 500: gathering_error


## X Update
* endpoint: /v3/bus/xupdate
* POST args OPTION A:
    - BODY:

            #!javascript
            {
                cross_id: [int],
                cross: [object:cross],
                by_identity: [object:identity]
            }

* POST args OPTION B:
    - BODY:

            #!javascript
            {
                exfee_id: [int],
                cross: [object:cross],
                by_identity: [object:identity]
            }

* returns
    - 200:
        * data
            * cross_id: [int:cross_id]
            * exfee_id: [int:exfee_id]
            * cross: [object:cross]
    - 206:
        * data
            * cross_id: [int:cross_id]
            * exfee_id: [int:exfee_id]
            * cross: [object:cross]
        * warning: [object:{code, type, message}]
    - 400: not_authorized
    - 404: cross_not_found
    - 500: cross_error
    - 500: cross_error, with details
    - 500: identity_error
    - 500: user_error
    - 500: internal_server_error


## Get Conversation By Exfee Id
* endpoint: /v3/bus/conversation/[int:exfee_id]
* QUERY args:
    - updated_at: [str:time]
    - direction: [str:newer(default)/older]
    - quantity: [int]
    - clear: [str:true(default)/false]
* returns:
    - 200:
        * data: [array:conversation_object]
    - 500: no_exfee_id
    - 500: internal_server_error


## Post Conversation
* endpoint: /v3/bus/postconversation
* POST args OPTION A:
    - external_id: [string]
    - provider: [string]
    - cross_id: [int]
    - content: [string]
    - time: [string:time]
* POST args OPTION B:
    - external_id: [string]
    - provider: [string]
    - exfee_id: [int]
    - content: [string]
    - time: [string:time]
* POST args OPTION C:
    - external_id: [string]
    - provider: [string]
    - iom: [string]
    - content: [int]
    - time: [string:time]
* returns:
    - 200:
        * data: [object:post]
    - 500: input_error
    - 500: identity_error
    - 500: user_error
    - 500: cross_error
    - 500: internal_server_error


## Get all recipients by identity_id
* endpoint: /v3/bus/recipients
* QUERY args:
    - identity_id: [str:identity_id]
* returns:
    - 200:
        * data: [array:recipient_object]
    - 400: error_identity_id
    - 404: recipient_not_found
* example:

        #!bash
        http api.panda.0d0f.com/v3/bus/recipients?identity_id=i@leaskh.com@email
        {
            "data": [
                {
                    "auth_data": "",
                    "external_id": "i@leaskh.com",
                    "external_username": "i@leaskh.com",
                    "id": 0,
                    "identity_id": 569,
                    "language": "en_us",
                    "name": "Leask Huang",
                    "provider": "email",
                    "timezone": "+08:00",
                    "token": "",
                    "type": "Recipient",
                    "user_id": 587
                },
                {
                    "auth_data": "",
                    "external_id": "xxx@leaskh.com",
                    "external_username": "xxx@leaskh.com",
                    "id": 0,
                    "identity_id": 828,
                    "language": "en_us",
                    "name": "xxx",
                    "provider": "email",
                    "timezone": "+08:00",
                    "token": "",
                    "type": "Recipient",
                    "user_id": 587
                },
                {
                    "auth_data": "",
                    "external_id": "988b537e3dce8e4d2d1471ca9931cc742f92ce1a54c9891a361cb4019101971a",
                    "external_username": "988b537e3dce8e4d2d1471ca9931cc742f92ce1a54c9891a361cb4019101971a",
                    "id": 0,
                    "identity_id": -130,
                    "language": "en_us",
                    "name": "Leask Huang",
                    "provider": "iOS",
                    "timezone": "+08:00",
                    "token": "",
                    "type": "Recipient",
                    "user_id": 587
                }
            ]
        }
