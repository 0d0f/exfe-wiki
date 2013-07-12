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
            "locale"           : [str:locale],
            "name"             : [str],
            "nickname"         : [str],
            "order"            : [int],
            "provider"         : [str:provider],
            "status"           : [str:RELATED|VERIFYING|CONNECTED|REVOKED],
            "timezone"         : [str:timezone],
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
            "status"            : "CONNECTED",
            "type"              : "device"
        }
