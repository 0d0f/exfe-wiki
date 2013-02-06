h1. Verify APIs For Front-end

<pre>
登录前，验证用户
endpoint: VerifyIdentity
method: post
args: provider, external_username
returns: VERIFYING（已经发送验证邮件） / REDIRECT（需要重定向到第三方验证）

example:
http -f POST api.local.exfe.com/v2/users/VerifyIdentity provider='email' external_username='i@leaskh.com'
</pre>


<pre>
登录后，验证用户
endpoint: VerifyUserIdentity
method: post
args: identity_id, token
returns: VERIFYING（已经发送验证邮件） / REDIRECT（需要重定向到第三方验证）

example:
http -f POST api.local.exfe.com/v2/users/VerifyUserIdentity?token=xxxxxxxxxx identity_id=233
</pre>


<pre>
忘记密码
endpoint: ForgotPassword
method: post
args: provider, external_id
returns: VERIFYING（已经发送重置密码邮件）

example:
http -f POST api.local.exfe.com/v2/users/ForgotPassword provider='email' external_id='i@leaskh.com'
</pre>


<pre>
解释Token
endpoint: ResolveToken
method: post
args: token
returns: VERIFIED（该Token为验证用户的Token，并且已经成功验证用户） / INPUT_NEW_PASSWORD（该Token为重设密码Token，接下来可以提交新密码）
returns: user_id, token （如果成功验证用户，用户会被直接登录，此处返回用户的id和登录得到的token）
returns: mergeable_user （如果有可以合并的用户，返回可以合并的用户及其identities信息）

example:
http -f POST api.local.exfe.com/v2/users/ResolveToken token='xxxxxxxxxx'
</pre>


<pre>
重设密码
endpoint: ResetPassword
method: post
args: token, password, name
returns: returns: user_id, token （如果成功重设密码，用户会被直接登录，此处返回用户的id和登录得到的token）

example:
http -f POST api.local.exfe.com/v2/users/ResetPassword token='xxxxxxxxxx' password='xxxxxxxxxx' name='xxxxxxx'
</pre>