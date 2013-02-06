h1. Api test

一些post用的文件放在testcase下

使用:

signin:

curl -d "external_id=...&provider=email&password=..." http://api.local.exfe.com/v2/users/signin

cross:

curl --http1.0 -d @cross.txt "http://api.local.exfe.com/v2/crosses/add?token=98eddc9c0afc48087f722ca1419c8650"

curl --http1.0 -d @cross_edit.txt "http://api.local.exfe.com/v2/crosses/100183/edit?token=98eddc9c0afc48087f722ca1419c8650"

curl --http1.0 -d @conversation.txt "http://api.local.exfe.com/v1/x/100185/posts?token= 98eddc9c0afc48087f722ca1419c8650"