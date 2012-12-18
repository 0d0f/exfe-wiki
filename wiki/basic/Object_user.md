h1. Object user

id
name
bio
default_identity
avatar_filename
timezone


<pre>
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb$ curl http://api.local.exfe.com/v2/identities/[id]?token=xxxxxxx
Try to get an identity object:
Identity Object
(
    [name] => Leask Huang
    [nickname] =>
    [bio] =>
    [provider] => email
    [connected_user_id] => 0
    [external_id] => i@leaskh.com
    [external_username] => i@leaskh.com
    [avatar_filename] =>
    [created_at] => 2011-11-10 05:16:23
    [updated_at] => 2011-11-10 05:16:23
    [id] => 1
    [type] => identity
)


Try to get a user object:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get api.local.exfe.com/v2/users/143?token=xxxxxxx
HTTP/1.1 200 OK
X-Powered-By: PHP/5.3.13
Set-Cookie: PHPSESSID=72gjeqe6fe6h8ou0slmejtot80; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Fri, 25 May 2012 10:42:37 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    },
    "response": {
        "user": {
            "avatar_filename": "https://twimg0-a.akamaihd.net/profile_images/1204136991/johnny-galecki-as-leonard-hofstadter.jpg",
            "avatar_updated_at": null,
            "bio": "I am a physicist at CalTech and live with my best friend Sheldon.",
            "cross_quantity": 11,
            "default_identity": {
                "avatar_filename": "http://img.local.exfe.com/8/6f/86f61dd57ca0c0a177c6b10ee9d62ff8.png",
                "bio": "I am a physicist at CalTech and live with my best friend Sheldon.",
                "connected_user_id": 143,
                "created_at": "2012-05-08 18:37:59",
                "external_id": "tester_leonard@0d0f.com",
                "external_username": "tester_leonard@0d0f.com",
                "id": 233,
                "name": "Leonard Hofstadter",
                "nickname": "",
                "provider": "email",
                "status": "CONNECTED",
                "type": "identity",
                "updated_at": ""
            },
            "created_at": "2011-11-10 05:16:23",
            "updated_at": "2011-11-10 05:16:23",
            "id": 143,
            "identities": [
                {
                    "avatar_filename": "http://img.local.exfe.com/8/6f/86f61dd57ca0c0a177c6b10ee9d62ff8.png",
                    "bio": "I am a physicist at CalTech and live with my best friend Sheldon.",
                    "connected_user_id": 143,
                    "created_at": "2012-05-08 18:37:59",
                    "external_id": "tester_leonard@0d0f.com",
                    "external_username": "tester_leonard@0d0f.com",
                    "id": 233,
                    "name": "Leonard Hofstadter",
                    "nickname": "",
                    "provider": "email",
                    "status": "CONNECTED",
                    "type": "identity",
                    "updated_at": ""
                },
                {
                    "avatar_filename": "http://img.local.exfe.com/3/d2/3d2db166ec8d3b6ff550426ec8c38df5.png",
                    "bio": "I am a physicist at CalTech and live with my best friend Sheldon.",
                    "connected_user_id": 143,
                    "created_at": "2012-05-08 18:37:59",
                    "external_id": "575129929",
                    "external_username": "0d0f_tester_leo",
                    "id": 236,
                    "name": "Leonard Hofstadter",
                    "nickname": "",
                    "provider": "twitter",
                    "status": "CONNECTED",
                    "type": "identity",
                    "updated_at": ""
                },
                {
                    "avatar_filename": "http://www.gravatar.com/avatar/97b9df41c992c3b5253689f8dd250d0f?d=http%3A%2F%2Fimg.local.exfe.com%2F0%2Ffa%2F0fa3ca091d9c79fc3e340a269f9593d2.png",
                    "bio": "",
                    "connected_user_id": 143,
                    "created_at": "2012-05-24 16:55:56",
                    "external_id": "asdfsda@dsfadf.com",
                    "external_username": "asdfsda@dsfadf.com",
                    "id": 341,
                    "name": "lllll",
                    "nickname": "",
                    "provider": "email",
                    "status": "VERIFYING",
                    "type": "identity",
                    "updated_at": ""
                }
            ],
            "name": "Leonard Hofstadter",
            "password": true,
            "timezone": "+08:00",
            "type": "user"
        }
    }
}

</pre>
