h1. Api cross update

在redis中记录部分字段变化状况。
如

<pre>
{
"place":{"updated_at":xxxx,"identity_id":IDENTITY_ID },
"time":{"updated_at":xxxx,"identity_id":IDENTITY_ID },
"title":{"updated_at":xxxx,"identity_id":IDENTITY_ID},
"desc":{"updated_at":xxxx,"identity_id":IDENTITY_ID },
"exfee":{"updated_at":xxxx,"identity_id":IDENTITY_ID },
"conversation":{"updated_at":xxxx}
}

</pre>

某一类对象比如 conversation 需要根据api参数中的访问时间，从数据库生成conversation对象。
