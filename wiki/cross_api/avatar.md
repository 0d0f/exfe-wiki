<pre>

Get identity avatar.

if there is no avatar exists, api will return a default avatar based on identity name:

http://api.local.exfe.com/v2/avatar/get?provider=[string]&external_username=[string]


Example:

http://api.local.exfe.com/v2/avatar/get?provider=email&external_username=tester_leonard@0d0f.com

</pre>


<pre>

Render customize avatar from any web image url:

http://api.local.exfe.com/v2/avatar/render?url=[base64_encoded_image_url]&width=[int:x>0]&height=[int:x>0]&alpha=[folat:0<x<=1]&ishost=[true|false]&mates=[int:0<=x<=9]&resolution=[1x|1.5x|2x]


Example:

http://api.local.exfe.com/v2/avatar/render?url=aHR0cDovL3d3dy5ncmF2YXRhci5jb20vYXZhdGFyLzE1YjdmYzFiMTAxZWUyODliODE2Nzg4MTI3ODFhZWE2LnBuZz9kPWh0dHAlM0ElMkYlMkZhcGkuMGQwZi5jb20lMkZ2MiUyRmF2YXRhciUyRmdldCUzRnByb3ZpZGVyJTNEZW1haWwlMjZleHRlcm5hbF91c2VybmFtZSUzRGdvb2dvbGxlZSU0MGdtYWlsLmNvbQ%3D%3D&width=40&height=40&alpha=0.5&ishost=true&mates=9&resolution=2x

</pre>


<pre>

get default avatar:

http://api.local.exfe.com/v2/avatar/default?name=leask
</pre>


<pre>

avatar update:

endpoint: avatar/update
method: post
args: token, identity_id[Optional], origin, 80_80

example:
leask@Flora:~/Downloads> http -f post api.local.exfe.com/v2/avatar/update?token=sadfsadfsdafsdf original@origin.png 80_80@80_80.png
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.3
Set-Cookie: PHPSESSID=ddlia4l53t6ibjcr4sdqg41be4; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Fri, 22 Jun 2012 07:08:31 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    },
    "response": {
        "avatars": {
            "80_80": "http://img.local.exfe.com/8/87/80_80_887cb3d41920d203eb528cf92dbee071.png",
            "original": "http://img.local.exfe.com/8/87/original_887cb3d41920d203eb528cf92dbee071.png"
        },
        "type": "user",
        "user_id": 143
    }
}



leask@Flora:~/Downloads> http -f post api.local.exfe.com/v2/avatar/update?token=sadfsadfsdafsdf original@origin.png 80_80@80_80.png identity_id=341
HTTP/1.1 200 OK
X-Powered-By: PHP/5.4.3
Set-Cookie: PHPSESSID=sl6i7m9p49vsol9qo16ufl3no0; path=/; domain=.exfe.com
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Content-Type: application/json; charset=UTF-8
Transfer-Encoding: chunked
Date: Fri, 22 Jun 2012 07:08:26 GMT
Server: lighttpd/1.4.30

{
    "meta": {
        "code": 200
    },
    "response": {
        "avatars": {
            "80_80": "http://img.local.exfe.com/8/16/80_80_8166d82b95b8d8e68771e28d361d5641.png",
            "original": "http://img.local.exfe.com/8/16/original_8166d82b95b8d8e68771e28d361d5641.png"
        },
        "identity_id": 341,
        "type": "identity"
    }
}

</pre>

<pre>
??????

identitiy:
    ?????????
    garater ??
    user ??
    ??????


user?
    ?????????
    ????????????????
