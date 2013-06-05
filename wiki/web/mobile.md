Mobile
------

## Redirecting

## Home

### Cross
  1. 请求 API `GetCrossByInvitationToken`, 获取 cross data
  2. 如果返回数据有带 token, 则使用 { token, user_id } 跳到 app
  3. 显示 cross 页面

### SMS-Token
  1. 获取 head.meta 中的 sms token
  2. 更具 token.action 走 `Set Password` or `Verify`

### Set Password
  0. 如果没有 SMS-Token, 请求 API `resolveToken`
  1. sms-token 或者 resolveToken { token, user_id, identity_id }
  2. 显示 set-password 页
  3. 请求 API resetpassword
  3. 设置成功，换回 authorization = { token, user_id }
  4. 使用 authorization 跳转到 app

### Verify
  0. 如果没有 SMS-Token, 请求 API `resolveToken`
  1. sms-token 或者 resolveToken { token, user_id, identity_id }
  2. 显示 verify 页面
  3. 使用 resolveToken 跳转到 app

### Invalid
  1. 如果 ajax 失败, token 失效，或者 meta.code !== 200
  2. 跳到首页(/)
  3. 弹出错误提示窗口

### Open EXFE app (未完成)
  1. 点击 `Open EXFE app` 按钮
  2. 尝试跳 EXFE.app
  3. 上一步如果失败，尝试跳 itunes EXFE.app 
