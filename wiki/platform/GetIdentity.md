## Get

<pre>
endpoint: /v2/identities/get
POST:
identities : [
    {
        id : integer
    },
    {
        provider : string,
        external_id : string
    },
    {
        provider : string,
        external_username : string
    }
]

return:
{
    meta : 200,
    response :
    {
        identities : [
            {
                name : string
                nickname : string
                bio : string
                provider : string
                connected_user_id : int
                external_id : string
                external_username : string
                avatar_filename : string
                created_at : string
                updated_at : string
                id : int
                type : 'identity'
            }
        ]
    }
}

example:
leask@Flora:~/Downloads> http -f post api.local.exfe.com/v2/Identities/Get identities='[{"id":568},{"external_id":"i@leaskh.com","provider":"email"},{"external_username":"leaskh","provider":"twitter"}]'
HTTP/1.1 200 OK

{
    "meta": {
        "code": 200
    },
    "response": {
        "identities": [
            {
                "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=asdf",
                "bio": "",
                "connected_user_id": -568,
                "created_at": "2012-11-26 09:58:36 +0000",
                "external_id": "asdf@leaskh.com",
                "external_username": "asdf@leaskh.com",
                "id": 568,
                "name": "asdf",
                "nickname": "",
                "order": 0,
                "provider": "email",
                "type": "identity",
                "unreachable": false,
                "updated_at": "2012-11-26 09:58:36 +0000"
            },
            {
                "avatar_filename": "http://www.gravatar.com/avatar/5b53fb71b6f36f46fe9cb14eb5acd56f",
                "bio": "",
                "connected_user_id": 319,
                "created_at": "2012-05-17 15:56:42 +0000",
                "external_id": "i@leaskh.com",
                "external_username": "i@leaskh.com",
                "id": 324,
                "name": "Leask",
                "nickname": "",
                "order": 0,
                "provider": "email",
                "type": "identity",
                "unreachable": true,
                "updated_at": "2012-11-14 11:37:01 +0000"
            },
            {
                "avatar_filename": "http://a0.twimg.com/profile_images/1417120703/leask_s_reasonably_small.png",
                "bio": "break the wall or bring the war",
                "connected_user_id": -356,
                "created_at": "2012-06-26 11:06:52 +0000",
                "external_id": "10065202",
                "external_username": "Leaskh",
                "id": 356,
                "name": "Leask Huang",
                "nickname": "",
                "order": 0,
                "provider": "twitter",
                "type": "identity",
                "unreachable": false,
                "updated_at": "2012-06-26 11:07:17 +0000"
            }
        ]
    }
}
</pre>
