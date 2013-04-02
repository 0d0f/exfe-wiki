live发现服务
===========

模型
----

 - Identity

	表示一个Identity的对象

		{
			"external_id": "id",
			"external_username": "username",
			"provider": "provider"
		}

 - Card

	表示一个Card的对象

		{
			"id": "card id",
			"name": "user name",
			"avatar": "http://avatar/url",
			"bio": "some bio",
			"identities": [...], // 由Identity组成的数组，包括用户所有的身份信息
			"is_me": true // 表示是不是自己
		}
 - Data

	Data对象

		{
			"card": [card object],
			"latitude": 134.52545435,
			"longitude": 52.54243214325,
			"accuracy": 10,
			"traits": [...]      // 由字符串组成的数组，用来给一组用户做特征标记，比如ip或者用户选择的识别码
		}

接口
----

 - 注册Card

	POST http://server/v3/live/cards?token=xxxx

	报文内容为Data对象。返回值为下次请求需要的token。

	第一次请求时，不用带token，系统会根据当前状态返回一个token字符串。在指定时间内（1分钟）可以用这个token来连接更新接口，并且用这个token提交同一个人Card的更新情况。如果超过指定时间，则token作废，使用作废token提交的任何请求都会被拒绝，需要用不带token的方式注册Card，等同于一次新的流程。

 - 更新接口

	GET http://server/v3/live/streaming?token=xxxx

	token为注册Card时获得的token。每次该Card所在的组更新时，会下发这个组最新的Card数据，格式是card对象的array。
