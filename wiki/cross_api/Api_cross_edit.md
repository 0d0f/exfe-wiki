h1. Api cross edit

Edit a Cross

endpoint: http://API_ROOT/v2/crosses/CROSS_ID/edit
method: POST

Cross: a cross object in json format

注意：post中json字段要urlencoding，比如  +08:00 要写成 %2b08:00
<pre>
cross= {
    "attribute": {
        "state": "published"
    },
    "by_identity_id": "174",
    "description": "desc...",
    "place": {
        "description": "place desc",
        "external_id": "",
        "id": "94",
        "lat": "23.13177681",
        "lng": "113.26757050",
        "provider": "",
        "title": "place title",
        "type": "Place"
    },
    "relative": {
        "id": 0,
        "relation": ""
    },
    "time": {
        "begin_at": {
            "date": "2012-03-22",
            "date_word": "",
            "id": 0,
            "time": "08:00:00",
            "time_word": "",
            "timezone": "%2B08:00",
            "type": "EFTime"
        },
        "id": 0,
        "origin": "03-22-2012 04:00 PM",
        "outputformat": "",
        "type": "CrossTime"
    },
    "title": "post by curl",
    "type": "Cross",
    "widget": [
        {
            "id": 0,
            "image": "IMG_0111",
            "type": "Background",
            "widget_id": 0
        }
    ]
}
</pre>

Result:

cross	The [[Object_meta_info#core-property | cross]] that was just edited.
