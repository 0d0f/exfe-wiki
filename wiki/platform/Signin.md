h1. Signin

endpoint: http://API_ROOT/v2/users/signin

POST:
external_username: string
provider: string
password: string

<pre>

return:
{
    meta : 200,
    response :
    {
        user_id: int
        token: string
    }
}

error:

403 no_external_username
403 no_provider
403 no_password
400 weak_password
400 unsupported_provider
403 failed

</pre>
