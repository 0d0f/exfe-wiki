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
</pre>