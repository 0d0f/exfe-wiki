    #!javascript
    {
        "id": [int],
        "caption": [str],
        "by_identity": [object:identity],
        "created_at": [str:time],
        "updated_at": [str:time],
        "provider": [str],
        "external_album_id": [str],
        "external_id": [str],
        "location": [object:place],
        "images": {
            "origin": {
                "height": [int],
                "width": [int],
                "url": [str:url],
            },
            "fullsize": {
                "height": [int],
                "width": [int],
                "url": [str:url],
            },
            "preview": {
                "height": [int],
                "width": [int],
                "url": [str:url]
            }
        },
        "type": "photo",
        "siblings": [[object:photo]]
    },
