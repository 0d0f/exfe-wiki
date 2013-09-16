# iOS URL 
## Description
用来支持通过URI直接打开App的功能。根据用户user_id以及token可能触发身份合并或者重新登陆。

举例：

    exfe:///?user_id=233&username=moew&token=b049787660161c912407e6b3a0de42647d515858592b54a1e1741e08a116e49a

根据URL的结构，分成Scheme host path parameters 4部分单独定义。

## 设计原则：

1. 兼容Android，比如[URI](http://developer.android.com/reference/java/net/URI.html)，[Intent Filter](http://developer.android.com/guide/topics/manifest/intent-filter-element.html)
2. 和[Web的路由](/web/router.html)尽量统一
3. 权限和资源分离，权限部分用参数赖表示登陆等信息，资源用Path描述，两者正交。

## <a id="index"></a>Index
* [Scheme](#scheme)
* [Host](#host)
* [Path](path)
	* [Cross List](#crosses)
	* [Cross](#cross)
	* [Conversation](#conversation)
	* [Exfee](#exfee)
	* [routex](#routex)
	* [Gather](#gather)
	* [Profile](#profile)
	* [Identity](#identity)
	* [Keep Current screen](#inplace)
* [Parameters](#parameters)
	* [user_id](#user_id)
	* [token](#token)
	* [username](#username)
	* [identity_id](#identity_id)
* [Sample](#sample)

## <a id="scheme"></a>Scheme
目前注册的Scheme是exfe://，测试版本则使用black://(0d0f 黑盒)和panda://(pilot Panda)。

考虑到将来需要弃用exfe，因此在未来某个时间会切换到使用shuady，并有一段过渡期，在过渡期内两者同时使用，因此目前代码解析上对此不做限定和依赖。

    exfe://abc/
    black://abc/
    panda://abc/
    
    shuady://abc/

## <a id="host"></a>Host
iOS支持空Host，需要支持服务器的区分，cn表示国内服务器，zz和com表示全球服务器（默认服务器），空白视为默认服务器。

目前假设host部分不包含"."，如果包含"."，则留作未来扩展，比如最右侧的点之后来表示服务器，但目前不作处理。

    exfe://zz/
    
    shuady://cn/

##<a id="path"></a>Path
### <a id="crosses"></a>Cross List
直接打开Cross List界面

    /

备注：其他不认识和解析失败的Path都进入到Cross List界面(草案)

[^Index](#index)

### <a id="cross"></a>Cross
直接打开CrossID为%CROSS_ID%的Cross Detail界面

    /!%CROSS_ID%

[^Index](#index)

### <a id="conversation"></a>Conversation
直接打开CrossID为%CROSS_ID%的Cross Conversation界面

    /!%CROSS_ID%/conversation

[^Index](#index)

### <a id="exfee"></a>Exfee
直接打开CrossID为%CROSS_ID%的Cross Exfee界面

    /!%CROSS_ID%/exfee

[^Index](#index)

### <a id="routex"></a>Routex
直接打开CrossID为%CROSS_ID%的Cross Routex界面

    /!%CROSS_ID%/routex

[^Index](#index)

### <a id="gather"></a>Gather
直接打开Gather界面

    /gather

其他(草案)

    /gather/place
    /gather/time
    /gather/title
    /gather/description

[^Index](#index)

### <a id="profile"></a>Profile
直接打开Profile界面

    /profile

[^Index](#index)

### <a id="identity"></a>Identity
直接打开Profile界面

    /%IDENTITY_ID%

[^Index](#index)
### <a id="inplace"></a>Keep Current screen (草案)
保持当前界面不跳转

    (空)

[^Index](#index)

## <a id="parameters"></a>Parameters
### <a id="user_id"></a>user_id
用来标示登陆的用户信息，必选。

* 如果没有登陆，则用user_id作为登陆用户，token直接作为权限，来使用，并处理跳转逻辑。
* 如果已经登陆，user_id相同，不做额外动作，处理跳转逻辑。
* 如果已经登陆，user_id不同，走合并身份并更换token，然后处理跳转逻辑
* 如果user_id和toke同时没有，可以单独进行跳转逻辑处理。

### <a id="token"></a>token
授权的token，必选。使用场景参考[user_id](#user_id)

### <a id="username"></a>username
用户名称，必选。用来在合并的时候给予提示，由于调用者并不知道是否会合并，因此该选项必须有

### <a id="identity_id"></a>identity_id (Optional)
用来标示更改的身份信息，不是每个调用都有，一般用于Profile的更新或者添加Identity，可选。
[^Index](#index)

## <a id="Sample"></a>Sample
* 纯路径
<table>
  <tr>
    <th>URL for world wide</th>
    <th>URL for cn</th>
    <th>跳转到</th>
  </tr>
  <tr>
    <td>exfe://zz</td>
    <td>shuady://cn</td>
    <td>当前界面</td>
  </tr>
  <tr>
    <td>exfe://zz/</td>
    <td>shuady://cn/</td>
    <td>Cross List界面</td>
  </tr>
  <tr>
    <td>exfe://zz/profile</td>
    <td>shuady://cn/profile</td>
    <td>User Profile界面</td>
  </tr>
  <tr>
    <td>exfe://zz/gather</td>
    <td>shuady://cn/gather</td>
    <td>Gather界面</td>
  </tr>
  <tr>
    <td>exfe://zz/!100233</td>
    <td>shuady://cn/!100233</td>
    <td>Cross界面，这个Cross的id是100233</td>
  </tr>
  <tr>
    <td>exfe://zz/!100233/cross</td>
    <td>shuady://cn/!100233/cross</td>
    <td>Cross界面的cross Widget(默认)，这个Cross的id是100233</td>
  </tr>
  <tr>
    <td>exfe://zz/!100233/exfee</td>
    <td>shuady://cn/!100233/exfee</td>
    <td>Cross界面的exfee Widget，这个Cross的id是100233</td>
  </tr>
  <tr>
    <td>exfe://zz/!100233/conversation</td>
    <td>shuady://cn/!100233/conversation</td>
    <td>Cross界面的conversation Widget，这个Cross的id是100233</td>
  </tr>
  <tr>
    <td>exfe://zz/!100233/&lt;WIDGET_NAME></td>
    <td>shuady://cn/!100233/&lt;WIDGET_NAME></td>
    <td>Cross界面的&lt;WIDGET_NAME> Widget，这个Cross的id是100233，如果&lt;WIDGET_NAME>不认识，则进入默认界面，同exfe:///!100233</td>
  </tr>
</table>

* 包含参数

打开用user_id为233，用token登陆/合并后，跳转到100233的Cross界面：

    exfe://zz/!100233?user_id=233&username=moew&token=b049787660161c912407e6b3a0de42647d515858592b54a1e1741e08a116e49a
    
[^Index](#index)


