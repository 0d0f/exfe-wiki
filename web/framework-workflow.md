# Framework workflow 框架流程

## URL格式
domain/!:cross\_id/:widget?xcode=xxxx&via=identity

## 基本流程
1. URL解析失败显示首页并提示无效链接，结束。    // 首页DOM在framework中
1. 本地已存user\_token
    a. 如果下发isSmith将user加进·X·，成功则加载页面。
    a. 如果下发user\_token则加载页面，此时如果下发的与本地的user相同，更新本地为前者，否则需合并下发user的身份。
    a. 如果下发x\_token与本地的user相同，以user加载页面。
    a. 以本地user调用getCross，成功则加载页面。
1. 若在微信WebKit中则调用OAuth。返回成功进行下列判断，失败显示首页并提示授权失败。
    a. 如果OAuth返回的user\_token与本地的相同user，则更新本地为前者，否则需合并OAuth的user身份。
    a. 如果下发isSmith将OAuth的user加进·X·，成功则加载页面。
    a. 如果下发user\_token则加载页面，此时如果下发的与OAuth的user不同，需合并下发user的身份。
    a. 如果下发x\_token与OAuth的user相同，以OAuth的user加载页面。
    a. 以OAuth的user调用getCross，成功则加载页面。
1. 如果下发isSmith，加载受邀页面。
1. 如果下发x\_token，以浏览身份加载页面。
1. 如果下发user\_token则加载页面。
1. 加载无权访问页面。

### 加载页面
1. 根据URL和参数加载·X·或widget的页面或受邀页面并显示。若加载失败显示首页并提示服务器错，结束。
1. 若需要合并身份，网页版提示合并，移动版直接合并。
1. 开始运行被加载页面。

## ·X·页面框架逻辑
// 根据 user\_token 和 x\_token 、 read\_only 判断读写状态

## RouteX页面框架逻辑
1. 如果是x\_token，跳回·X·页。
1. 开始使用活点地图。