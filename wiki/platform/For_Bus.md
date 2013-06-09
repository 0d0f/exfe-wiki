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
        * data
            * cross_id: [int:cross_id]
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
