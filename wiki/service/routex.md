# 活点地图

## 接口规划

 - Location 信息更新

    此接口用于更新某个用户的地理信息。用户地理信息 location object 如下：

        {
            "timestamp": yyyy,
            "accuracy": "nnn",
            "longitude": "xxxxxx",
            "latitude": "yyyyyy"
        }

     - 用户更新 location

        POST http://domain/v3/cross/nnnn/routex/location?token=xxxxxx

        Post Data:

            <location object>

     - 获得某个 cross 所有用户的 location 信息

        GET http://domain/v3/cross/nnnn/routex/location?token=xxxxxx

        Response:

            {
                "id@provider": [<location object>, ...],
                "id@provider": [<location object>, ...],
                ...
            }

 - Route 更新

    此接口用于传输 app 用户画的路径图信息。

     - 更新 Route

        POST http://domain/v3/cross/nnnn/routex/route?token=xxxxxxxx

        Post Data:

            [
                {
                    "id": "id",
                    "type": "location",
                    "created_at": 0,
                    "created_by": "uid",
                    "updated_at": 0,
                    "updated_by": "uid",
                    "tags": ["place", "park"],
                    "icon": "http://...",
                    "title": "Title",
                    "description": "Description",
                    "longitude": "x.xxx",
                    "latitude": "y.yyy",
                    //"altitude": "z.zzz"
                },
                {
                    "id": "id",
                    "type": "route",
                    "created_at": 0,
                    "created_by": "id@provider",
                    "updated_at": 0,
                    "updated_by": "id@provider",
                    "title": "Title",
                    "description": "Description",
                    "color": "rrggbbaa",
                    "positions": [
                        {"timestamp": 9, "longitude": "x.xxx", "latitude": "y.yyy"},
                        ...
                        {"timestamp": 1, "longitude": "x.xxx", "latitude": "y.yyy"}
                    ]
                }
            ]

     - 获取 Route

        GET http://domain/v3/cross/nnnn/routex/route?token=xxxxxxxxx

        Response:

            [
                {
                    "id": "id",
                    "type": "location",
                    "created_at": 0,
                    "created_by": "uid",
                    "updated_at": 0,
                    "updated_by": "uid",
                    "tags": ["place", "park"],
                    "icon": "http://...",
                    "title": "Title",
                    "description": "Description",
                    "longitude": "x.xxx",
                    "latitude": "y.yyy",
                    //"altitude": "z.zzz"
                },
                {
                    "id": "id",
                    "type": "route",
                    "created_at": 0,
                    "created_by": "id@provider",
                    "updated_at": 0,
                    "updated_by": "id@provider",
                    "title": "Title",
                    "description": "Description",
                    "color": "rrggbbaa",
                    "positions": [
                        {"timestamp": 9, "longitude": "x.xxx", "latitude": "y.yyy"},
                        ...
                        {"timestamp": 1, "longitude": "x.xxx", "latitude": "y.yyy"}
                    ]
                }
            ]

 - Streaming
 
    获得关于某个 cross 的 route_x 更新的所有通知。第一次连接后，会下发cross对应的当前所有location和route的信息。

    POST http://domain/v3/cross/nnnn/routex?\_method=WATCH&token=xxxxxx

    Response:

        {
            "path": "/v3/cross/nnnn/routex/location",
            "room": "location",
            "data": {
                "id@provider": [<location object>, ...]
            }
        }
        {
            "path": "/v3/cross/nnnn/routex/route",
            "room": "route",
            "data": [
                {
                    "id": "id",
                    "type": "location",
                    "created_at": 0,
                    "created_by": "uid",
                    "updated_at": 0,
                    "updated_by": "uid",
                    "tags": ["place", "park"],
                    "icon": "http://...",
                    "title": "Title",
                    "description": "Description",
                    "longitude": "x.xxx",
                    "latitude": "y.yyy",
                    //"altitude": "z.zzz"
                },
                {
                    "id": "id",
                    "type": "route",
                    "created_at": 0,
                    "created_by": "id@provider",
                    "updated_at": 0,
                    "updated_by": "id@provider",
                    "title": "Title",
                    "description": "Description",
                    "color": "rrggbbaa",
                    "positions": [
                        {"timestamp": 9, "longitude": "x.xxx", "latitude": "y.yyy"},
                        ...
                        {"timestamp": 1, "longitude": "x.xxx", "latitude": "y.yyy"}
                    ]
                }
            ]
        }
