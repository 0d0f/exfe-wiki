here发现服务
===========

模型
----

 - Identity

 	{
 		"id": "external_id@provider"
	}

 - User

 	{
 		"id": "1234567890",  // 10位数字组成的字符串id
 		"name": "user name",
 		"avatar": "http://avatar/url",
 		"bio": "some bio",
 		"identities": [...], // 由Identity组成的数组，包括用户所有的身份信息
 		"latitude": 134.52545435,
 		"longitude": 52.54243214325,
 		"accuracy": 10,
 		"traits": [...]      // 由字符串组成的数组，用来给一组用户做特征标记，比如ip或者用户选择的识别码
 	}

接口
----

 - 注册用户

 	POST http://server/v3/here/users

 	报文内容为User对象。
 	
 - 用户更新接口

 	GET http://server/v3/here/streaming?token=user_id	 

 	user_id为注册用户时使用的user id。