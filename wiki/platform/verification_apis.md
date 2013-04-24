# Verification APIs For Front-end


##验证用户(登录前)
* 在用户没有登陆的情况下，给需要验证的身份，请求发送一次验证信息。根据provider，系统会发送的相应的渠道验证信息(VERIFYING)或者返回需要登陆的URL(REDIRECT)并交给客户端触发
* endpoint: users/verifyidentity
* method: post
* args: provider, external_username
* content type: application/x-www-form-urlencoded; charset=utf-8
* returns:
有两种正确结果
    action:VERIFYING（已经发送验证邮件）
    Identity:

    action:REDIRECT（需要重定向到第三方验证）
    url: 直接跳转到第三方登陆用的url
    Identity:
错误结果：
    400 - identity_does_not_exist
    400 - no_external_username
    400 - no_provider
    400 - no_need_to_verify
    500 - failed

* 备注：请使用测试服务器测试本接口，生产服务器发邮件或者短信要钱的。

第一种结果：
Request:

    $ http -fv POST api.panda.0d0f.com/v2/users/verifyidentity provider='email' external_username=stonydemo@gmail.com
    POST /v2/users/VerifyIdentity HTTP/1.1
    Accept: */*
    Accept-Encoding: gzip, deflate, compress
    Content-Length: 54
    Content-Type: application/x-www-form-urlencoded; charset=utf-8
    Host: api.panda.0d0f.com
    User-Agent: HTTPie/0.4.1

    provider=email&external_username=stonydemo%40gmail.com

Response:

    HTTP/1.1 200 OK
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Content-Type: application/json; charset=UTF-8
    Date: Sat, 20 Apr 2013 03:31:03 GMT
    Expires: Thu, 19 Nov 1981 08:52:00 GMT
    Pragma: no-cache
    Server: lighttpd/1.4.28
    Set-Cookie: PHPSESSID=cdi1fl23cc478cjsg5l4f3vo76; path=/; domain=.exfe.com
    Transfer-Encoding: chunked
    X-Powered-By: PHP/5.4.14-1~precise+1

    {
        "meta": {
            "code": 200
        },
        "response": {
            "action": "VERIFYING",
            "identity": {
                "avatar_filename": "http://api.panda.0d0f.com/v2/avatar/default?name=stonydemo",
                "bio": "",
                "connected_user_id": -664,
                "created_at": "2013-04-19 17:01:26 +0000",
                "external_id": "stonydemo@gmail.com",
                "external_username": "stonydemo@gmail.com",
                "id": 664,
                "name": "stonydemo",
                "nickname": "",
                "order": 999,
                "provider": "email",
                "type": "identity",
                "unreachable": false,
                "updated_at": "2013-04-19 17:01:26 +0000"
            }
        }
    }

第二种结果：
Request:

    $ http -fv POST api.panda.0d0f.com/v2/users/verifyidentity provider='facebook' external_username=leaskh
    POST /v2/users/verifyidentity HTTP/1.1
    Accept: */*
    Accept-Encoding: gzip, deflate, compress
    Content-Length: 42
    Content-Type: application/x-www-form-urlencoded; charset=utf-8
    Host: api.panda.0d0f.com
    User-Agent: HTTPie/0.4.1

    provider=facebook&external_username=leaskh

Response:

    HTTP/1.1 200 OK
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Content-Type: application/json; charset=UTF-8
    Date: Mon, 22 Apr 2013 05:02:16 GMT
    Expires: Thu, 19 Nov 1981 08:52:00 GMT
    Pragma: no-cache
    Server: lighttpd/1.4.28
    Set-Cookie: PHPSESSID=6tkhp2en3ek1j01rbus5ope9g2; path=/; domain=.exfe.com
    Transfer-Encoding: chunked
    X-Powered-By: PHP/5.4.14-1~precise+1

    {
        "meta": {
            "code": 200
        },
        "response": {
            "action": "REDIRECT",
            "identity": {
                "avatar_filename": "https://graph.facebook.com/554148635/picture?type=large",
                "bio": "",
                "connected_user_id": -638,
                "created_at": "2013-04-02 14:17:52 +0000",
                "external_id": "554148635",
                "external_username": "leaskh",
                "id": 638,
                "name": "Leask Huang",
                "nickname": "",
                "order": 999,
                "provider": "facebook",
                "type": "identity",
                "unreachable": false,
                "updated_at": "2013-04-02 14:17:52 +0000"
            },
            "url": "https://graph.facebook.com/oauth/authorize?client_id=119145884898699&redirect_uri=http://panda.0d0f.com/OAuth/facebookCallBack&type=web_server&scope=user_photos,email,user_birthday,user_online_presence,status_update,photo_upload,video_upload,create_note,share_item,publish_stream"
        }
    }


