# iOS push message format



	#!javascript
	{
	    "aps":
	    {
	        "alert":"Gathering the X \\\"test 1a_04271801_release\\\" 6:30 PM, Apr 27, 2012",
	        "badge":4,
	        "sound":"default"
	    },
	    "url":"exfe://zz/!100120"
	    "path":"/!100120"
	}


* aps
    * "badge" 未读消息数量
* url
	
	url，用来区分服务器和控制界面跳转的，参考[iOS URL scheme](ios_url_scheme.html)。
* path (deprecated)

    路径，参考[iOS URL scheme](ios_url_scheme.html)
