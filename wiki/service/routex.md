# 活点地图

## 接口规划

 - Geo信息更新

    此接口用于更新某个用户的地理信息。用户地理信息geo object如下：

        {
            "id": "uin@wechat",
            "geos": [
                {
                    "timestamp": nnnnn,
                    "data": [geojson point object]
                },
                ...
            ]
        }

     - 用户更新geo
     
        POST http://domain/v3/route_x/cross/nnnn/geo?token=xxxxxx

        Data: geo object

     - 获得某个cross所有用户的geo信息

        GET http://domain/v3/route_x/cross/nnnn/geo?token=xxxxxx

        Response: 
        
            {
                "uin@wechat": [geo object],
                "uin@wechat": [geo object],
                ...
            }

 - Path更新

    此接口用于传输app用户画的路径图信息。

     - 更新Path
    
        POST http://domain/v3/route_x/cross/nnnn/path?token=xxxxxxxx

        Post Data: [[geojson path object], ...]

     - 获取Path

        GET http://domain/v3/route_x/cross/nnnn/path?token=xxxxxxxxx

        Response: [[geojson path object], ...]

 - Streaming
 
    获得关于某个cross的route_x更新的所有通知

    POST http://domain/v3/route\_x/cross/nnnn?\_method=WATCH&token=xxxxxx

    Response:

        {
            "name": "/cross/nnnn/geo",
            "data": [geo object]
        }
        {
            "name": "/cross/nnnn/path",
            "data": [[geojson path object], ...]
        }


