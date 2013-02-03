Mnemosyne API
------------------------
> author: Leask

> created date: 2013-02-01

> updated date: 2013-02-01


## Get PhotoX
* description: 获取一个 PhotoX 下的所有照片。
* endpoint: /v2/photox/[str:photox_id]
* GET args:
    - token: [str:user_token] 
* returns:
    - 200: {"photos" : [array:photo_object]}
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Get albums
* description: 获取某个第三方身份的所有可添加进 PhotoX 的相册。
* endpoint: /v2/photox/GetSouceAlbums
* GET args:
    - token: [str:user_token]
* POST args:
    - identity_id: [int]
    - album_id: [str]
* returns:
    - 200: {"albums" : [array:album_object]} 
    - 400: param_error
    - 401: invalid_auth


## Get source photos
* description: 获取某个第三方身份的照片 feed 中的照片。
* endpoint: /v2/photox/GetSoucePhotos
* GET args:
    - token: [str:user_token]
* POST args:
    - identity_id: [int]
* returns:
    - 200: {"photos" : [array:photo_object]}
    - 400: param_error
    - 401: invalid_auth


## Get photo
* description: 获取某一张照片的全尺寸版本。
* endpoint: /v2/photox/GetPhoto
* GET args:
    - token: [str:user_token]
* POST args:
    - photox_id: [int]
    - id: [int:photo_id]
* returns:
    - 200: {"photo" : [object:photo]}
    - 400: error_getting_photo
    - 401: invalid_auth
    - 403: not_authorized


## Add
* description: 添加照片到 PhotoX。
* endpoint: /v2/photox/Add
* GET args:
    - token: [str:user_token]
* POST args OPTION A / 用于从有相册功能的身份中添加照片
  (eg: Facebook, Flickr, Dropbox):
    - photox_id: [int]
    - identity_id: [int]
    - album_id: [str]
* POST args OPTION B / 用于从有照片流功能的身份中添加照片
  (eg: Instagram): 
    - photox_id: [str]
    - identity_id: [int]
    - min_id: [int]
    - max_id: [int]
* POST args OPTION C / 用于从 PhotoStream 等公开 feed 中加入照片: 
  (eg: PhotoStream): 
    - photox_id: [int]
    - stream_id: [str]
* return:
    - 200: {"photos" : [array:photo_object]}
    - 400: param_error
    - 401: invalid_auth
    - 403: not_authorized


## Add photos (for GoBus only)
* description: GoBus 爬照片回调接口。
* endpoint: /v2/gobus/AddPhotos/[str:photox_id]
* POST args:
    - BODY: [json:photos_array]
* return:
    - 200: ''
    - 500: error_input
