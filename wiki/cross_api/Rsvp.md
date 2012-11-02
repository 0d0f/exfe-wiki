h1. Rsvp

<pre>
endpoint: api.local.exfe.com/v2/exfee/[exfee_id]/rsvp?token=xxxxxxx
method: post
args:
rsvp=[
    {
        identity_id : [int]
        rsvp_status : '[Enumerate: 'NORESPONSE', 'ACCEPTED', 'INTERESTED', 'DECLINED', 'REMOVED', 'NOTIFICATION']'
        by_identity_id : [int]
        type : 'rsvp'
    }
]

example:

leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http -f post api.local.exfe.com/v2/exfee/110000/rsvp?token=sadfsadfsdafsdf rsvp="[{\"identity_id\":233, \"rsvp_status\":\"ACCEPTED\", \"by_identity_id\":233}]"
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.3
Set-Cookie: PHPSESSID=rf0u338dh9te4rnah1q2l7a136; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Mon, 04 Jun 2012 10:07:44 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    },
    "response": {
        "rsvp": [
            {
                "by_identity_id": 233, 
                "identity_id": 233, 
                "rsvp_status": ACCEPTED, 
                "type": "rsvp"
            }
        ]
    }
}


</pre>
