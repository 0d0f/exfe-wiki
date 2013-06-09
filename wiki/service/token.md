# token服务

## token结构

存储上的形式如下：

    {
        "token": "cccccc", // 根据类型不同，token长度不同
        "hash": "ccccc", // 根据resource字段做的md5
        "id": "xxxx@provider", // token对应的所有者id
        "scopes": ["...", "..."], // token的权限
        "client": "cccc", // 申请token的客户端名字
        "created_at": "YYYY-MM-DD HH:MM:SS", // token创建时间
        "expires_in": "YYYY-MM-DD HH:MM:SS", // token的过期时间
        "touched_at": "YYYY-MM-DD HH:MM:SS", // token最近一次被访问的时间
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

manager会监听http请求。url query里必须含有token或者t字段，manager会将该字段的值取出，查到对应的token结构（如果不存在token，或者没有对应字段，返回403 Forbidden），将结构里的数据塞入http header，下发给下游服务。

## token内容与http header对应关系

 - scopes: ["exfe://user", "exfe://cross/ics"] -> Exfe-Auth-Scopes: exfe://user, exfe://cross/ics
 - id: "xxxx@provider" -> Exfe-Id: xxxx@provider
 - client: "client" -> Exfe-Auth-Client: client
 - created_at: "2010-01-02 15:04:05" -> Exfe-Auth-Created-At: Mon, 2 Jan 2010 15:04:05 GMT
 - expires_in: "2010-01-02 15:04:05" -> Exfe-Auth-Expires-In: Mon, 2 Jan 2010 15:04:05 GMT
 - touched_at: "2010-01-02 15:04:05" -> Exfe-Auth-Touched-At: Mon, 2 Jan 2010 15:04:05 GMT
 - data: "abcde" -> Exfe-Auth-Data: abcde