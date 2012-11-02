h1. Api del post

delete a post

endpoint: http://API_ROOT/v2/conversation/EXFEE_ID/del?post_id=POST_ID
EXFEE_ID: 所属exfee 的数字id
POST_ID: 要删除的post数字id
method: GET

如果删除成功，会返回被删除的post id和exfee id。
<pre>

{"meta":{"code":200},
"response":{"post":{"id":"792","exfee_id":"100098"}}
}
</pre>