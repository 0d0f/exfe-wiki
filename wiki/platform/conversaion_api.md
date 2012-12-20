Conversation API
----------------

对外接口
=======

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
		"by_identity": {
			"id": 123,
			"name": "steve exfee",
			...
		},
		"content": "blablablabla",
		"via": "web",
		"created_at": "2012-12-21 23:59:00 +0800",
		"relationship": [{
			"relation": "mention",
			"uri": "identity://external_username@provider",
		}],
		"exfee_id": {EXFEE_ID}
	}

获得EXFEE_ID中的一些Posts：

	GET http://API_ROOT/v2/exfee/{EXFEE_ID}/Conversation?clear=false&since=2011-12-21+23:59:00&until=2012-12-21+23:59:00&min_id=123&max_id=456

返回：

	[
		{
			"id": 456,
			"by_identity": {
				"id": 123,
				"name": "steve exfee",
				...
			},
			"content": "blablablabla",
			"via": "web",
			"created_at": "2012-12-21 23:59:00 +0800",
			"relationship": [{
				"relation": "mention",
				"uri": "identity://external_username@provider",
			}],
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
		"by_identity": {
			"id": 123,
			"name": "steve exfee",
			...
		},
		"content": "blablablabla",
		"via": "web",
		"created_at": "2012-12-21 23:59:00 +0800",
		"relationship": [{
			"relation": "mention",
			"uri": "identity://external_username@provider",
		}],
		"exfee_id": {EXFEE_ID}
	}

获得用户USER_ID在EXFEE_ID的未读消息数：

	GET http://API_ROOT/v2/exfee/{EXFEE_ID}/user/{USER_ID}/unread_count

返回：

	5

对内结构
=======

Meta结构：

	type Relationship struct {
		URI      string `json:"uri"`
		Relation string `json:"relation"`
	}

	type Meta struct {
		ID           string         `json:"id"`
		Type         string         `json:"type"`
		CreatedAt    time.Time      `json:"created_at"`
		By           Identity       `json:"by"`
		Relationship []Relationship `json:"relationship"`
	}

Post结构：

	type Post struct {
		model.Meta
		Content string `json:"content"`
		Via     string `json:"via"`
		ExfeeID uint64 `json:"exfee_id"`
	}
