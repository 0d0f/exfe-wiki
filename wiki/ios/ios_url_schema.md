# iOS URL Schema 
## Description
用来支持通过URI直接打开App的功能。目前注册的Schema是exfe://，测试版本则使用black://(0d0f 黑盒)和panda://(pilot P盒)。
根据用户user_id以及token可能触发身份合并或者重新登陆。
   
##Index    
* [Cross](#cross)
* [Cross List](#crosses)
* [Profile](#profile)
* [Identity (NOT Implemented)](#identity)
   
## Parameters
### user_id
用来标示登陆的用户信息，必选。
### token
授权的token
### identity_id (Optional)
用来标示更改的身份信息，不是每个调用都有，一般用于Profile的更新或者添加Identity。

##Schema
### <a id="cross"></a>Cross
exfe://crosses/%CROSS_ID%
直接打开CrossID为%CROSS_ID%的Cross Detail界面

### <a id="crosses"></a>Cross List
exfe://crosses
直接打开Cross List界面

### <a id="profile"></a>Profile
exfe://profile
直接打开Profile界面

### <a id="identity"></a>Identity (NOT Implemented)
exfe://Identity/IDENTITY_ID
添加Identity（未完成）

