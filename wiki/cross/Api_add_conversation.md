## Api add conversation

Add a post

endpoint: http://API_ROOT/v2/conversation/EXFEE_ID/add
method: POST

post: a post object in json format

<pre>
{
"by_identity_id": "174",
"content": "中文的",
"relative": [],
"type": "Post",
"via": ""
}
</pre>


Result:

Post The [[Object_meta_info#post|post]] that was just created.
