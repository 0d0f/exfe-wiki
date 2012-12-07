## dev 上的 vpn

cd /usr/local/etc/openvpn/usvpn/;openvpn --config /usr/local/etc/openvpn/usvpn/huoju.conf --script-security 2

## 网站上线规范

*大家一起来完善以及维护一份网站的上线规范吧。*

### 一、关于数据结构变动。

# 所有的数据结构变动脚本都放在doc/upgrade_db_script/目录下面，同时以时间戳标记其先后。
# 每次更新完数据结构，都把数据结构变更脚本删除，同时导出一份最新的数据结构。

### 服务器配置变化

## URL

[URL Rules](Url-rules)

## API v2

[api_document]

[api_test]

[Human Date Time 主要逻辑]

[ios_push_msg|iOS Push消息格式]

[android_device_id|Android 身份相关]

[cross_updated]

[exfe service]

[gobus 接口]
