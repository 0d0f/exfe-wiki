# API Readme
    author: Leask Huang
    created date: 2013-05-30
    updated date: 2013-05-30


## API Returns
- 200

        #!javascript
        {
            "data" : [object/array:datas]
        }

- 2xx

        #!javascript
        {
            "data" : [object/array:datas],
            "warning" : {
                "code" : [int:error_code],
                "type" : [str:error_type],
                "message" : [anything_needed_to_handle_the_error]
            }
        }

    * demo: 206

            #!javascript
            {
                "data" : {
                    "cross_id" : 233
                },
                "warning" : {
                    "code" : -1,
                    "type" : "exfee_over_soft_quota",
                    "message" : {
                        "exfee_soft_quota" : 12,
                        "exfee_hard_quota" : 50
                    }
                }
            }

- 3xx

        [empty_body]

- 4xx / 5xx

        #!javascript
        {
            "error" : {
                "code" : [int:error_code],
                "type" : [str:error_type],
                "message" : [anything_needed_to_handle_the_error]
            },
            "data" : [object/array:datas] / OPTIONAL
        }


## Supporting Identity Providers
- authenticate
    * twitter
    * facebook
    * flickr
    * dropbox
    * instagram
    * google
- verification
    * phone
    * email


## RSVP Status
* 0 = NORESPONSE
* 1 = ACCEPTED
* 2 = INTERESTED
* 3 = DECLINED
* 4 = REMOVED
* 5 = NOTIFICATION
* 6 = IGNORED


## User Identity Status
* 0 = ''
* 1 = RELATED
* 2 = VERIFYING
* 3 = CONNECTED
* 4 = REVOKED
