h1. Cross updated

common.php中

saveUpdate($cross_id,$updated) 

传入cross_id和updated。

其中 updated是如下结构的php Array

<pre>
Array
(
    [place] => Array
        (
            [updated_at] => 1335346467
            [identity_id] => 174
        )

    [title] => Array
        (
            [updated_at] => 1335346467
            [identity_id] => 174
        )

    [description] => Array
        (
            [updated_at] => 1335346467
            [identity_id] => 174
        )

    [time] => Array
        (
            [updated_at] => 1335346467
            [identity_id] => 174
        )

    [background] => Array
        (
            [updated_at] => 1335346467
            [identity_id] => 174
        )

)

</pre>

这段信息会被json_encode之后存储在redis中，并附带在api user_crosses对象 中。