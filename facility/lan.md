# 局域网配置
* 网络段: 10.2.33.0
* 子网掩码: 255.255.255.0 /24
* 网关: 10.2.33.1
* DNS: 10.2.33.1
* DHCP Server: 10.2.33.1

[Wifi和代理](proxy.md)

## 静态主机
#### 工作
<table>
	<tr>
		<th>MAC</th>
		<th>Host</th>
		<th>IP</th>
	</tr>
	<tr>
		<td>00:25:00:D1:78:AC</td>
		<td>white</td>
		<td>10.2.33.88</td>
	</tr>
	<tr>
		<td>00:E0:4C:E0:57:DF</td>
		<td>black</td>
		<td>10.2.33.100</td>
	</tr>
	<tr>
		<td>D4:BE:D9:9B:B7:36</td>
		<td>panda</td>
		<td>10.2.33.89</td>
	</tr>
	<tr>
		<td>B8:27:EB:34:DE:64</td>
		<td>FloraPi</td>
		<td>10.2.33.253</td>
	</tr>
	<tr>
		<td>00:8A:8D:8A:68:84</td>
		<td>cfd</td>
		<td>10.2.33.37</td>
	</tr>
</table> 
### 私人
(略)
## 域名

	# Local Address
	#address=/white.0d0f.com/10.2.33.88
	address=/.white.0d0f.com/10.2.33.88
	#address=/panda.0d0f.com/10.2.33.89
	address=/.panda.0d0f.com/wiki.0d0f.com/free.0d0f.com/git.0d0f.com/wpad.0d0f.com/app.0d0f.com/10.2.33.89
	#address=/black.0d0f.com/10.2.33.100
	address=/0d0f.com/api.0d0f.com/img.0d0f.com/10.2.33.100
	address=/router.0d0f.com/e3000.0d0f.com/dns.0d0f.com/10.2.33.1
	address=/leask.0d0f.com/10.2.33.254
	#address=/wezone.0d0f.com/10.2.33.2
	address=/wrh54g.0d0f.com/10.2.33.5
	address=/m20.0d0f.com/10.2.33.7
	address=/m20g.0d0f.com/10.2.33.9
	address=/wpad/10.2.33.89
	#address=/cfd.0d0f.com/10.2.33.37
	address=/.cfd.0d0f.com/10.2.33.37
	address=/.master.cfd.0d0f.com/10.2.33.37
	# Proxy 
	#dhcp-option=hotspot,252,http://free.0d0f.com/

## 路由器
###[主路由器](http://10.2.33.1/)

#### 中继路由器1
~.3
#### 中继路由器2
~.5
#### 中继路由器3
~.9
## 交换机



