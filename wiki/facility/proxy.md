## 自动翻墙代理
* 连上无线网络(SSID:0d0f) 或者 有线网络
* 开启自动代理发现功能：

MAC下查询WI-FI的开启状态
<pre>
$networksetup -getproxyautodiscovery WI-FI
Auto Proxy Discovery: Off
</pre>
开关WI-FI的自动代理发现功能
<pre>
$ sudo networksetup -setproxyautodiscovery WI-FI [on|off]
</pre>
这里WI-FI可以替换成其他网络接口。

## 连接无线网络
<pre>
SSID: 0d0f
Pwd: (hidden)
</pre>

## 代理
<pre>
Proxy:
Domain: panda.0d0f.com
Port: 8964
Type: SOCKS5
</pre>

## PAC
<pre>
PAC URL: http://http://wpad/wpad.dat 
</pre>

