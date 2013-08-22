# 活点地图

## 通用原则

所有接口支持coordinate参数，表示操作的坐标系是地球坐标earth还是火星坐标mars。如果不给此参数，默认为地球坐标。

所有接口支持token参数，用于权鉴。其中GET接口支持user_token，cross_access_token和cross invitation code，其余接口支持user_token和cross_access_token。

## 数据模型

 - Location模型

    Location模型表示一个坐标点，并带有描述点的相关信息。

        {
            "id": "id",
            "type": "location",
            "created_at": nnn,
            "created_by": "uid",
            "updated_at": nnn,
            "updated_by": "uid",
            "tags": ["place", "park"],
            "icon": "http://...",
            "title": "Title",
            "description": "Description",
            "lng": x.xxx,
            "lat": y.yyy
        }

 - Simple Location模型

    Simple Location模型用于提交用户的坐标信息。

        {
            "t": yyyy,
            "gps": [x.xxx, y.yyy, n.nnn]
            // gps信息，都是浮点数。第一个值表示纬度latitude，第二个表示经度longitude，第三个表示经纬度的精度accuracy
        }

 - Route模型

    Route模型表示一条线，并带有描述线的相关信息。

        {
            "id": "id",
            "type": "route",
            "created_at": 0,
            "created_by": "id@provider",
            "updated_at": 0,
            "updated_by": "id@provider",
            "tags": ["breadcrumbs", "geomarks"],
            "title": "Title",
            "description": "Description",
            "color": "rrggbbaa",
            "positions": [
                {"t": yyyy, "gps": []}, // 最新
                ...
                {"t": yyyy, "gps": []} // 最老
            ]
        }

