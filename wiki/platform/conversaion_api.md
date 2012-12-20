Conversation API
----------------

发一条Post到EXFEE_ID：

	POST http://API_ROOT/v2/exfee/{EXFEE_ID}/Conversation
	{
		"by_identity": {
			"id": 123,
			"external_name": "steve",
			"provider": "twitter",
			...
		},  // 不一定是完整的identity，只要可以识别唯一identity，比如只有id或者external username和provider
		"content": "blablabla",
		"via": "web",
		"created_at": "2012-12-21 23:59:00 +0800", // 可选，若没有默认为当前时间
	}

返回：

	{
		"id": 456,
		"via": "web",
		"type": "post",
		"created_at": "2012-12-21 23:59:00 +0800",
		"by_identity": {
			"id": 123,
			"name": "steve exfee",
			...
		},
		"relationship": [{
			"relation": "mention",
			"uri": "identity://external_username@provider",
		}],
		"content": "blablablabla",
		"via": "web",
		"exfee_id": {EXFEE_ID}
	}

获得EXFEE_ID中的一些Posts：

	GET http://API_ROOT/v2/exfee/{EXFEE_ID}/Conversation?clear=false&since=2011-12-21+23:59:00&until=2012-12-21+23:59:00&min_id=123&max_id=456

返回：

	[
		{
			"id": 456,
			"via": "web",
			"type": "post",
			"created_at": "2012-12-21 23:59:00 +0800",
			"by_identity": {
				"id": 123,
				"name": "steve exfee",
				...
			},
			"relationship": [{
				"relation": "mention",
				"uri": "identity://external_username@provider",
			}],
			"content": "blablablabla",
			"via": "web",
			"exfee_id": {EXFEE_ID}
		},
		{
			...
		},
		...
	]

删除EXFEE_ID中的一条Post：

	DELETE http://API_ROOT/v2/exfee/{EXFEE_ID}/conversation/456

返回：

	{
		"id": 456,
		"via": "web",
		"type": "post",
		"created_at": "2012-12-21 23:59:00 +0800",
		"by_identity": {
			"id": 123,
			"name": "steve exfee",
			...
		},
		"relationship": [{
			"relation": "mention",
			"uri": "identity://external_username@provider",
		}],
		"content": "blablablabla",
		"via": "web",
		"exfee_id": {EXFEE_ID}
	}

获得用户USER_ID在EXFEE_ID的未读消息数：

	GET http://API_ROOT/v2/exfee/{EXFEE_ID}/user/{USER_ID}/unread_count

返回：

	5