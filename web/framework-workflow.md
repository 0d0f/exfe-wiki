·X·页框架流程
------------
## URL形式

domain/!:cross_id/:widget?xcode=xxxx&via=identity

## 基本流程
1. if (WebKit = 微信)
    1. if (user_token)
        1. if (isSmith) inviteExfee(user_id);       #isSmith服务器已给
        1. if (未获得cross数据) call getCross(user_token);       #需要服务器修改优化
        1. 如果已获得cross数据，根据URL判断加载X页或widget，开始执行js。
    1. call OAuth()
        1. 如果OAuth返回的user_token与本地user_token不同则合并身份？
        1. if (已获得cross数据) inviteExfee(user_id);
        1. 如果已获得cross数据，根据URL判断加载X页或widget，开始执行js。
        1. 显示invalid link页面，结束。
    1. 显示提示页面告知用户必须需同意OAuth
        1. if (isSmith) 可以允许用户输入手机邮箱。
        1. 结束。
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

