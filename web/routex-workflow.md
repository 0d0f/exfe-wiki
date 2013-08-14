活点地图流程
------------
## Routex url 形式

  * 没带 xcode          /!:cross_id/routex
  * 带 xcode            /!:cross_id/routex?xcode=xxxx

## 流程

### 有 xcode
  1. 有 xcode，调用 getCrossByInvitationToken 接口
  2. --> C
  3. 根据本地 user-token 和 cross-access-token 、 read-only 判断读写状态

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
  5. 授权失败

### B 微信外

### C 进入活点地图

