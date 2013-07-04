# token服务

## token结构

存储上的形式如下：

    {
        "key": "cccccc", // 根据类型不同，key长度不同
        "hash": "ccccc", // 根据resource字段做的md5
        "user_id": "xxxx@provider", // token对应的所有者的user id
        "scopes": ["...", "..."], // token的权限
        "client": "cccc", // 申请token的客户端名字
        "created_at": "nnnn", // token创建时间
        "expires_at": "nnnn", // token的过期时间
        "touched_at": "nnnn", // token最近一次被访问的时间
        "data": "....", // token附加数据，不参与索引
    }

## scope说明

scope代表了一个服务的操作权限。一个token具有这个scope，意味着拥有执行对应服务的权限。token服务并不判断权限是否有效，交由具体服务判断。

例子：

 - user: exfe://user
 - verification: exfe://user/verification
 - cross ics: exfe://cross/ics
 - cross access: exfe://cross/access

## token manager

manager会监听http请求。如果url query里含有token或者t字段，manager会将该字段的值取出，查到对应的token结构，将结构里的数据塞入http header，下发给下游服务。如果没有相关字段，http请求不作处理直接转发。

## token内容与http header对应关系

 - scopes: ["exfe://user", "exfe://cross/ics"] -> Exfe-Auth-Scopes: exfe://user, exfe://cross/ics
 - user_id: "xxxx@provider" -> Exfe-Auth-User-Id: xxxx@provider
 - client: "client" -> Exfe-Auth-Client: client
 - expires_at: "1371630909" -> Exfe-Auth-Expires-At: 1371630909
 - touched_at: "1371630909" -> Exfe-Auth-Touched-At: 1371630909
 - data: "abcde" -> Exfe-Auth-Data: abcde

额外字段：

 - Exfe-Auth-Verified: true/false

    如果http请求里的token请求有效，则为true，否则为false。

 - Exfe-Auth-Version: 1