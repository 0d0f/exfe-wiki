# Vote API
    author: Leask Huang
    created date: 2013-07-04
    updated date: 2013-07-05

## Basic Objects
* Vote

        #!javascript
        {
            "id"          : [int],
            "status"      : [str:DRAFT | OPENING | PAUSED | CLOSED | 'DELETED'],
            "title"       : [str:length <= 233],
            "description" : [str:length <= 64k],
            "created_by"  : [object:Identity],
            "updated_by:  : [object:Identity],
            "created_at"  : [str:time],
            "updated_at"  : [str:time],
            "options"     : [array:option],
            "type"        : "vote",
            "responses"   : [array:response_object],
        }


* Option

        #!javascript
        {
            "id"          : [int],
            "title"       : [str:length <= 233],
            "data"        : [object],
            "created_by"  : [object:Identity],
            "updated_by:  : [object:Identity],
            "created_at"  : [str:time],
            "updated_at"  : [str:time],
            "type"        : "option"
        }


* Response Object Prototype

        #!javascript
        {
            "id"          : [int],
            "object_type" : [str:object_type],
            "object_id"   : [int:object_id],
            "response"    : [str:length < 233],
            "by_identity" : [object:Identity],
            "created_at"  : [str:time],
            "updated_at"  : [str:time],
            "type"        : "response"
        }


* Response Object In Vote

        #!javascript
        {
            "id"          : [int],
            "object_type" : "option",
            "object_id"   : [int:option_id],
            "response"    : "AGREE",
            "by_identity" : [object:Identity],
            "created_at"  : [str:time],
            "updated_at"  : [str:time],
            "type"        : "response"
        }


## Get All Widgets Of Cross
* endpoint: /v2/crosses/[inr:cross_id]/widgets
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* returns
    - 200: [array: widget_object] // vote as widget
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Create Vote
* endpoint: /v2/votes/create
* QUERY args:
    - token: [str:user_token | cross_identity_token]
    - cross_id: [int: cross_id]
* POST args:
    - BODY: [object: vote]
* returns:
    - 200: [object: vote]
    - 400: error_vote
    - 401: invalid_auth
    - 403: not_authorized


## Get Vote
* endpoint: /v2/votes/[int:vote_id]
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* returns:
    - 200: [object: vote]
    - 401: invalid_auth
    - 403: not_authorized
    - 404: not_found


## Update Vote
* endpoint: /v2/votes/[int:vote_id]/update
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* POST args:
    - BODY: [object: vote]
* returns:
    - 200: [object: vote]
    - 400: error_vote
    - 401: invalid_auth
    - 403: not_authorized


## Close Vote
* endpoint: /v2/votes/[int:vote_id]/close
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* returns:
    - 200: [object: vote]
    - 400: error_vote
    - 401: invalid_auth
    - 403: not_authorized


## Delete Vote
* endpoint: /v2/votes/[int:vote_id]/delete
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* returns:
    - 200: [int: vote_id]
    - 400: error_vote
    - 401: invalid_auth
    - 403: not_authorized


## Add Options
* endpoint: /v2/votes/[int:vote_id]/options/add
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* POST args:
    - BODY: [array: option_object]
* returns:
    - 200: [object: vote]
    - 400: error_option
    - 401: invalid_auth
    - 403: not_authorized
    - 404: not_found


## Update Option
* endpoint: /v2/votes/[int:vote_id]/options/[int:option_id]/update
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* POST args:
    - BODY: [object: option]
* returns:
    - 200: [object: vote]
    - 400: error_option
    - 401: invalid_auth
    - 403: not_authorized
    - 404: not_found


## Remove Options
* endpoint: /v2/votes/[int:vote_id]/options/[int:option_id]/remove
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* returns:
    - 200: [object: vote]
    - 400: error_option
    - 401: invalid_auth
    - 403: not_authorized
    - 404: not_found


## Vote
* endpoint: /v2/votes/[int:vote_id]/options/[int:option_id]/vote
* QUERY args:
    - token: [str:user_token | cross_identity_token]
* returns:
    - 200: [object: vote]
    - 400: error_option
    - 401: invalid_auth
    - 403: not_authorized
    - 404: not_found
