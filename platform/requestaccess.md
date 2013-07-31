# Request Access

    author: Leask Huang
    created date: 2013-07-23
    updated date: 2013-07-23


## Request
* endpoint: /v2/exfee/[int:exfee_id]/request
* POST args:
    - provider: [str:provider]
    - external_username: [str:external_username]
    - cross_id: [int:cross_id] // OPTIONAL
    - invitation_token: [str:invitation_token] // OPTIONAL
* returns:
    - 200: [object:request]
    - 400: error_provider
    - 400: error_external_username
    - 400: no_exfee_id
    - 404: exfee_not_found
    - 403: not_authorized
    - 401: invalid_auth
    - 400: invalid_request
    - 500: identity_error
    - 400: no_need
    - 500: server_error


## Approve
* endpoint: /v2/exfee/[int:exfee_id]/request/[int:request_id]/approve
* QUERY args:
    - token: [str:user_token]
* returns:
    - 200: [object:request]
    - 400: no_exfee_id
    - 404: exfee_not_found
    - 403: not_authorized
    - 401: invalid_auth
    - 500: server_error


## Decline
* endpoint: /v2/exfee/[int:exfee_id]/request/[int:request_id]/decline
* QUERY args:
    - token: [str:user_token]
* returns:
    - 200: [object:request]
    - 400: no_exfee_id
    - 404: exfee_not_found
    - 403: not_authorized
    - 401: invalid_auth
    - 500: server_error
