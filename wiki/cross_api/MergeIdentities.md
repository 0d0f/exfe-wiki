h1. MergeIdentities

<pre>
endpoint: users/mergeIdentities
args/get:
    token: 当前用户token
args/post:
    browsing_identity_token: 浏览身份token
    identity_ids: json数组，需要合并的身份id

returns:
    mete: 200 成功（部分成功） / 400、401、500 失败
    status: array 每个identity 合并的结果
    mergeable_user: 如果有其他可以合并的identity身份，将返回可以合并的用户极其身份信息

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/users/208/mergeIdentities?token=764ca290b978ddc65e1364e50b36925787c831802f62b83e8aafcf9dcbb9aa06 browsing_identity_token='8ec8efd1910c08dac8cc9301a14a2008bf3e9e13b054df6f64b122d76ef5fa3b' identity_ids='[499,500]'
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.6
Set-Cookie: PHPSESSID=n20rgfv7ddsjqiom60ga44peb6; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Wed, 19 Sep 2012 09:26:13 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "mergeable_user": {
            "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=yyy", 
            "bio": "", 
            "default_identity": {
                "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=yyy", 
                "bio": "", 
                "connected_user_id": 305, 
                "created_at": "2012-09-19 09:23:08 +0000", 
                "external_id": "yyy@leaskh.com", 
                "external_username": "yyy@leaskh.com", 
                "id": 499, 
                "name": "yyy", 
                "nickname": "", 
                "provider": "email", 
                "status": "CONNECTED", 
                "type": "identity", 
                "updated_at": "2012-09-19 09:23:08 +0000"
            }, 
            "id": 305, 
            "identities": [
                {
                    "avatar_filename": "http://api.local.exfe.com/v2/avatar/default?name=e", 
                    "bio": "", 
                    "connected_user_id": 305, 
                    "created_at": "2012-07-25 09:53:25 +0000", 
                    "external_id": "e@leaskh.com", 
                    "external_username": "e@leaskh.com", 
                    "id": 364, 
                    "name": "e", 
                    "nickname": "", 
                    "provider": "email", 
                    "status": "CONNECTED", 
                    "type": "identity", 
                    "updated_at": "2012-07-25 09:53:25 +0000"
                }
            ], 
            "name": "Syxnx", 
            "timezone": "+08:00", 
            "type": "user"
        }, 
        "status": {
            "499": true, 
            "500": true
        }
    }
}
</pre>