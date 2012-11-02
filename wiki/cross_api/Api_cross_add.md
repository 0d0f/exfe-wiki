## Api cross add

Gather a Cross

endpoint: http://API_ROOT/v2/crosses/add
method: POST

Cross: a cross object in json format

注意：post中json字段要urlencoding，比如  +08:00 要写成 %2b08:00
<pre>
    [title] => Meet huoju 2222
    [description] =>
    [time] => CrossTime Object
        (
            [begin_at] => EFTime Object
                (
                    [date_word] =>
                    [date] => 2012-03-22
                    [time_word] =>
                    [time] => 08:00:00
                    [timezone] => +08:00
                    [id] => 0
                    [type] => EFTime
                )

            [origin] => 03-22-2012 04:00 PM
            [outputformat] =>
            [id] => 0
            [type] => CrossTime
        )

    [place] => Place Object
        (
            [title] =>
            [description] =>
            [lng] => 113.26757050
            [lat] => 23.13177681
            [provider] =>
            [external_id] =>
            [id] => 94
            [type] => Place
        )

    [attribute] => Array
        (
            [state] => published
        )

    [exfee_id] =>
    [widget] => Array
        (
            [0] => Background Object
                (
                    [image] => IMG_0111
                    [widget_id] => 0
                    [id] => 0
                    [type] => Background
                )

        )

    [relative] => Array
        (
            [id] => 0
            [relation] =>
        )
    [type] => Cross
</pre>

## Result:
  cross The [Object_meta_info\#core-property | cross] that was just created.
