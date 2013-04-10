# PhotoX API
    author: Leask Huang
    created date: 2013-02-01
    updated date: 2013-02-26


## Basic Objects
* PhotoX

        #!javascript
        {
            "id"     : [int],
            "photos" : [array:photo_object],
            "type"   : "photox"
        }

* photo

        #!javascript
        {
            "id"                : [int],
            "caption"           : [str],
            "by_identity"       : [object:identity],
            "created_at"        : [str:time],
            "updated_at"        : [str:time],
            "provider"          : [str],
            "external_album_id" : [str],
            "external_id"       : [str],
            "location"          : [object:place],
            "images"            : {
                "original" : {
                    "height" : [int],
                    "width"  : [int],
                    "url"    : [str:url],
                },
                "fullsize" : {
                    "height" : [int],
                    "width"  : [int],
                    "url"    : [str:url],
                },
                "preview"  : {
                    "height" : [int],
                    "width"  : [int],
                    "url"    : [str:url]
                }
            },
            "imported"          : [bol],
            "type"              : "photo",
            "siblings"          : [[object:photo]]
        }

* Album

        #!javascript
        {
            "external_id" : [str],
            "provider"    : [str],
            "caption"     : [str],
            "artwork"     : [str:url],
            "count"       : [int],
            "size"        : [str:size],
            "by_identity" : [object:identity]
            "created_at"  : [str:time],
            "updated_at"  : [str:time],
            "imported"    : [bol]
        }

* Response

        #!javascript
        {
            "id"          : [int],
            "object_type" : [str],
            "object_id"   : [str],
            "response"    : [str],
            "by_identity" : [object:identity],
            "created_at"  : [str:time],
            "updated_at"  : [str:time]
        }


## Get PhotoX
* description: 获取一个 PhotoX 下的所有照片。
* endpoint: /v2/photox/[str:photox_id]
* GET args:
    - token: [str:user_token]
    - sort: [str:[imported_time_desc|...]] OPTION
* returns:
    - 200: {"photox" : [object:photox]}
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Browse Source
* description: 获取某个第三方身份的所有可添加进 PhotoX 的相册。
* endpoint: /v2/photox/browseSource
* GET args:
    - token: [str:user_token]
    - identity_id: [int/Optional]
    - album_id: [str/Optional]
    - photox_id: [int/Optional]
* returns:
    - 200:

            #!javascript
            {
                "albums"            : [array:album_object],
                "photos"            : [array:photo_object],
                "failed_identities" : [object:identities]
            }

    - 400: param_error
    - 401: invalid_auth


## Get Source Photo
* description: 获取源照片。
* endpoint: /v2/photox/GetSourcePhotos
* GET args:
    - token: [str:user_token]
* POST args:
    - external_ids: [json:external_id_array]
    - identity_id: [int]
    - album_id: [str]
* returns:
    - 200: {"photos" : [array:photo_object]}
    - 400: error_getting_photo
    - 401: invalid_auth
    - 403: not_authorized
    - 404: photo_not_found


## Get Photo
* description: 获取某一张照片的全尺寸版本。
* endpoint: /v2/photox/GetPhoto
* GET args:
    - token: [str:user_token]
    - photo_id: [int:photo_id]
* returns:
    - 200: {"photo" : [object:photo]}
    - 400: error_getting_photo
    - 401: invalid_auth
    - 403: not_authorized
    - 404: photo_not_found


## Add
* description: 添加照片到 PhotoX。
* endpoint: /v2/photox/[str:photox_id]/Add
* GET args:
    - token: [str:user_token]
* POST args OPTION A / 用于从有相册功能的身份中添加照片
  (eg: Facebook, Flickr, Dropbox):
    - identity_id: [int]
    - album_id: [str]
* POST args OPTION B / 用于从有照片流功能的身份中添加照片
  (eg: Instagram):
    - identity_id: [int]
    - ids: [array:string]
* POST args OPTION C / 用于从 PhotoStream 等公开 feed 中加入照片:
  (eg: PhotoStream):
    - stream_id: [str]
* return:
    - 200: {"photox" : [object:photo]}
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Del
* description: 从 PhotoX 中删除照片。
* endpoint: /v2/photox/[str:photox_id]/Delete
* GET args:
    - token: [str:user_token]
* POST args OPTION A:
    - provider: [str]
    - external_album_id: [str]
* POST args OPTION B:
    - photo_ids: [array:str]
* return:
    - 200: {"photox" : [object:photo]}
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Get likes
* description: 获取照片的 like 状态。
* endpoint: /v2/photox/[str:photox_id]/GetLikes
* GET args:
    - token: [str:user_token]
* return:
    - 200: {"likes" : [array:response_object]}
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Like
* description: Like 一张照片。
* endpoint: /v2/photox/Like
* GET args:
    - token: [str:user_token]
* POST args：
    - id: [int:photo_id]
    - LIKE: [str:"false"] OPTION
* return:
    - 200: {"like" : [object:response]}
    - 400: error_responsing_photo
    - 401: invalid_auth
    - 403: not_authorized
    - 404: photo_not_found


## Add photos (for Bus only)
* description: GoBus 爬照片回调接口。
* endpoint: /v2/gobus/AddPhotos/[str:photox_id]
* POST args:
    - BODY: [json:photos_array]
* return:
    - 200: ''
    - 500: error_input
