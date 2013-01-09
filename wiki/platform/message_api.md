Message API
===========

对外接口
-------

发一条Message：

	POST http://API_ROOT/v2/message
	{
		"service": [
			"bus://streaming/conversation",
			"bus://notifier/conversation",
		],
		"ticket": "....",
		"recipients": [
			...
		],
		"data": {
			"by_identity": {...},
			"exfee_id": {...},
			"content": "...",
			...
		}
	}

返回：

	2
