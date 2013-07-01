## Complete

        #!text

        endpoint: identities/complete
        method: get
        args: token, key

        example:
        leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get api.local.exfe.com/v2/identities/complete?token=sadfsadfsdafsdf\&key=a
        HTTP/1.1 200 OK
        X-Powered-By: PHP/5.4.3
        Set-Cookie: PHPSESSID=2i4m5q97s0csv5g67f6p4lvc72; path=/; domain=.exfe.com
        Expires: Thu, 19 Nov 1981 08:52:00 GMT
        Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
        Pragma: no-cache
        Content-Type: application/json; charset=UTF-8
        Transfer-Encoding: chunked
        Date: Fri, 22 Jun 2012 04:23:16 GMT
        Server: lighttpd/1.4.30

        #!javascript

        {
            "meta": {
                "code": 200
            },
            "response": {
                "identities": [{
                    "name": "sadfasd",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": -894,
                    "external_id": "sadfasd@lelaskh.com",
                    "external_username": "sadfasd@lelaskh.com",
                    "avatar_filename": "http:\/\/api.leask.0d0f.com\/v2\/avatar\/default?name=sadfasd",
                    "created_at": "2013-06-28 10:45:52 +0000",
                    "updated_at": "2013-06-28 10:45:52 +0000",
                    "order": 999,
                    "unreachable": false,
                    "id": 894,
                    "type": "identity"
                }, {
                    "name": "sadfasdf",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": -897,
                    "external_id": "sadfasdf@asdfasdf.com",
                    "external_username": "sadfasdf@asdfasdf.com",
                    "avatar_filename": "http:\/\/api.leask.0d0f.com\/v2\/avatar\/default?name=sadfasdf",
                    "created_at": "2013-06-28 11:17:51 +0000",
                    "updated_at": "2013-06-28 11:17:51 +0000",
                    "order": 999,
                    "unreachable": false,
                    "id": 897,
                    "type": "identity"
                }, {
                    "name": "feedly safari",
                    "nickname": "",
                    "bio": "",
                    "provider": "twitter",
                    "connected_user_id": 0,
                    "external_id": "80073205",
                    "external_username": "feedly_safari",
                    "avatar_filename": "http:\/\/a0.twimg.com\/profile_images\/454303978\/images_normal.jpg",
                    "created_at": "0000-00-00 00:00:00 +0000",
                    "updated_at": "0000-00-00 00:00:00 +0000",
                    "order": 0,
                    "unreachable": false,
                    "id": 0,
                    "type": "identity"
                }, {
                    "name": "safds",
                    "nickname": "",
                    "bio": "",
                    "provider": "email",
                    "connected_user_id": -893,
                    "external_id": "safds@leaskh.com",
                    "external_username": "safds@leaskh.com",
                    "avatar_filename": "http:\/\/api.leask.0d0f.com\/v2\/avatar\/default?name=safds",
                    "created_at": "2013-06-28 10:45:10 +0000",
                    "updated_at": "2013-06-28 10:45:10 +0000",
                    "order": 999,
                    "unreachable": false,
                    "id": 893,
                    "type": "identity"
                }, {
                    "name": "Salad",
                    "nickname": "",
                    "bio": "",
                    "provider": "twitter",
                    "connected_user_id": 0,
                    "external_id": "100672653",
                    "external_username": "salad_33",
                    "avatar_filename": "http:\/\/a0.twimg.com\/profile_images\/3569540525\/b602f31a8694f5a06572df3ff623a679_normal.jpeg",
                    "created_at": "0000-00-00 00:00:00 +0000",
                    "updated_at": "0000-00-00 00:00:00 +0000",
                    "order": 0,
                    "unreachable": false,
                    "id": 0,
                    "type": "identity"
                }]
            }
        }
