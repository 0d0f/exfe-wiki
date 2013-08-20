# iOS URL Schema 
## Description
用来支持通过URI直接打开App的功能。根据用户user_id以及token可能触发身份合并或者重新登陆。

设计原则：

1. 兼容Android
2. 和[Web的路由](/web/router.html)尽量统一 

## Index(New)
* [Cross List](#crosses)
* [Cross](#cross)
* [Conversation](#conversation)
* [Exfee](#exfee)
* [routex](#routex)
* [Gather](#gather)
* [Profile](#profile)

## Schema
目前注册的Schema是exfe://，测试版本则使用black://(0d0f 黑盒)和panda://(pilot P盒)。
## Host
(默认)
## Parameters
### user_id
用来标示登陆的用户信息，必选。
### token
授权的token，必选。
### identity_id (Optional)
用来标示更改的身份信息，不是每个调用都有，一般用于Profile的更新或者添加Identity。

##Path
### <a id="crosses"></a>Cross List
/

直接打开Cross List界面

其他不认识的path

### <a id="cross"></a>Cross
/!%CROSS_ID%

直接打开CrossID为%CROSS_ID%的Cross Detail界面

### <a id="conversation"></a>Conversation
/!%CROSS_ID%/conversation

直接打开CrossID为%CROSS_ID%的Cross Conversation界面


### <a id="exfee"></a>Exfee
/!%CROSS_ID%/exfee

直接打开CrossID为%CROSS_ID%的Cross Exfee界面

### <a id="routex"></a>Routex
/!%CROSS_ID%/routex

直接打开CrossID为%CROSS_ID%的Cross Routex界面

### <a id="gather"></a>Gather
/gather

直接打开Gather界面

* /gather/place
* /gather/time
* /gather/title
* /gather/description

### <a id="profile"></a>Profile
/users/profile
直接打开Profile界面


---

##Index (Deprecated)   
* [Cross](#cross_2)
* [Cross List](#crosses_2)
* [Profile](#profile_2)
* [Identity (NOT Implemented)](#identity_2)
   
## Parameters
### user_id
用来标示登陆的用户信息，必选。
### token
授权的token，必选。
### identity_id (Optional)
用来标示更改的身份信息，不是每个调用都有，一般用于Profile的更新或者添加Identity。

##Schema
### <a id="cross_2"></a>Cross
exfe://crosses/%CROSS_ID%
直接打开CrossID为%CROSS_ID%的Cross Detail界面

### <a id="crosses_2"></a>Cross List
exfe://crosses
直接打开Cross List界面

### <a id="profile_2"></a>Profile
exfe://profile
直接打开Profile界面
草稿：
exfe://profile/username/edit
exfe://profile/IDENTITY_ID/edit
exfe://profile/password/change
exfe://profile/password/reset

### <a id="identity_2"></a>Identity (NOT Implemented)
exfe://Identity/IDENTITY_ID
添加Identity（未完成）

