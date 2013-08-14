#·X·页框架流程

## URL格式
domain/!:cross_id/:widget?xcode=xxxx&via=identity

## 基本流程
1. if (WebKit = 微信)
    a. 本地已有user_token
        1. 当isSmith时将user下的微信（或首选）身份加到cross中。     //需服务器下发isSmith标识
        1. getCross(user_token)，成功则根据URL判断加载cross或widget页，开始执行js。
    a. 调用微信内OAuth，并保存返回的user_token
        1. 如果返回的user_token与本地不同则合并身份     //此步骤待定
        1. 当isSmith时将user下的微信（或首选）身份加到cross中。
        1. getCross(user_token)，成功则根据URL判断加载cross或widget页，开始执行js。
        1. getCrossByInvitationToken，若返回user_roken则将微信身份合并，并根据URL判断加载cross或widget页，开始执行js。
        1. 显示invalid link页，结束。
    a. 显示提示页面告知用户必须需同意OAuth
        1. 当isSmith时可让用户输入手机邮箱验证。
    a. 结束。
//以下流程未完成
1. if (cross-access-token)
    1. call getCrossByInvitationToken();
    1. （浏览身份相关逻辑）成功则打开·X·或widget页面。
    1. 结束。
1. 用本地user-token调用getCross接口。成功则打开·X·或widget页面。
    1. （合并身份逻辑）
    1. 结束。

##·X·页面框架逻辑


### 有 xcode
  1. 有 xcode
  2. 检查本地是否有 cross-access-token
  3. 有 --> C
  4. 没有 调用 getCrossByInvitationToken 接口
  5. --> C
  6. 根据本地 user-token 和 cross-access-token 、 read-only 判断读写状态

### 没有 xcode
  1. 判断本地是否有 user-token
  2. 有 user-token --> C

### A 微信内
  1. 没有 user-token 则进行 weixin OAuth
  2. 调用内部 OAuth 接口， POST /OAuth/Authenticate?provider=wechat
  3. 跳到微信授权页面，（用户填写信息）
  4. 授权成功，打开活点地图 url
    1. 保存 OAuth 回来的 user-token
    2. --> C
  5. 授权失败/取消授权

