#无线网络和代理
## 连接无线网络

* SSID: 0d0f
* Pwd: gatherx0    

### 自动翻墙代理
* 连上无线网络(SSID:0d0f) 或者 有线网络
* 开启自动代理发现功能。

#### Mac
MAC下查询WI-FI的开启状态

    $networksetup -getproxyautodiscovery WI-FI
    Auto Proxy Discovery: Off

开关WI-FI的自动代理发现功能
    
    $sudo networksetup -setproxyautodiscovery WI-FI [on|off]
    
这里WI-FI可以替换成其他网络接口。
#### Win
(待完成)
#### *nix
(待完成)
#### iOS
WLan设置中，进入0d0f的详细设置，代理选择Auto
#### Android
参考手动设置代理部分

##手动配置代理
### 代理

####Proxy1:

    Domain: panda.0d0f.com    
    Port: 8964    
    Type: SOCKS5    


####Proxy2:    

    Domain: panda.0d0f.com    
    Port: 6489    
    Type: HTTP


### PAC
####PAC URL: 
   
    http://free.0d0f.com/
    http://wpad/wpad.dat