##验证用户(登录后)

<pre>
endpoint: VerifyUserIdentity
method: post
args: identity_id, token
returns: VERIFYING（已经发送验证邮件） / REDIRECT（需要重定向到第三方验证）

example:
http -f POST api.local.exfe.com/v2/users/VerifyUserIdentity?token=xxxxxxxxxx identity_id=233
</pre>


##忘记密码
* 用户忘记密码，请求发送验证邮件重设密码
* endpoint: ForgotPassword
* method: post
* args: provider, external_username
* returns: VERIFYING（已经发送重置密码邮件）
    action:VERIFYING（已经发送验证邮件）
        和Identity
* 备注：请使用测试服务器测试本接口，生产服务器发邮件或者短信要钱的。

Request:

    $ http -vf POST api.panda.0d0f.com/v2/users/ForgotPassword provider='email' external_username='stony.demo@gmail.com'
    POST /v2/users/ForgotPassword HTTP/1.1
    Accept: */*
    Accept-Encoding: gzip, deflate, compress
    Content-Length: 55
    Content-Type: application/x-www-form-urlencoded; charset=utf-8
    Host: api.panda.0d0f.com
    User-Agent: HTTPie/0.4.1

    provider=email&external_username=stony.demo%40gmail.com

Response:

    HTTP/1.1 200 OK
    Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
    Content-Type: application/json; charset=UTF-8
    Date: Sat, 20 Apr 2013 05:12:25 GMT
    Expires: Thu, 19 Nov 1981 08:52:00 GMT
    Pragma: no-cache
    Server: lighttpd/1.4.28
    Set-Cookie: PHPSESSID=knoo5ecno8sbvi3s095osf9fc2; path=/; domain=.exfe.com
    Transfer-Encoding: chunked
    X-Powered-By: PHP/5.4.14-1~precise+1

    {
        "meta": {
            "code": 200
        },
        "response": {
            "action": "VERIFYING",
            "identity": {
                "avatar_filename": "http://api.panda.0d0f.com/v2/avatar/default?name=Stony+Demo",
                "bio": "",
                "connected_user_id": -615,
                "created_at": "2013-03-25 22:22:02 +0000",
                "external_id": "stony.demo@gmail.com",
                "external_username": "stony.demo@gmail.com",
                "id": 615,
                "name": "Stony Demo",
                "nickname": "",
                "order": 999,
                "provider": "email",
                "type": "identity",
                "unreachable": false,
                "updated_at": "2013-03-25 22:22:02 +0000"
            }
        }
    }

错误：
400 - no_external_username
400 - no_provider
400 - identity_does_not_exist
400 - identity_is_being_verified
500 - failed


##解释Token

<pre>
endpoint: ResolveToken
method: post
args: token
returns: VERIFIED（该Token为验证用户的Token，并且已经成功验证用户） / INPUT_NEW_PASSWORD（该Token为重设密码Token，接下来可以提交新密码）
returns: user_id, token （如果成功验证用户，用户会被直接登录，此处返回用户的id和登录得到的token）
returns: mergeable_user （如果有可以合并的用户，返回可以合并的用户及其identities信息）

example:
http -f POST api.local.exfe.com/v2/users/ResolveToken token='xxxxxxxxxx'
</pre>

##重设密码

<pre>
endpoint: ResetPassword
method: post
args: token, password, name
returns: returns: user_id, token （如果成功重设密码，用户会被直接登录，此处返回用户的id和登录得到的token）

example:
http -f POST api.local.exfe.com/v2/users/ResetPassword token='xxxxxxxxxx' password='xxxxxxxxxx' name='xxxxxxx'
</pre>