## 接口规划

 - 获取某个cross_id是否曾经开启过routex

    此接口提交一个cross_id的列表，返回对应的cross是否开启过routex服务，如果开启过服务，返回routex最后的更新时间。

    此接口为内部接口，外部不能调用。

     POST http://domain/v3/routex/_inner/search/crosses

     Request Data:

        [
            nnnnn, // cross_id
            nnnn,
            nnnn
        ]

    Response Data:

        [
            {"cross_id": nnnnn, "enable": true,  "updated_at": xxxxx},
            {"cross_id": nnnn,  "enable": false},
            {"cross_id": nnnn,  "enable": false},
            ...
        ]


 - 设置cross

     - 获取用户在cross_id里routex的状态

        获取用户在某个cross的routex的状态，true为开启上报，false为关闭上报，null为用户没有操作过当前cross对应的routex。

        GET http://domain/v3/routex/_inner/users/:user_id/crosses/:cross_id

        Response:

            true

        or

            false

        or

            null

     - 提交用户可以更新的cross（内部接口）

        此接口设置用户提交的地理信息可以展示在哪个cross里。一次开启默认持续2个小时（可以在after_in_seconds设置，默认7200），就是说从上发一次save_breadcrumbs为true的时刻开始，2个小时内，此用户上发的breadcrumbs信息会存入对应的cross里。

        POST http://domain/v3/routex/_inner/users/:user_id/crosses/:cross_id

        Request Data:

            {"save_breadcrumbs": true, "after_in_seconds": 7200},

        or

            {"save_breadcrumbs": false}

     - 提交用户可以更新的cross

        POST http://domain/v3/routex/users/crosses/:cross_id?token=xxxxxxxx

        Request Data:

            {"save_breadcrumbs": true, "after_in_seconds": 7200},

        or

            {"save_breadcrumbs": false}

 - 用户路径信息breadcrumbs更新

    此接口用于更新某个用户的路径信息breadcrumbs。每个breadcrumbs的id为所属用户的user_id。

     - 用户更新 route

        POST http://domain/v3/routex/breadcrumbs?coordinate=(earth|mars)&token=xxxxxx

        gps一项至少包含三个float值，且第三个值的范围是(0,70]。

        Request Data:

            [
                {"t": yyyy, "gps": []}, // 最新
                <simple location>,
                <simple location>       // 最老
            ]

        Response:

            {
                "earth_to_mars_latitude": xx.xxxx,
                "earth_to_mars_longitude": yy.yyyy
            }

     - 用户更新 route（内部用）

        POST http://domain/v3/routex/_inner/breadcrumbs/users/:user_id?coordinate=(earth|mars)

        Request Data:

            [
                {"t": yyyy, "gps": []}, // 最新
                <simple location>,
                <simple location>       // 最老
            ]

        Response:

            {
                "earth_to_mars_latitude": xx.xxxx,
                "earth_to_mars_longitude": yy.yyyy
            }

     - 获得某个 cross 所有用户的 breadcrumbs 信息

        GET http://domain/v3/routex/breadcrumbs/crosses/:cross_id?coordinate=(earth|mars)&token=xxxxxx

        Response:

            [
                <route object with tag breadcrumbs, id is user identity id>,
                {
                    "id": "user_id@exfe",
                    "type": "route",
                    "created_at": 0,
                    "created_by": "",
                    "updated_at": 0,
                    "updated_by": "",
                    "tags": ["breadcrumbs"],
                    "title": "Title",
                    "description": "Description",
                    "color": "rrggbbaa",
                    "positions": [
                        {"t": yyyy, "gps": []}, // 最新
                        ...
                        {"t": yyyy, "gps": []}, // 最老
                    ]
                },
                <route object with tag breadcrumbs, id is user identity id>
            ]

     - 获得某个 cross 某个用户的 breadcrumbs 信息

        GET http://domain/v3/routex/breadcrumbs/crosses/:cross_id/users/:user_id?coordinate=(earth|mars)&token=xxxxxx&after_timestamp=xxxxx

        每次最多只返回最新的100个positions，如果要请求更多的数据，可以指定after_timestamp参数，表示从after_timestamp时间开始再往更老的时间取最多100个数据。

        Response:

            {
                "id": "user_id@exfe",
                "type": "route",
                "created_at": 0,
                "created_by": "",
                "updated_at": 0,
                "updated_by": "",
                "tags": ["breadcrumbs"],
                "title": "Title",
                "description": "Description",
                "color": "rrggbbaa",
                "positions": [
                    {"t": yyyy, "gps": []}, // 最新
                    ...
                    {"t": yyyy, "gps": []}, // 最老
                ]
            }

     - 获得某个用户的 breadcrumbs 信息 内部使用

        GET http://domain/v3/routex/breadcrumbs/users/:user_id?coordinate=(earth|mars)

        Response:

            {
                "id": "user_id@exfe",
                "type": "route",
                "created_at": 0,
                "created_by": "",
                "updated_at": 0,
                "updated_by": "",
                "tags": ["breadcrumbs"],
                "title": "Title",
                "description": "Description",
                "color": "rrggbbaa",
                "positions": [
                    {"t": yyyy, "gps": []} // 最新
                ]
            }

 - Geomarks 更新

    此接口用于传输 app 用户画的路径图信息。url中的type字段为geomark的类型，可以为route或者location。

     - 设置某个 Geomark

        如果已经有同id的geomark存在，则覆盖原来的geomark，如果没有则新建一个geomark。

        PUT http://domain/v3/routex/geomarks/crosses/:cross_id/:geomark_type/:geomark_id?coordinate=(earth|mars)&token=xxxxxxxx

        or

        POST http://domain/v3/routex/geomarks/crosses/:cross_id/geomarks/:geomark_type/:geomark_id?coordinate=(earth|mars)&token=xxxxxxxx&_method=PUT

        Request Data:

            {
                "id": "id",
                "type": "location",
                "created_at": nnn,
                "created_by": "uid",
                "updated_at": nnn,
                "updated_by": "uid",
                "tags": ["place", "park"],
                "icon": "http://...",
                "title": "Title",
                "description": "Description",
                "lng": x.xxx,
                "lat": y.yyy,
            }

        or

            {
                "id": "id",
                "type": "route",
                "created_at": 0,
                "created_by": "id@provider",
                "updated_at": 0,
                "updated_by": "id@provider",
                "tags": ["breadcrumbs", "geomarks"],
                "title": "Title",
                "description": "Description",
                "color": "rrggbbaa",
                "positions": [
                    {"t": yyyy, "gps": []}, // 最新
                    ...
                    {"t": yyyy, "gps": []}, // 最老
                ]
            }

     - 删除某个 Geomark

        DELETE http://domain/v3/routex/geomarks/crosses/:cross_id/:geomark_type/:geomark_id?token=xxxxxxxx

        or

        POST http://domain/v3/routex/geomarks/crosses/:cross_id/:geomark_type/:geomark_id?token=xxxxxxxx&_method=DELETE

     - 搜索geomark，内部使用

        GET http://domain/v3/routex/_inner/geomarks/crosses/:cross_id?tags=destination

        Response:

            [
                {
                    "id": "id",
                    "type": "location",
                    "created_at": nnn,
                    "created_by": "uid",
                    "updated_at": nnn,
                    "updated_by": "uid",
                    "tags": ["destination", "park"],
                    "icon": "http://...",
                    "title": "Title",
                    "description": "Description",
                    "lng": x.xxx,
                    "lat": y.yyy,
                }
            ]
  

     - 获取 Geomarks

        GET http://domain/v3/routex/geomarks/crosses/:cross_id?coordinate=(earth|mars)&token=xxxxxxxxx

        Response:

            [
                {
                    "id": "id",
                    "type": "location",
                    "created_at": nnn,
                    "created_by": "uid",
                    "updated_at": nnn,
                    "updated_by": "uid",
                    "tags": ["place", "park"],
                    "icon": "http://...",
                    "title": "Title",
                    "description": "Description",
                    "lng": x.xxx,
                    "lat": y.yyy,
                },
                {
                    "id": "id",
                    "type": "route",
                    "created_at": 0,
                    "created_by": "id@provider",
                    "updated_at": 0,
                    "updated_by": "id@provider",
                    "tags": ["breadcrumbs", "geomarks"],
                    "title": "Title",
                    "description": "Description",
                    "color": "rrggbbaa",
                    "positions": [
                        {"t": yyyy, "gps": []}, // 最新
                        ...
                        {"t": yyyy, "gps": []}, // 最老
                    ]
                }
            ]

 - Request

    给用户发送push，通知用户登录routex。identity_id是external_username@provider的形式。

    POST http://domain/v3/routex/notification/crosses/:cross_id/:identity_id?token=xxxxxx

    No Request Data.

    No Response.

     - 200

        成功

     - 401

        token无效

     - 403

        用户identity_id不在cross里

     - 406

        用户identity_id没有可以发送的渠道。

 - Streaming

    获得关于某个 cross 的 route_x 更新的所有通知。第一次连接后，会下发cross对应的当前所有breadcrumbs和geomarks的信息。对于route对象，每次下发对象最多含有100个position信息，多于100个position会拆成几次分别下发，id相同，updated at相同。如果updated at不同但id相同的route，需要覆盖之前的同id route内容。对于tag为breadcrumbs的route对象，只包含对应用户最新所在点的信息。

    POST http://domain/v3/routex/crosses/:cross_id?_method=WATCH&coordinate=(earth|mars)&token=xxxxxx

    Response:

        {
            "id": "user_id@exfe",
            "type": "route",
            "created_at": 0,
            "created_by": "",
            "updated_at": 0,
            "updated_by": "",
            "tags": ["breadcrumbs"],
            "title": "Title",
            "description": "Description",
            "color": "rrggbbaa",
            "positions": [
                {"t": yyyy, "gps": []}, // 最新
            ]
        }
        {
            "id": "id",
            "type": "location",
            "created_at": nnn,
            "created_by": "uid",
            "updated_at": nnn,
            "updated_by": "uid",
            "tags": ["place", "park"],
            "icon": "http://...",
            "title": "Title",
            "description": "Description",
            "lng": x.xxx,
            "lat": y.yyy
        }
        {
            "action": "update", // 流建立后立刻下发的历史geomark对象不带action字段，之后更新的geomark都带action update字段。
            "id": "id",
            "type": "route",
            "created_at": 0,
            "created_by": "id@provider",
            "updated_at": 0,
            "updated_by": "id@provider",
            "tags": ["geomarks"],
            "title": "Title",
            "description": "Description",
            "color": "rrggbbaa",
            "positions": [
                {"t": yyyy, "gps": []},
                ...
                {"t": yyyy, "gps": []}
            ]
        }
        {
            "action": "delete",
            "id": "id",
            "type": "route",
        } // 表示删除对应id的mark。
