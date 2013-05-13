# Conversation


## Get Conversations by Exfee_id
* description: 获得某个 Exfee 下的会话记录
* endpoint: /v2/conversation/[int:exfee_id]
* GET args:
    - updated_at: [str:time]
    - clear: [bol] // 是否清空阅读状态，默认为 true
    - direction: [str:older|newer] // 读取方向，更新的会话，还是更旧的会话
    - quantity: [int] // 读取条目数;
* returns:
    - conversation: [json:conversations_array]
* error:
    401: invalid_auth
    403: not_authorized
* demo:

        #!bash
        http 'http://api.leask.0d0f.com/v2/Conversation/110322?token=50c5e5b47ef77b8d8daa2d7fda2f8b56301313b29f011a251f767fbdcaf60247'

        {
            "meta": {
                "code": 200
            },
            "response": {
                "conversation": [
                    {
                        "by_identity": {
                            "avatar_filename": "http://a0.twimg.com/profile_images/1417120703/leask_s_reasonably_small.png",
                            "bio": "break the wall or bring the war",
                            "connected_user_id": 379,
                            "created_at": "2013-04-25 15:23:44 +0000",
                            "external_id": "10065202",
                            "external_username": "leaskh",
                            "id": 668,
                            "name": "Leask Huang",
                            "nickname": "",
                            "order": 4,
                            "provider": "twitter",
                            "type": "identity",
                            "unreachable": false,
                            "updated_at": "2013-04-25 15:23:44 +0000"
                        },
                        "content": "测试1",
                        "created_at": "2013-05-13 08:32:29 +0000",
                        "id": 2393,
                        "postable_id": 110322,
                        "postable_type": "exfee",
                        "relative": [],
                        "type": "Post",
                        "updated_at": "2013-05-13 08:32:29 +0000",
                        "via": ""
                    },
                    {
                        "by_identity": {
                            "avatar_filename": "http://a0.twimg.com/profile_images/1417120703/leask_s_reasonably_small.png",
                            "bio": "break the wall or bring the war",
                            "connected_user_id": 379,
                            "created_at": "2013-04-25 15:23:44 +0000",
                            "external_id": "10065202",
                            "external_username": "leaskh",
                            "id": 668,
                            "name": "Leask Huang",
                            "nickname": "",
                            "order": 4,
                            "provider": "twitter",
                            "type": "identity",
                            "unreachable": false,
                            "updated_at": "2013-04-25 15:23:44 +0000"
                        },
                        "content": "测试",
                        "created_at": "2013-05-13 08:32:27 +0000",
                        "id": 2392,
                        "postable_id": 110322,
                        "postable_type": "exfee",
                        "relative": [],
                        "type": "Post",
                        "updated_at": "2013-05-13 08:32:27 +0000",
                        "via": ""
                    },
                    {
                        "by_identity": {
                            "avatar_filename": "http://a0.twimg.com/profile_images/1417120703/leask_s_reasonably_small.png",
                            "bio": "break the wall or bring the war",
                            "connected_user_id": 379,
                            "created_at": "2013-04-25 15:23:44 +0000",
                            "external_id": "10065202",
                            "external_username": "leaskh",
                            "id": 668,
                            "name": "Leask Huang",
                            "nickname": "",
                            "order": 4,
                            "provider": "twitter",
                            "type": "identity",
                            "unreachable": false,
                            "updated_at": "2013-04-25 15:23:44 +0000"
                        },
                        "content": "sadfasdf",
                        "created_at": "2013-05-08 23:03:51 +0000",
                        "id": 2355,
                        "postable_id": 110322,
                        "postable_type": "exfee",
                        "relative": [],
                        "type": "Post",
                        "updated_at": "2013-05-08 23:03:51 +0000",
                        "via": ""
                    },
                    {
                        "by_identity": {
                            "avatar_filename": "http://a0.twimg.com/profile_images/1417120703/leask_s_reasonably_small.png",
                            "bio": "break the wall or bring the war",
                            "connected_user_id": 379,
                            "created_at": "2013-04-25 15:23:44 +0000",
                            "external_id": "10065202",
                            "external_username": "leaskh",
                            "id": 668,
                            "name": "Leask Huang",
                            "nickname": "",
                            "order": 4,
                            "provider": "twitter",
                            "type": "identity",
                            "unreachable": false,
                            "updated_at": "2013-04-25 15:23:44 +0000"
                        },
                        "content": "sadfasdf",
                        "created_at": "2013-05-08 23:00:57 +0000",
                        "id": 2354,
                        "postable_id": 110322,
                        "postable_type": "exfee",
                        "relative": [],
                        "type": "Post",
                        "updated_at": "2013-05-08 23:00:57 +0000",
                        "via": ""
                    }
                ]
            }
        }

