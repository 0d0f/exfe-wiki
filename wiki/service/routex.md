# 活点地图

## 接口规划

 - Location 信息更新

    此接口用于更新某个用户的地理信息。用户地理信息 location object 如下：

        {
            "timestamp": nnnnn,
            "lng": "xxxxxx",
            "lat": "yyyyyy"
        }

     - 用户更新 location
     
        POST http://domain/v3/routex/cross/nnnn/location?token=xxxxxx

        Post Data: 

            <location object>

     - 获得某个 cross 所有用户的 location 信息

        GET http://domain/v3/routex/cross/nnnn/location?token=xxxxxx

        Response: 
        
            {
                "id@provider": [<location object>, ...],
                "id@provider": [<location object>, ...],
                ...
            }

 - Route 更新

    此接口用于传输 app 用户画的路径图信息。

     - 更新 Route
    
        POST http://domain/v3/routex/cross/nnnn/route?token=xxxxxxxx

        Post Data: .....

     - 获取 Route

        GET http://domain/v3/routex/cross/nnnn/route?token=xxxxxxxxx

        Response: .....

 - Streaming
 
    获得关于某个 cross 的 route_x 更新的所有通知

    POST http://domain/v3/routex/cross/nnnn?\_method=WATCH&token=xxxxxx

    Response:

        {
            "name": "/cross/nnnn/location",
            "data": {
                "id@provider": [<location object>, ...]
            }
        }
        {
            "name": "/cross/nnnn/route",
            "data": "....." 
        }
