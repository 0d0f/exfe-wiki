# Exfees
    author: Leask Huang
    created date: 2013-06-06
    updated date: 2013-06-06


## Invitation Schema

        #!javascript
        {
            "id"         : [int:invitation_id],
            "identity"   : [obj:identity],
            "invited_by" : [obj:identity],
            "updated_by" : [obj:identity],
            "response"   : [str:NORESPONSE/ACCEPTED/INTERESTED/DECLINED],
            "via"        : [str],
            "created_at" : [str:time],
            "updated_at" : [str:time],
            "token"      : [str:length=32],
            "host"       : [bol],
            "mates"      : [int:0-9],
            "type"       : "invitation",
            "notification_identities" : [array:identity_ids]
        }


## Exfee Schema

        #!javascript
        {
            "id"          : [int:exfee_id],
            "name"        : [str:name],
            "invitations" : [array:invitation_object],
            "total"       : [int],
            "accepted"    : [int],
            "created_at"  : [str:time],
            "updated_at"  : [str:time],
            "type"        : "exfee"
        }


## Demo

         #!javascript
        {
            "id"          : 233,
            "name"        : "Star Trek Into Darkness",
            "invitations" : [
                {
                    "id"         : 100,
                    "identity"   : [obj:identity],
                    "invited_by" : [obj:identity],
                    "updated_by" : [obj:identity],
                    "response"   : "ACCEPTED",
                    "via"        : "EXFE",
                    "created_at" : "2013-06-04 10:45:18 +0800",
                    "updated_at" : "2013-06-04 10:45:18 +0800",
                    "token"      : "13f8b04f92590f29cd715ce9a78e40bf",
                    "host"       : true,
                    "mates"      : 0,
                    "type"       : "invitation",
                    "notification_identities" : [
                        "233@leaskh.com@email",
                        "233meow@twitter"
                    ]
                },
                {
                    "id"         : 101,
                    "identity"   : [obj:identity],
                    "invited_by" : [obj:identity],
                    "updated_by" : [obj:identity],
                    "response"   : "DECLINED",
                    "via"        : "EXFE",
                    "created_at" : "2013-06-04 10:45:18 +0800",
                    "updated_at" : "2013-06-04 10:45:18 +0800",
                    "token"      : "13f8b04f92590f29cd715ce9a78e40bf",
                    "host"       : false,
                    "mates"      : 1,
                    "type"       : "invitation",
                    "notification_identities" : [
                        "googollee@twitter"
                    ]
                }
            ],
            "total"       : 3,
            "accepted"    : 1,
            "type"        : "exfee"
        }


## Remove Notification Identity
* endpoint: /v2/exfee/[int:exfee_id]/removenotificationidentity
* QUERY args:
    - token: [str:user_token]
* POST args:
    - identity_id: [str:external_username@provider]
* returns:
    - 200: {"exfee" : [object:exfee]}
    - 400: no_exfee_id
    - 403: not_authorized
    - 401: invalid_auth
    - 403: not_authorized
    - 400: no_identity_id
    - 400: error_identity_id
    - 500: server_error

<!--
## working on!!!!!!!!!!!!!!!!!!!!!!!
## Invite User To Exfee
* endpoint: /v2/exfee/[int:exfee_id]/invite
* QUERY args:
    - xcode: [str:xcode]
    - user_id: [int:user_id]
    -
 http -f post api.leask.0d0f.com xcode=77c4c4af701181364749dc9d015fd7a7 user_id=476 via=leaskh@gmail.com@email
 -->
