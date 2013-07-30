h1. Api user crosses

endpoint: http://API_ROOT/v2/users/USER_ID/crosses

USER_ID : user 的数字ID

参数：
token
updated_at [Optional]

例: http://api.local.exfe.com/v2/users/131/crosses?token=xxxxxxxxxxxxx
<pre>

Array
(
    [0] => Cross Object
        (
            [id_base62] => 
            [title] => post by curl
            [description] => desc...
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
                    [title] => place title
                    [description] => 
                    [lng] => 113.26757050
                    [lat] => 23.13177681
                    [provider] => 
                    [external_id] => 
                    [created_at] => 
                    [updated_at] => 1334641460
                    [id] => 144
                    [type] => Place
                )

            [attribute] => Array
                (
                    [state] => published
                )

            [exfee] => Exfee Object
                (
                    [invitations] => Array
                        (
                            [0] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => huoju
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 132
                                            [external_id] => hj@exfe.com
                                            [external_username] => hj@exfe.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/e461fe2d48746288ffef676def2f6e82?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:59
                                            [updated_at] => 
                                            [id] => 175
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => ACCEPTED
                                    [via] => 
                                    [created_at] => 2012-04-12 06:20:36
                                    [updated_at] => 2012-04-12 06:20:36
                                    [token] => 
                                    [id] => 325
                                    [type] => invitation
                                )

                            [1] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => bbbbb
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => bbbbb@c.com
                                            [external_username] => bbbbb@c.com
                                            [avatar_filename] => default.png
                                            [created_at] => 2012-03-16 10:16:00
                                            [updated_at] => 
                                            [id] => 176
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => NORESPONSE
                                    [via] => 
                                    [created_at] => 2012-04-12 06:20:36
                                    [updated_at] => 2012-04-12 06:20:36
                                    [token] => 
                                    [id] => 326
                                    [type] => invitation
                                )

                        )

                    [id] => 110011
                    [type] => exfee
                )

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
            [created_at] => 
            [by_identity] => Identity Object
                (
                    [name] => virushuo
                    [nickname] => 
                    [bio] => 
                    [provider] => email
                    [connected_user_id] => 131
                    [external_id] => virushuo@gmail.com
                    [external_username] => virushuo@gmail.com
                    [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                    [created_at] => 2012-03-09 08:41:20
                    [updated_at] => 
                    [id] => 174
                    [type] => identity
                )

            [id] => 0
        )

    [1] => Cross Object
        (
            [id_base62] => 
            [title] => post by curl
            [description] => desc...
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
                    [title] => place title
                    [description] => 
                    [lng] => 113.26757050
                    [lat] => 23.13177681
                    [provider] => 
                    [external_id] => 
                    [created_at] => 
                    [updated_at] => 1334641460
                    [id] => 145
                    [type] => Place
                )

            [attribute] => Array
                (
                    [state] => published
                )

            [exfee] => Exfee Object
                (
                    [invitations] => Array
                        (
                            [0] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => huoju
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 132
                                            [external_id] => hj@exfe.com
                                            [external_username] => hj@exfe.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/e461fe2d48746288ffef676def2f6e82?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:59
                                            [updated_at] => 
                                            [id] => 175
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => ACCEPTED
                                    [via] => 
                                    [created_at] => 2012-04-13 10:25:28
                                    [updated_at] => 2012-04-13 10:25:28
                                    [token] => 
                                    [id] => 327
                                    [type] => invitation
                                )

                            [1] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => bbbbb
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => bbbbb@c.com
                                            [external_username] => bbbbb@c.com
                                            [avatar_filename] => default.png
                                            [created_at] => 2012-03-16 10:16:00
                                            [updated_at] => 
                                            [id] => 176
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => NORESPONSE
                                    [via] => 
                                    [created_at] => 2012-04-13 10:25:28
                                    [updated_at] => 2012-04-13 10:25:28
                                    [token] => 
                                    [id] => 328
                                    [type] => invitation
                                )

                        )

                    [id] => 110012
                    [type] => exfee
                )

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
            [created_at] => 
            [by_identity] => Identity Object
                (
                    [name] => virushuo
                    [nickname] => 
                    [bio] => 
                    [provider] => email
                    [connected_user_id] => 131
                    [external_id] => virushuo@gmail.com
                    [external_username] => virushuo@gmail.com
                    [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                    [created_at] => 2012-03-09 08:41:20
                    [updated_at] => 
                    [id] => 174
                    [type] => identity
                )

            [id] => 0
        )

    [2] => Cross Object
        (
            [id_base62] => 
            [title] => post by curl
            [description] => desc...
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
                    [title] => place title
                    [description] => 
                    [lng] => 113.26757050
                    [lat] => 23.13177681
                    [provider] => 
                    [external_id] => 
                    [created_at] => 
                    [updated_at] => 1334641460
                    [id] => 146
                    [type] => Place
                )

            [attribute] => Array
                (
                    [state] => published
                )

            [exfee] => Exfee Object
                (
                    [invitations] => Array
                        (
                            [0] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => huoju
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 132
                                            [external_id] => hj@exfe.com
                                            [external_username] => hj@exfe.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/e461fe2d48746288ffef676def2f6e82?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:59
                                            [updated_at] => 
                                            [id] => 175
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => ACCEPTED
                                    [via] => 
                                    [created_at] => 2012-04-13 10:29:10
                                    [updated_at] => 2012-04-13 10:29:10
                                    [token] => 
                                    [id] => 329
                                    [type] => invitation
                                )

                            [1] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => bbbbb
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => bbbbb@c.com
                                            [external_username] => bbbbb@c.com
                                            [avatar_filename] => default.png
                                            [created_at] => 2012-03-16 10:16:00
                                            [updated_at] => 
                                            [id] => 176
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => NORESPONSE
                                    [via] => 
                                    [created_at] => 2012-04-13 10:29:10
                                    [updated_at] => 2012-04-13 10:29:10
                                    [token] => 
                                    [id] => 330
                                    [type] => invitation
                                )

                        )

                    [id] => 110013
                    [type] => exfee
                )

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
            [created_at] => 
            [by_identity] => Identity Object
                (
                    [name] => virushuo
                    [nickname] => 
                    [bio] => 
                    [provider] => email
                    [connected_user_id] => 131
                    [external_id] => virushuo@gmail.com
                    [external_username] => virushuo@gmail.com
                    [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                    [created_at] => 2012-03-09 08:41:20
                    [updated_at] => 
                    [id] => 174
                    [type] => identity
                )

            [id] => 0
        )

    [3] => Cross Object
        (
            [id_base62] => 
            [title] => post by curl
            [description] => desc...
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
                    [title] => place title
                    [description] => 
                    [lng] => 113.26757050
                    [lat] => 23.13177681
                    [provider] => 
                    [external_id] => 
                    [created_at] => 
                    [updated_at] => 1334641460
                    [id] => 147
                    [type] => Place
                )

            [attribute] => Array
                (
                    [state] => published
                )

            [exfee] => Exfee Object
                (
                    [invitations] => Array
                        (
                            [0] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => huoju
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 132
                                            [external_id] => hj@exfe.com
                                            [external_username] => hj@exfe.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/e461fe2d48746288ffef676def2f6e82?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:59
                                            [updated_at] => 
                                            [id] => 175
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => ACCEPTED
                                    [via] => 
                                    [created_at] => 2012-04-13 10:29:17
                                    [updated_at] => 2012-04-13 10:29:17
                                    [token] => 
                                    [id] => 331
                                    [type] => invitation
                                )

                            [1] => Invitation Object
                                (
                                    [identity] => Identity Object
                                        (
                                            [name] => bbbbb
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => bbbbb@c.com
                                            [external_username] => bbbbb@c.com
                                            [avatar_filename] => default.png
                                            [created_at] => 2012-03-16 10:16:00
                                            [updated_at] => 
                                            [id] => 176
                                            [type] => identity
                                        )

                                    [by_identity] => Identity Object
                                        (
                                            [name] => virushuo
                                            [nickname] => 
                                            [bio] => 
                                            [provider] => email
                                            [connected_user_id] => 131
                                            [external_id] => virushuo@gmail.com
                                            [external_username] => virushuo@gmail.com
                                            [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                                            [created_at] => 2012-03-09 08:41:20
                                            [updated_at] => 
                                            [id] => 174
                                            [type] => identity
                                        )

                                    [rsvp_status] => NORESPONSE
                                    [via] => 
                                    [created_at] => 2012-04-13 10:29:17
                                    [updated_at] => 2012-04-13 10:29:17
                                    [token] => 
                                    [id] => 332
                                    [type] => invitation
                                )

                        )

                    [id] => 110014
                    [type] => exfee
                )

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
            [created_at] => 
            [by_identity] => Identity Object
                (
                    [name] => virushuo
                    [nickname] => 
                    [bio] => 
                    [provider] => email
                    [connected_user_id] => 131
                    [external_id] => virushuo@gmail.com
                    [external_username] => virushuo@gmail.com
                    [avatar_filename] => http://www.gravatar.com/avatar/b578b513f1d494bf0248faaedcc38699?d=DEFAULT_AVATAR_URL
                    [created_at] => 2012-03-09 08:41:20
                    [updated_at] => 
                    [id] => 174
                    [type] => identity
                )

            [id] => 0
        )

)
</pre>