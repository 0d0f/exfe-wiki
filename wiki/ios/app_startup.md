#App Start Up

冷起动(didFinishLaunchingWithOptions)


  1. 设置flurry初始化信息
  2. 设置RestKit的Log级别 D
  3. 打印API URL D
  4. 启动清理工作，删除废弃的用户文件夹
  
  --以上是通用工作，以下是用户相关的--
  
  5. 根据保存登录的user_id来创建Model，必要时创建对应的用户文件夹，并标记废弃用户文件夹
  6. 设置AFNetwork的网络指示属性
  7. 请求APN token，如果需要的话
  8. 创建界面的导航浏览控制器和第一个界面xlist控制器
  9. 处理Push进来的数据
  10. 显示开发版本 D
  11. 挂载通知监听
  12. 如果登录的话，请求一次当前用户的Profile
  13. 请求一次随机背景的列表

切换从后台进入界面(applicationWillEnterForeground)


  1. 刷新一次Cross List

进入激活(applicationDidBecomeActive)


  1. 清空badge数字
  2. fb调用
  3. 检查版本更新

处理push和url跳转
(待定)