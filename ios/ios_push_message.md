# iOS push message format



	#!javascript
	{
	    "aps":
	    {
	        "alert":"Gathering the X \\\"test 1a_04271801_release\\\" 6:30 PM, Apr 27, 2012",
	        "badge":4,
	        "sound":"default"
	    },
	    "path":"/!100120"
	}


* aps
    * "badge" 未读消息数量
* path

    路径，参考[iOS URL scheme](ios_url_scheme.html)
