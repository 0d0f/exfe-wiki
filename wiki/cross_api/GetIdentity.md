## Get

<pre>
POST:
identities : [
    {
        provider : string,
        external_id : string || external_username : string
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
leask@Flora:~/Downloads> http -f post api.local.exfe.com/v2/identities/get identities="[{\"provider\":\"twitter\",\"external_username\":\"@leaskh\"},{\"provider\":\"email\",\"external_username\":\"i@leaskh.com\"},{\"provider\":\"email\",\"external_username\":\"x@leaskh.com\"}]"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.3
Set-Cookie: PHPSESSID=ntgp3njad0bup9r0hcmcl30707; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Mon, 25 Jun 2012 09:05:37 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    },
    "response": {
        "identities": [
            {
                "avatar_filename": "http://a0.twimg.com/profile_images/1417120703/leask_s_reasonably_small.png",
                "bio": "break the wall or bring the war",
                "connected_user_id": 0,
                "created_at": "",
                "external_id": 10065202,
                "external_username": "Leaskh",
                "id": 0,
                "name": "Leask Huang",
                "nickname": "",
                "provider": "twitter",
                "type": "identity",
                "updated_at": ""
            },
            {
                "avatar_filename": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png",
                "bio": "",
                "connected_user_id": 207,
                "created_at": "2012-05-17 15:56:42",
                "external_id": "i@leaskh.com",
                "external_username": "i@leaskh.com",
                "id": 324,
                "name": "Leask",
                "nickname": "",
                "provider": "email",
                "type": "identity",
                "updated_at": null
            },
            {
                "avatar_filename": "http://www.gravatar.com/avatar/6148111086570ea4b6a2e73509c7504d?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fdefault%3Fname%3Dx%40leaskh.com",
                "bio": "",
                "connected_user_id": 0,
                "created_at": "",
                "external_id": "x@leaskh.com",
                "external_username": "x@leaskh.com",
                "id": 0,
                "name": "x",
                "nickname": "",
                "provider": "email",
                "type": "identity",
                "updated_at": ""
            }
        ]
    }
}
</pre>
