Update User name
===
Description:
---

* method:
	POST
* endpoint:
	<%API_V2_ROOT%>users/update?token=[string]
* encoding:
	FormURLParameterEncoding
* url args: 

	"token"=[string]
* form args: 

	"name"=[string]
* return:
	user object

Sample:
---

	leask@Flora:~/Downloads> http -f post api.local.exfe.com/v2/users/update?token=sadfsadfsdafsdf name="LLLLL"
	HTTP/1.1 200 OK
	X-Powered-By: PHP/5.3.13
	Set-Cookie: PHPSESSID=iulcd1bjdpaj85m1oi1t6omk43; path=/; domain=.exfe.com
	Expires: Thu, 19 Nov 1981 08:52:00 GMT
	Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
	Pragma: no-cache
	Content-Type: application/json; charset=UTF-8
	Transfer-Encoding: chunked
	Date: Thu, 31 May 2012 10:32:40 GMT
	Server: lighttpd/1.4.30

	{
	    "meta": {
	        "code": 200
	    }, 
	    "response": {
	        "user": {
	            "avatar_filename": "", 
	            "avatar_updated_at": null, 
	            "bio": "I am a physicist at CalTech and live with my best friend Sheldon.", 
	            "default_identity": {
	                "avatar_filename": "http://img.local.exfe.com/8/6f/86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
	                "bio": "ok", 
	                "connected_user_id": 143, 
	                "created_at": "2012-05-08 18:37:59", 
	                "external_id": "tester_leonard@0d0f.com", 
	                "external_username": "tester_leonard@0d0f.com", 
	                "id": 233, 
	                "name": "\u6566\u5b57", 
	                "nickname": "", 
	                "provider": "email", 
	                "status": "CONNECTED", 
	                "type": "identity", 
	                "updated_at": "2012-05-31 18:09:26"
	            }, 
	            "id": 143, 
	            "identities": [
	                {
	                    "avatar_filename": "http://img.local.exfe.com/8/6f/86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
	                    "bio": "ok", 
	                    "connected_user_id": 143, 
	                    "created_at": "2012-05-08 18:37:59", 
	                    "external_id": "tester_leonard@0d0f.com", 
	                    "external_username": "tester_leonard@0d0f.com", 
	                    "id": 233, 
	                    "name": "\u6566\u5b57", 
	                    "nickname": "", 
	                    "provider": "email", 
	                    "status": "CONNECTED", 
	                    "type": "identity", 
	                    "updated_at": "2012-05-31 18:09:26"
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
	                    "avatar_filename": "", 
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
	            "name": "LLLLL", 
	            "timezone": "+08:00", 
	            "type": "user"
	        }
	    }
	}

