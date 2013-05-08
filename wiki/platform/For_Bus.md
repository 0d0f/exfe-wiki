# For Bus
    author: Leask Huang
    created date: 2013-02-26
    updated date: 2013-05-05


## Response:
* 200: 正常
* 4xx: 必须反馈给用户的错误
* 5xx: 无须反馈给用户的错误


## Identity Update
* endpoint: /v2/Gobus/UpdateIdentity
* POST args:
    - id: [int]
    - provider: [string]
    - external_id: [string]
    - name: [string]
    - nickname: [string]
    - bio: [string]
    - avatar_filename: [string]
    - external_username: [string]


## Notification Callback:
* endpoint: /v2/Gobus/NotificationCallback
* POST args:
    - BODY:

            #!javascript
            {
                "recipient" : [object:recipient],
                "error"     : [string:reason]
            }


## Revoke Identity:
* endpoint: /v2/Gobus/RevokeIdentity
* POST args:
    - BODY: [json:identity]


## Get Cross By Id
* endpoint: /v2/Gobus/Crosses
* GET args:
    - id: [int]
    - user_id: [int]
    - updated_at: [str:time]
* returns:
    - 200: [json:cross]
    - 304: '' // Not Modified
    - 403: '' // Forbidden
    - 404: '' // Not Found


## Gather
* endpoint: /v2/Gobus/Gather
* POST args:
    - BODY: [json:cross]


## X Update
* endpoint: /v2/Gobus/XUpdate
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


## Post Conversation:
* endpoint: /v2/Gobus/PostConversation
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
