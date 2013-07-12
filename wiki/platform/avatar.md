# Avatar

    author: Leask Huang
    created date: 2012-10-06
    updated date: 2013-07-12


## Get identity avatar
* description: If there is no avatar exists, api will return a default avatar based on identity name.
* endpoint: /v2/avatar/get?provider=[string]&external_username=[string]


## Render customize avatar from any web image url
* endpoint: /v2/avatar/render?url=[base64_encoded_image_url]&width=[int:x>0]&height=[int:x>0]&alpha=[folat:0<x<=1]&ishost=[true|false]&mates=[int:0<=x<=9]&resolution=[1x|1.5x|2x]


## Get default avatar
* endpoint: /v2/avatar/default?name=[str:name]


## Update avatar for user or identity
* endpoint: /v2/avatar/update
* QUERY args:
    - token
* POST args:
    - identity_id: [int:identity_id] // Optional
* POST files:
    - origin : [bin: png | gif | bmp | jpg(jpeg)]
    - 320_320: [bin: png | gif | bmp | jpg(jpeg)] // Optional
    - 80_80  : [bin: png | gif | bmp | jpg(jpeg)] // Optional
* returns:
    - 200:
        * avatar : [array: avatar_url]
        * avatars: [array: avatar_url] // @warning: will be removed in v3
        * type: [str:user | identity]
        * user_id: [int:user_id] // Optional
        * identity_id: [int:identity_id] // Optional
    - 400: missing_original_sizes
    - 400: identity_does_not_exist
    - 400: provider_error
    - 400: error_image_format
    - 401: not_allowed
    - 401: no_signin
    - 500: error_saving_image
* example:

        #!bash
        $ http -f post api.panda.0d0f.com/v2/avatar/update?token=sadfsadfsdafsdf original@origin.png 80_80@80_80.png
        {
            "meta": {
                "code": 200
            },
            "response": {
                "avatar": {
                    "320_320": "http://img.panda.0d0f.com/8/87/320_320_887cb3d41920d203eb528cf92dbee071.png",
                    "80_80": "http://img.panda.0d0f.com/8/87/80_80_887cb3d41920d203eb528cf92dbee071.png",
                    "original": "http://img.panda.0d0f.com/8/87/original_887cb3d41920d203eb528cf92dbee071.png"
                },
                "avatars": {
                    "320_320": "http://img.panda.0d0f.com/8/87/320_320_887cb3d41920d203eb528cf92dbee071.png",
                    "80_80": "http://img.panda.0d0f.com/8/87/80_80_887cb3d41920d203eb528cf92dbee071.png",
                    "original": "http://img.panda.0d0f.com/8/87/original_887cb3d41920d203eb528cf92dbee071.png"
                },
                "type": "user",
                "user_id": 143
            }
        }

        $ http -f post api.panda.0d0f.com/v2/avatar/update?token=sadfsadfsdafsdf original@origin.png 80_80@80_80.png identity_id=341
        {
            "meta": {
                "code": 200
            },
            "response": {
                "avatar": {
                    "320_320": "http://img.panda.0d0f.com/8/16/320_320_8166d82b95b8d8e68771e28d361d5641.png",
                    "80_80": "http://img.panda.0d0f.com/8/16/80_80_8166d82b95b8d8e68771e28d361d5641.png",
                    "original": "http://img.panda.0d0f.com/8/16/original_8166d82b95b8d8e68771e28d361d5641.png"
                },
                "avatars": {
                    "320_320": "http://img.panda.0d0f.com/8/16/320_320_8166d82b95b8d8e68771e28d361d5641.png",
                    "80_80": "http://img.panda.0d0f.com/8/16/80_80_8166d82b95b8d8e68771e28d361d5641.png",
                    "original": "http://img.panda.0d0f.com/8/16/original_8166d82b95b8d8e68771e28d361d5641.png"
                },
                "identity_id": 341,
                "type": "identity"
            }
        }
