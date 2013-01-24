    #!javascript
    {
        "id": [int],
        "caption": [str],
        "by_identity": [object:identity],
        "created_at": [str:time],
        "updated_at": [str:time],
        "provider": [str],
        "external_id": [str],
        "location": [object:place],
        "images": {
            "fullsize": {
                "height": [int],
                "width": [int],
                "url": [str:url]
            },
            "thumbnail": {
                "height": [int],
                "width": [int],
                "url": [str:url]
            }
        },
        "type": "photo",
        "siblings": [[object:photo]]
    },
