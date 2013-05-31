# Users

    author: Leask Huang
    created date: 2012-10-06
    updated date: 2013-05-31


## Signin / Signup
* endpoint: /v2/users/signin
* POST args:
    - external_username: [str:external_username]
    - provider: [str:provider]
    - password: [str:password] // encoded by utf8 && length >= 4
* returns:
    - 200: {"user_id" : [int:user_id], "token" : [str:token]}
    - 400: no_external_username, external_username must be provided
    - 400: no_password, password must be provided
    - 400: no_provider, provider must be provided
    - 400: unsupported_provider, We are not supporting this kind of provider currently.
    - 400: weak_password, password must be longer than four
    - 403: failed, {"registration_flag" : [str:registration_flag]}
    - 500: failed, failed while signing up new user
