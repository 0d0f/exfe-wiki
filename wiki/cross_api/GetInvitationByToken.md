h1. GetInvitationByToken

<pre>
endpoint: crosses/GetInvitationByToken
args: cross_id, token(invitation token 2, 3, 4)

example:
leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/crosses/100234/GetInvitationByToken token=4fe
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.4
Set-Cookie: PHPSESSID=ural9q70d8eapfklt6hb15skb1; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Fri, 10 Aug 2012 07:42:58 GMT
Server: lighttpd/1.4.31

{
    "meta": {
        "code": 200
    }, 
    "response": {
        "invitation": {
            "by_identity": {
                "avatar_filename": "http://www.gravatar.com/avatar/502d0bc996b5cc9d5e8bbedd6bb42235.jpg?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fget%3Fprovider%3Demail%26external_username%3De%40leaskh.com", 
                "bio": "", 
                "connected_user_id": 0, 
                "created_at": "2012-07-25 09:53:25", 
                "external_id": "e@leaskh.com", 
                "external_username": "e@leaskh.com", 
                "id": 364, 
                "name": "", 
                "nickname": "", 
                "provider": "email", 
                "type": "identity", 
                "updated_at": null
            }, 
            "created_at": "2012-07-25 09:53:04", 
            "host": false, 
            "id": 615, 
            "identity": {
                "avatar_filename": "http://www.gravatar.com/avatar/5b53fb71b6f36f46fe9cb14eb5acd56f.jpg?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fget%3Fprovider%3Demail%26external_username%3Di%40leaskh.com", 
                "bio": "", 
                "connected_user_id": 207, 
                "created_at": "2012-05-17 15:56:42", 
                "external_id": "i@leaskh.com", 
                "external_username": "i@leaskh.com", 
                "id": 324, 
                "name": "Leask", 
                "nickname": "", 
                "provider": "email", 
                "type": "identity", 
                "updated_at": null
            }, 
            "mates": 0, 
            "rsvp_status": "NORESPONSE", 
            "token": "", 
            "type": "invitation", 
            "updated_at": "2012-07-27 09:02:57", 
            "via": ""
        }
    }
}

</pre>