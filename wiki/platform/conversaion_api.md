Conversation API
================

特殊conversation内容：
--------------------

默认解析方式：

	"@exfe@twitter look at this image http://instagr.am/xxxx\n cool!"
	=>
	"@exfe@twitter look at this image {{url:http://instagr.am/xxxx}}\n cool!"
	relationship: [{"mention": "identity://123"}, {"url":"http://instagr.am/xxxx"}]

特殊格式解析：

	"@exfe@twitter look at this image {{image:http://instagr.am/xxxx.jpg}}\n cool!"
	=>
	"@exfe@twitter look at this image {{image:http://instagr.am/xxxx.jpg}}\n cool!"
	relationship: [{"mention": "identity://123"}, {"image":"http://instagr.am/xxxx.jpg"}]

	"@exfe@twitter look at this image {{webpage:http://instagr.am/xxxx}}\n cool!"
	=>
	"@exfe@twitter look at this image {{webpage:http://instagr.am/xxxx}}\n cool!"
	relationship: [{"mention": "identity://123"}, {"webpage":"http://instagr.am/xxxx"}]

对外接口
-------

发一条Post到CROSS_ID：

	POST http://API_ROOT/v2/cross/{CROSS_ID}/Conversation?reply=123&via=web&created_at={timestamp}
	{
		"by_identity": {
			"id": 123,
			"external_name": "steve",
			"provider": "twitter",
			...
		},  // 不一定是完整的identity，只要可以识别唯一identity，比如只有id或者external username和provider
		"content": "blablabla"
	}

- reply：表示回复的某条post
- via：客户端信息
- created_at：创建时间

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
		"relationship": [
			{
				"relation": "mention",
				"uri": "identity://234"
			},
			{
				"relation": "reply",
				"uri": "post://123"
			}
		],
		"exfee_id": {EXFEE_ID},
		"ref_id": "cross://{CROSS_ID}"
	}

获得CROSS_ID中的一些Posts：

	GET http://API_ROOT/v2/cross/{CROSS_ID}/Conversation?clear_user=123&since=2011-12-21+23:59:00&until=2012-12-21+23:59:00&min_id=123&max_id=456

- clear_user：清掉对应的user在CROSS_ID的unread count
- since：返回此时间之后的posts
- until：返回此时间之前的posts
- min_id：返回post id大于此id的posts
- max_id：返回post id于此id的posts

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
				"uri": "identity://234"
			}],
			"exfee_id": {EXFEE_ID},
			"ref_id": "cross://{CROSS_ID}"
		},
		{
			...
		},
		...
	]

删除CROSS_ID中的一条Post：

	DELETE http://API_ROOT/v2/cross/{CROSS_ID}/conversation/456

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
			"uri": "identity://234"
		}],
		"exfee_id": {EXFEE_ID},
		"ref_id": "cross://{CROSS_ID}"
	}

获得用户USER_ID在CROSS_ID的未读消息数：

	GET http://API_ROOT/v2/cross/{CROSS_ID}/user/{USER_ID}/unread_count

返回：

	5

对内结构
-------

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
		RefID   string `json:"ref_id"`
	}
