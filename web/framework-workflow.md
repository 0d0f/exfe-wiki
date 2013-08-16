# Framework workflow 框架流程

## URL格式
domain/!:cross\_id/:widget?xcode=xxxx&via=identity

## 基本流程
1. 在微信WebKit中
    a. 本地已有user\_token
        1. 当isSmith时将user下的微信（或首选）身份加到cross中。
        1. getCross(user\_token)，成功则根据URL加载cross或widget并开始执行js。
    a. 调用微信内OAuth，并保存返回的user\_token
        1. 如果返回的user\_token与本地不同则合并身份。        // 此步待定
        1. 当isSmith时将user下的微信（或首选）身份加到cross中。
        1. getCross(user\_token)，成功则根据URL加载cross或widget并开始执行js。
        1. getCrossByInvitationToken，若返回user\_token则将微信身份合并，并根据URL加载cross或widget并开始执行js。
        1. 显示invalid link页，结束。
    a. 显示活点地图受邀页面。当isSmith时可让用户输入手机邮箱验证。
    a. 结束。
1. 本地已有cross\_access\_token
    a. 返回user\_token
    a. 返回cross\_access\_token，
    a. 
    a. //浏览身份相关逻辑
    a. 根据URL加载cross或widget并开始执行js。
1. 本地已有user-token
    a. getCross(user\_token)，成功则根据URL加载cross或widget并开始执行js。
    a. //合并身份逻辑
    a. 
1. // 当isSmith时加入cross
1. // request access
1. // invalid link

##·X·页面框架逻辑
// 根据 user-token 和 cross-access-token 、 read-only 判断读写状态

## RouteX页面框架逻辑
// 加入RouteX页面
