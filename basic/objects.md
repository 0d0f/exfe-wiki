# Objects

    author: Leask Huang
    created date: 2013-07-12
    updated date: 2013-07-12


## User

        #!javascript
        {
            "avatar"         : {
                "320_320" : [str:url],
                "80_80"   : [str:url],
                "original": [str:url]
            },
            "avatar_filename": [str:url], // @warning: will be removed in v3
            "bio"            : [str:url],
            "cross_quantity" : [int],
            "id"             : [int:user_id],
            "devices"        : [array:device_object],
            "identities"     : [array:identity_object],
            "locale"         : [str:locale],
            "name"           : [str],
            "password"       : [bol],
            "timezone"       : [str:timezone],
            "created_at"     : [str:date],
            "updated_at"     : [str:date],
            "type"           : "user",
            "webcal"         : [str:webcal_url]
        }


## Identity

        #!javascript
        {
            "avatar"           : {
                "320_320" : [str:url],
                "80_80"   : [str:url],
                "original": [str:url]
            },
            "avatar_filename"  : [str:url], // @warning: will be removed in v3
            "bio"              : [str:url],
            "connected_user_id": [int],
            "external_id"      : [str],
            "external_username": [str],
            "id"               : [int:identity_id],
            "name"             : [str],
            "nickname"         : [str],
            "order"            : [int],
            "provider"         : [str:provider],
            "status"           : [str:RELATED|VERIFYING|CONNECTED|REVOKED],
            "type"             : "identity",
            "unreachable"      : [bol],
            "created_at"       : [str:date],
            "updated_at"       : [str:date]
        },


## Device

        #!javascript
        {
            "brand"             : [str],
            "description"       : [str],
            "disconnected_at"   : [str:date],
            "first_connected_at": [str:date],
            "id"                : [int:device_id],
            "last_connected_at" : [str:date],
            "model"             : [str],
            "name"              : [str],
            "os_name"           : [str],
            "os_version"        : [str],
            "status"            : [str: CONNECTED | DISCONNECTED],
            "type"              : "device"
        }


## Cross

        #!javascript
        {
            "by_identity"       : [object_identity],
            "conversation_count": [int],
            "created_at"        : [str:date],
            "description"       : [str],
            "exfee"             : [object:exfee],
            "id"                : [int:cross_id],
            "place"             : [object:place],
            "relative"          : [array],
            "time"              : [object:cross_time],
            "title"             : [str],
            "touched_at"        : [str:date],
            "type"              : "Cross",
            "updated"           : [array:update_infos],
            "updated_at"        : [str:date],
            "widget"            : [array:widget_object],
            "attribute"         : {
               "closed": [bol],
               "state" : [str:published | draft]
            }
        }


## Routex Widget

        #!javascript
        {
            "my_status" : true | false | null,
            "type" : "routex",
        }
