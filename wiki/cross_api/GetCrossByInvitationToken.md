h1. GetCrossByInvitationToken

<pre>
endpoint: crosses/GetCrossByInvitationToken
args:
    GET: token(user)
    POST: invitation_token

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/crosses/GetCrossByInvitationToken?token=sadfsadfssadffsdf invitation_token='fabfa3ce994b802e99f7c94575647eb8'
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.6
Set-Cookie: PHPSESSID=1o30dsbjtmk89gbbdj8fgihh37; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Tue, 11 Sep 2012 14:01:25 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "authorization": {
            "name": "Leask Huang", 
            "password": true, 
            "token": "764ca290b978ddc65e1364e50b36925770235de727fcf78a46e9c86d1330f718", 
            "user_id": 208
        }, 
        "cross": {
            "attribute": {
                "state": "published"
            }, 
            "by_identity": {
                "avatar_filename": "http://www.gravatar.com/avatar/0b4d9df63e92a6002ce8018589aab61f", 
                "bio": "", 
                "connected_user_id": 208, 
                "created_at": "2012-05-22 17:22:27 +0000", 
                "external_id": "leaskh@gmail.com", 
                "external_username": "leaskh@gmail.com", 
                "id": 331, 
                "name": "Leask Huang", 
                "nickname": "", 
                "provider": "email", 
                "type": "identity", 
                "updated_at": "2012-09-03 06:23:15 +0000"
            }, 
            "conversation_count": 0, 
            "created_at": "2012-09-10 10:20:36", 
            "description": "", 
            "exfee": {
                "accepted": 1, 
                "id": 110141, 
                "invitations": [
                    {
                        "by_identity": {
                            "avatar_filename": "http://www.gravatar.com/avatar/0b4d9df63e92a6002ce8018589aab61f", 
                            "bio": "", 
                            "connected_user_id": 208, 
                            "created_at": "2012-05-22 17:22:27 +0000", 
                            "external_id": "leaskh@gmail.com", 
                            "external_username": "leaskh@gmail.com", 
                            "id": 331, 
                            "name": "Leask Huang", 
                            "nickname": "", 
                            "provider": "email", 
                            "type": "identity", 
                            "updated_at": "2012-09-03 06:23:15 +0000"
                        }, 
                        "created_at": "2012-09-10 10:20:36 +0000", 
                        "host": true, 
                        "id": 803, 
                        "identity": {
                            "avatar_filename": "http://www.gravatar.com/avatar/0b4d9df63e92a6002ce8018589aab61f", 
                            "bio": "", 
                            "connected_user_id": 208, 
                            "created_at": "2012-05-22 17:22:27 +0000", 
                            "external_id": "leaskh@gmail.com", 
                            "external_username": "leaskh@gmail.com", 
                            "id": 331, 
                            "name": "Leask Huang", 
                            "nickname": "", 
                            "provider": "email", 
                            "type": "identity", 
                            "updated_at": "2012-09-03 06:23:15 +0000"
                        }, 
                        "mates": 0, 
                        "rsvp_status": "ACCEPTED", 
                        "token": "", 
                        "type": "invitation", 
                        "updated_at": "2012-09-10 10:20:36 +0000", 
                        "via": ""
                    }, 
                    {
                        "by_identity": {
                            "avatar_filename": "http://www.gravatar.com/avatar/0b4d9df63e92a6002ce8018589aab61f", 
                            "bio": "", 
                            "connected_user_id": 208, 
                            "created_at": "2012-05-22 17:22:27 +0000", 
                            "external_id": "leaskh@gmail.com", 
                            "external_username": "leaskh@gmail.com", 
                            "id": 331, 
                            "name": "Leask Huang", 
                            "nickname": "", 
                            "provider": "email", 
                            "type": "identity", 
                            "updated_at": "2012-09-03 06:23:15 +0000"
                        }, 
                        "created_at": "2012-09-10 10:20:36 +0000", 
                        "host": false, 
                        "id": 804, 
                        "identity": {
                            "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=e", 
                            "bio": "", 
                            "connected_user_id": 305, 
                            "created_at": "2012-07-25 09:53:25 +0000", 
                            "external_id": "e@leaskh.com", 
                            "external_username": "e@leaskh.com", 
                            "id": 364, 
                            "name": "e", 
                            "nickname": "", 
                            "provider": "email", 
                            "type": "identity", 
                            "updated_at": "2012-07-25 09:53:25 +0000"
                        }, 
                        "mates": 0, 
                        "rsvp_status": "NORESPONSE", 
                        "token": "", 
                        "type": "invitation", 
                        "updated_at": "2012-09-10 10:20:36 +0000", 
                        "via": ""
                    }
                ], 
                "items": 2, 
                "total": 2, 
                "type": "exfee", 
                "updated_at": "2012-09-10 10:20:36"
            }, 
            "id": 100264, 
            "place": {
                "created_at": "2012-09-10 10:20:36 +0000", 
                "description": "", 
                "external_id": "", 
                "id": 539, 
                "lat": "0.00000000", 
                "lng": "0.00000000", 
                "provider": "", 
                "title": "", 
                "type": "Place", 
                "updated_at": "2012-09-10 10:20:36 +0000"
            }, 
            "relative": [], 
            "time": {
                "begin_at": {
                    "date": "2012-09-10", 
                    "date_word": "", 
                    "id": 0, 
                    "time": "", 
                    "time_word": "", 
                    "timezone": "+08:00 CST", 
                    "type": "EFTime"
                }, 
                "id": 0, 
                "origin": "2012-09-10", 
                "outputformat": 0, 
                "type": "CrossTime"
            }, 
            "title": "Meet Leask Huang", 
            "type": "Cross", 
            "widget": [
                {
                    "id": 0, 
                    "image": "hongkong.jpg", 
                    "type": "Background", 
                    "widget_id": 0
                }
            ]
        }, 
        "cross_access_token": "d829fbb3d2fc2647d92cdb9fdcc637138a183f5ec946030277a41d848d645127", 
        "read_only": false
    }
}

</pre>