# 更改列表
<hr></hr>

## Version 2.2.1
### Publish Date: 2013/9/??

### 功能/Feature
* 支持切换服务器(全球／中国)
* 更新TabBar

### 错误修正/Fix bugs
* 修正相对时间翻译
* 修正残留未翻译
* 汉化rome
* 调整Verification Account的文本样式

### 整理代码和重构
* Push跳转字段解析更新，支持区分服务器
* URL跳转支持自动选择服务器登陆
* 增加Shuady和所有Target对应的Test目标

<hr></hr>

## Version 2.2.0
### Publish Date: 2013/9/7

### 功能/Feature

* 添加活点地图
* 添加后台上报地理位置支持
* 界面支持URL跳转* 汉化，支持中文* 加入微信SDK和微信Provider的支持* Profile头像图片支持PNG，JPG系数是0.6### 错误修正/Fix bugs* 修复地图点击当前选中的点crash### 整理代码和重构* Push数据解析结构调整* 重写刷新Cross List的时间戳控制机制* 调整Cross/Exfee相关操作的调用方式和回调处理，支持重试* 调整Cross Frame和Tab Widget之间的关系* 合并Merge Identity为1步，调整Merge后的拉数据顺序* 将数据获取和拉取网络数据统一到Model上的接口。* 最低部署版本升级到6.0* 更换Log系统为RKLog

<hr></hr>

## Version 2.1.6

### 功能/Feature

* 删除通知身份
* 冷启动时注册设备
* 增加可以重复的网络操作机制，以及一个错误提示的流程(修改用户名字和bio)

### 功能细节修正

####Profile Edit:

* 调整进入界面的条件
* 修正只读界面限制
* 更换界面进入的方式（从下弹出更改为从右进入）
* 照片备份到手机相册
* 限制空名字的提交
* 提交的图片由JPEG更改为PNG
* 更改修改状态的退出监测方式，从图片区域tap到图片区域的任意触摸
* 移除Place关于任意触摸监测的无用代码
* 加载大图片的时候引入等待指示符号
* 调整图片显示策略
* 调整截图策略，并支持透明通道

### 界面修正
* 调整有新版本提示的文字

### 错误修正/Fix bugs
* 修正provider匹配的正则，修复了手机号码无法登陆／注册的问题
* 修正Server的500错误的匹配条件

### 整理代码和重构
* 整理Util文件
* 升级RestKit到v.20.3，调整RestKit的路径
* 更换flurry到4.2.3
