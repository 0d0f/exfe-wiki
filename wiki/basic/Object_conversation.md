h1. Object conversation


endpoint: http://API_ROOT/v2/conversation/EXFEE_ID?updated_at=TIMESTAMP&clear=false

EXFEE_ID : exfee 的数字ID
updated_at :最后更新时间
clear：是否清空阅读状态，默认为true


例: http://api.local.exfe.com/v2/conversation/100100

<pre>
Array
(
    [0] => Post Object
        (
            [by_identity] => Identity Object
                (
                    [name] => huoju
                    [nickname] =>
                    [bio] =>
                    [provider] => email
                    [connected_user_id] => 132
                    [external_id] => hj@exfe.com
                    [external_username] => hj@exfe.com
                    [avatar_filename] => http://www.gravatar.com/avatar/e461fe2d48746288ffef676def2f6e82?d=DEFAULT_AVATAR_URL
                    [avatar_updated_at] => 0000-00-00 00:00:00
                    [created_at] => 2012-03-09 08:41:59
                    [updated_at] =>
                    [id] => 175
                    [type] => identity
                )

            [content] => 123123123123
            [postable_id] => 100100
            [postable_type] => exfee
            [via] =>
            [relative] => Array
                (
                )

            [type] => Post
            [created_at] =>
            [id] => 712
        )

    [1] => Post Object
        (
            [by_identity] => Identity Object
                (
                    [name] => huoju
                    [nickname] =>
                    [bio] =>
                    [provider] => email
                    [connected_user_id] => 132
                    [external_id] => hj@exfe.com
                    [external_username] => hj@exfe.com
                    [avatar_filename] => http://www.gravatar.com/avatar/e461fe2d48746288ffef676def2f6e82?d=DEFAULT_AVATAR_URL
                    [avatar_updated_at] => 0000-00-00 00:00:00
                    [created_at] => 2012-03-09 08:41:59
                    [updated_at] =>
                    [id] => 175
                    [type] => identity
                )

            [content] => aaaabbbb
            [postable_id] => 100100
            [postable_type] => cross
            [via] =>
            [relative] => Array
                (
                )

            [type] => Post
            [created_at] =>
            [id] => 713
        )
)
</pre>
