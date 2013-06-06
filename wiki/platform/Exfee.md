# Exfee
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
            "name"        : [str:name]
            "invitations" : [array:invitation_object],
            "total"       : [int],
            "accepted"    : [int],
            "type"        : "exfee"
        }
