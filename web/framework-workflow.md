# Framework workflow 框架流程

## URL格式
domain/!:cross\_id/:widget?xcode=xxxx&via=identity

## 基本流程
1. url解析失败显示invalid link页，结束。
1. 在微信WebKit中
    a. 本地已有user\_token且isSmith时，添加当前user进·X·。成功则根据URL加载·X·或widget并开始执行js。
    a. 调用微信内OAuth，并保存返回的user\_token
        1. 如果返回的user\_token与本地不同user则合并身份。        // 此步待定
        1. 当isSmith时将user下的微信（或首选）身份加到·X·中。成功则根据URL加载·X·或widget并开始执行js。
        1. getCrossByInvitationToken，若返回user\_token则将微信身份合并，并根据URL加载·X·或widget并开始执行js。
        1. 显示无权访问页面，可进行request access。
    a. 显示活点地图受邀页面。当isSmith时可让用户输入手机邮箱验证。
    a. 结束。
1. 调用getCrossByInvitationToken，成功返回进行下列判断。
    a. 返回user\_token且与本地user\_token不属同一user，则合并身份。
    a. 返回user\_token且与本地user\_token同属相同user，则更新user\_token。
    a. 返回cross\_access\_token且与本地user\_token不属同一user，则根据URL加载·X·或widget，以浏览身份开始执行js。
    a. 返回cross\_access\_token且与本地user\_token同属相同user，则根据URL加载·X·或widget，以本地user开始执行js。
    a. 当isSmith时显示加入·X·或widget的页面并开始执行js。
1. 使用本地user\_token或·X·\_access\_token调用getCross接口，成功则根据URL加载·X·或widget并开始执行js。
1. 显示无权访问页面，可进行request access。

##·X·页面框架逻辑
// 根据 user\_token 和 cross\_access\_token 、 read\_only 判断读写状态

## RouteX页面框架逻辑
// 加入RouteX页面
