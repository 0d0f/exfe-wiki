# iOS push message format


	{
	    "aps":
	    {
	        "alert":"Gathering the X \\\"test 1a_04271801_release\\\" 6:30 PM, Apr 27, 2012",
	        "badge":4,
	        "sound":"default"
	    },
	    "args":
	    {
	        "cid":100120,
	        "t":"i"
	    }
	}


1 "badge" 未读消息数量   
2 cid: cross_id   
3 "t" 是类型

* c:conversation   
* i:invite to a new cross   
* u:update   
* r:remove a user from exfee   