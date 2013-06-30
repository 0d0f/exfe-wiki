## Complete

<pre>
  endpoint: identities/complete
  method: get
  args: token, key

  example:
  leask@Flora:~/Documents/Working/exfe/exfeweb/exfeweb> http get api.local.exfe.com/v2/identities/complete?token=sadfsadfsdafsdf\&key=a
  HTTP/1.1 200 OK
  X-Powered-By: PHP/5.4.3
  Set-Cookie: PHPSESSID=2i4m5q97s0csv5g67f6p4lvc72; path=/; domain=.exfe.com
  Expires: Thu, 19 Nov 1981 08:52:00 GMT
  Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
  Pragma: no-cache
  Content-Type: application/json; charset=UTF-8
  Transfer-Encoding: chunked
  Date: Fri, 22 Jun 2012 04:23:16 GMT
  Server: lighttpd/1.4.30

  {
      "meta": {
          "code": 200
      }, 
      "response": {
          "identities": [
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "a@a.com", 
                  "external_username": "a@a.com", 
                  "id": "268", 
                  "name": "a", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/d/ef/80_80_default.png", 
                  "bio": "", 
                  "external_identity": "asdf@asdfasdf.com", 
                  "external_username": "asdf@asdfasdf.com", 
                  "id": "348", 
                  "name": "asdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdf@sadfadsf.com", 
                  "external_username": "asdf@sadfadsf.com", 
                  "id": "344", 
                  "name": "asdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdf@sadfasd.com", 
                  "external_username": "asdf@sadfasd.com", 
                  "id": "280", 
                  "name": "asdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_filename": "http://www.gravatar.com/avatar/693d0e835eb1f36f6b0f86c7b911861d?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fget%3Fprovider%3Demail%26external_id%3Dasdf%40sadfasdfasdf.com", 
                  "bio": "", 
                  "connected_user_id": 0, 
                  "created_at": "2012-06-11 22:56:14", 
                  "external_id": "asdf@sadfasdfasdf.com", 
                  "external_username": "asdf@sadfasdfasdf.com", 
                  "id": 352, 
                  "name": "asdf", 
                  "nickname": "", 
                  "provider": "email", 
                  "type": "identity", 
                  "updated_at": null
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdf@sdaf.com", 
                  "external_username": "asdf@sdaf.com", 
                  "id": "328", 
                  "name": "\u8001\u97e9", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://www.gravatar.com/avatar/00c0d88b3f7e34e549e7ac6c8bf80ce0?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fget%3Fprovider%3Demail%26external_id%3Dasdfads%40asdfasdf.com", 
                  "bio": "", 
                  "external_identity": "asdfads@asdfasdf.com", 
                  "external_username": "asdfads@asdfasdf.com", 
                  "id": "350", 
                  "name": "asdfads", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfads@sdafdsaf.com", 
                  "external_username": "asdfads@sdafdsaf.com", 
                  "id": "287", 
                  "name": "asdfads", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfas@sadfasdf.com", 
                  "external_username": "asdfas@sadfasdf.com", 
                  "id": "345", 
                  "name": "asdfas", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfas@sdafasdf.com", 
                  "external_username": "asdfas@sdafasdf.com", 
                  "id": "278", 
                  "name": "asdfas", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasd@dsafadsf.com", 
                  "external_username": "asdfasd@dsafadsf.com", 
                  "id": "342", 
                  "name": "asdfasd", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasd@sadfasdf.com", 
                  "external_username": "asdfasd@sadfasdf.com", 
                  "id": "262", 
                  "name": "asdfasd", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/d/ef/80_80_default.png", 
                  "bio": "", 
                  "external_identity": "asdfasd@sdfsdaf.com", 
                  "external_username": "asdfasd@sdfsdaf.com", 
                  "id": "351", 
                  "name": "asdfasd", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasdf@asdfasdf.com", 
                  "external_username": "asdfasdf@asdfasdf.com", 
                  "id": "286", 
                  "name": "asdfasdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasdf@dsafsadf.com", 
                  "external_username": "asdfasdf@dsafsadf.com", 
                  "id": "298", 
                  "name": "asdfasdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasdf@sadfsd.com", 
                  "external_username": "asdfasdf@sadfsd.com", 
                  "id": "306", 
                  "name": "asdfasdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasdf@sdafasdf.com", 
                  "external_username": "asdfasdf@sdafasdf.com", 
                  "id": "263", 
                  "name": "asdfasdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasdf@sdafsadf.com", 
                  "external_username": "asdfasdf@sdafsadf.com", 
                  "id": "297", 
                  "name": "asdfasdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfasdf@sdfsd.com", 
                  "external_username": "asdfasdf@sdfsd.com", 
                  "id": "325", 
                  "name": "asdfasdf", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfd@dsafasdf.com", 
                  "external_username": "asdfd@dsafasdf.com", 
                  "id": "311", 
                  "name": "asdfd", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfds@asdfasdf.com", 
                  "external_username": "asdfds@asdfasdf.com", 
                  "id": "279", 
                  "name": "asdfds", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfs@sdafsdf.com", 
                  "external_username": "asdfs@sdafsdf.com", 
                  "id": "266", 
                  "name": "asdfs", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "asdfsa@sadfads.com", 
                  "external_username": "asdfsa@sadfads.com", 
                  "id": "346", 
                  "name": "asdfsa", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://www.gravatar.com/avatar/271e44c3ae06e47f8468f309839dd55d?d=http%3A%2F%2Fapi.local.exfe.com%2Fv2%2Favatar%2Fget%3Fprovider%3Demail%26external_id%3Dasdfsd%40sdafasdf.com", 
                  "bio": "", 
                  "external_identity": "asdfsd@sdafasdf.com", 
                  "external_username": "asdfsd@sdafasdf.com", 
                  "id": "349", 
                  "name": "asdfsd", 
                  "provider": "email"
              }, 
              {
                  "avatar_file_name": "http://img.local.exfe.com/8/6f/80_80_86f61dd57ca0c0a177c6b10ee9d62ff8.png", 
                  "bio": "", 
                  "external_identity": "axc22sd@dsf.com", 
                  "external_username": "axc22sd@dsf.com", 
                  "id": "269", 
                  "name": "axc22sd", 
                  "provider": "email"
              }
          ]
      }
  }
</pre>
