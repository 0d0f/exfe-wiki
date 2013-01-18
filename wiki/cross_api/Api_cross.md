## Api cross

usage A:
endpoint: http://API_ROOT/v2/crosses/CROSS_ID
CROSS_ID : cross 的数字ID

例: http://api.local.exfe.com/v2/crosses/100100

response:

<pre>
{
    "id_base62": "1e",
    "title": "post by curl",
    "description": "desc...",
    "time": {
        "begin_at": {
            "date_word": "",
            "date": "2012-03-22",
            "time_word": "",
            "time": "08:00:00",
            "timezone": "+08:00",
            "id": 0,
            "type": "EFTime"
        },
        "origin": "03-22-2012 04:00 PM",
        "outputformat": "",
        "id": 0,
        "type": "CrossTime"
    },
    "place": {
        "title": "place title",
        "description": "",
        "lng": "113.268",
        "lat": "23.1318",
        "provider": "",
        "external_id": "",
        "created_at": null,
        "updated_at": 1335256748,
        "id": "55",
        "type": "Place"
    },
    "attribute": {
        "state": "published"
    },
    "exfee": {
        "invitations": [
            {
                "identity": {
                    "name": "virushuo",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 29,
                    "external_id": "virushuo@gmail.com",
                    "external_username": "virushuo@gmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-03-27 06:08:09",
                    "updated_at": null,
                    "id": 74,
                    "type": "identity"
                },
                "by_identity": {
                    "name": "virushuo",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 29,
                    "external_id": "virushuo@gmail.com",
                    "external_username": "virushuo@gmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-03-27 06:08:09",
                    "updated_at": null,
                    "id": 74,
                    "type": "identity"
                },
                "rsvp_status": "ACCEPTED",
                "via": "",
                "created_at": "2012-04-24 08:28:55",
                "updated_at": "2012-04-24 08:28:55",
                "exfee_updated_at": "",
                "token": "",
                "id": 204,
                "type": "invitation"
            },
            {
                "identity": {
                    "name": "Stony Wang",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 39,
                    "external_id": "stonyw@gmail.com",
                    "external_username": "stonyw@gmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/5dd675e149a1210d0097e646cd30c995?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-04-24 07:46:33",
                    "updated_at": null,
                    "id": 84,
                    "type": "identity"
                },
                "by_identity": {
                    "name": "virushuo",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 29,
                    "external_id": "virushuo@gmail.com",
                    "external_username": "virushuo@gmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-03-27 06:08:09",
                    "updated_at": null,
                    "id": 74,
                    "type": "identity"
                },
                "rsvp_status": "ACCEPTED",
                "via": "",
                "created_at": "2012-04-24 08:28:55",
                "updated_at": "2012-04-24 08:28:55",
                "exfee_updated_at": "",
                "token": "",
                "id": 205,
                "type": "invitation"
            },
            {
                "identity": {
                    "name": "googollee",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 38,
                    "external_id": "googollee@hotmail.com",
                    "external_username": "googollee@hotmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/fc1d342bf78fffe115d867168598c9a5?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-04-24 05:31:27",
                    "updated_at": null,
                    "id": 83,
                    "type": "identity"
                },
                "by_identity": {
                    "name": "virushuo",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 29,
                    "external_id": "virushuo@gmail.com",
                    "external_username": "virushuo@gmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-03-27 06:08:09",
                    "updated_at": null,
                    "id": 74,
                    "type": "identity"
                },
                "rsvp_status": "ACCEPTED",
                "via": "",
                "created_at": "2012-04-24 08:28:55",
                "updated_at": "2012-04-24 08:28:55",
                "exfee_updated_at": "",
                "token": "",
                "id": 206,
                "type": "invitation"
            },
            {
                "identity": {
                    "name": "Leask Huang",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 25,
                    "external_id": "i@leaskh.com",
                    "external_username": "i@leaskh.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/5b53fb71b6f36f46fe9cb14eb5acd56f?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-03-21 04:42:38",
                    "updated_at": null,
                    "id": 66,
                    "type": "identity"
                },
                "by_identity": {
                    "name": "virushuo",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": 29,
                    "external_id": "virushuo@gmail.com",
                    "external_username": "virushuo@gmail.com",
                    "avatar_filename": "http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
                    "avatar_updated_at": "0000-00-00 00:00:00",
                    "created_at": "2012-03-27 06:08:09",
                    "updated_at": null,
                    "id": 74,
                    "type": "identity"
                },
                "rsvp_status": "NORESPONSE",
                "via": "",
                "created_at": "2012-04-24 08:28:55",
                "updated_at": "2012-04-24 08:28:55",
                "exfee_updated_at": "",
                "token": "",
                "id": 207,
                "type": "invitation"
            }
        ],
        "id": 110008,
        "type": "exfee"
    },
    "widget": [
        {
            "image": "IMG_0111",
            "widget_id": 0,
            "id": 0,
            "type": "Background"
        }
    ],
    "relative": {
        "id": 0,
        "relation": ""
    },
    "type": "Cross",
    "created_at": null,
    "by_identity": {
        "name": "virushuo",
        "nickname": "",
        "bio": "",
        "provider": "email",
        "connected_user_id": 29,
        "external_id": "virushuo@gmail.com",
        "external_username": "virushuo@gmail.com",
        "avatar_filename": "http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=http%3A%2F%2Fimg.dev.0d0f.com%2Fweb%2F80_80_default.png",
        "avatar_updated_at": "0000-00-00 00:00:00",
        "created_at": "2012-03-27 06:08:09",
        "updated_at": null,
        "id": 74,
        "type": "identity"
    },
    "id": 76,
    "deleted": false,
    "closed": false
}
</pre>


usage B:
endpoint: http://API_ROOT/v2/crosses/CROSS_BASE62_ID
CROSS_BASE62_ID : cross 的base62 id
by_cross62_id=true;

example:
http get api.local.exfe.com/v2/crosses/q3j?token=sadfsadfsdafsdf\&by_base62_id=1
