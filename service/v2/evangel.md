EVANGEL设计文档
==============

目的
----

使用统一的接口，可以给不同的渠道发送消息。屏蔽渠道的差异，并简化认证流程

概念
----

 - 渠道

	一个渠道是一个发送消息的通道。

	这个消息一般来说是即刻送到用户手里的（比如短信，push），但也有可能在用户的某个系统里缓存（比如邮件）。EVANGEL并不考虑消息是否真的送达到用户手里，只要送到用户的系统就可以。

	在接口里，渠道通过recipient对象的provider字段来确定。同时会使用recipient对象的authData字段里的数据来做验证。

 - 用户

	用户是收到消息的人或者组织或者系统。

	用户通过Recipient对象来表示：

		{
			"auth_data": {...},
			"tunnel": "...",
			"id": "...",
			"username": "..."
		}

	recipient内属性解释如下：

  	- auth_data：认证数据，对象

		认证数据只保存在recipient对象的auth\_data字段里，对不同类型的认证数据格式不同。认证数据分为几类：OAuth（twitter），OAuth2（facebook，Google），无认证（邮件）。

		使用者可以通过设置渠道接口（见下）来设置某个渠道的认证数据的默认值。比如对于OAuth认证，可以把client\_token和client\_secret设为默认值，这样每次提交发送数据时，auth\_data只需要提供access\_token和access\_secret即可。如果auth\_data依旧提供client\_token或者client\_secret，会覆盖相应的默认值。

		- OAuth认证数据格式：

				{
					"client_token": "...",
					"client_secret": "...",
					"access_token": "...",
					"access_secret": "..."
				}

		- OAuth2认证数据格式：

				{
					"token": "..."
				}

		- 无认证的数据格式留空

	- tunnel：渠道名，字符串

		例子：twitter、facebook、iOS、email

	- id：用户在渠道里的id，字符串

		一般id是一串数字，唯一表识一个渠道中的用户，但也可能有字符出现，比如使用email当作id。用户id不会改变。为了通用，使用字符串。

	- username：用户在渠道里的名字，字符串

		名字一般是由用户自己指定的，一般可以让用户改变名字。比如twitter的screen name就是username而不是id。

 - 消息

	消息是发给用户的一段数据，一般为可直接阅读的文本，也有可能是带有格式的富文本（比如html），或者一段渠道对段可以读取的数据（比如push）。

	消息分为公开消息（public）、私人消息（private）和原始消息（raw）。私人消息是只能由用户读到的消息（比如邮件，twitter direct message），公开消息为与用户相关的人也可以读到的消息（比如twitter tweet），原始消息是一些数据信息，用于一些特殊渠道（比如iOS push消息用于发送给app的一些数据）。

	EVANGEL会优先发送私人消息，如果私人消息无法送达（比如twitter渠道下，用户没有follow发送消息的帐户，无法发送direct message），则发送公共消息。实际使用时，私人消息可以包括一些关于用户的敏感信息，而公共消息则要尽量避免用户的敏感信息，如果有敏感内容，最好通过url转向一个单独的网页，验证用户身份后再显示。

接口
----

目前所有接口使用token验证，以后会改为signature的形式。

 - 设置渠道接口

 	设置某个渠道的默认auth_data。系统发送时，会用发送数据里recipient的auth\_data字段与对应渠道的默认值做合并，覆盖默认值内的同名值，作为发送时真正用于处理的auth\_data。

	 	http://domain/2013-02/tunnel?token=xxxxx

	 	POST
	 	{
	 		"tunnel": "...",
	 		"auth_data": {...}
	 	}
	 	

 - 发送接口

	recipient对象是要发送给用户的信息。private是要发送的私有消息。public是要发送的公开消息。raw是要发送的原始消息。

		http://domain/2013-02/send?token=xxxxxx

		POST
		{
			"recipient": {...},
			"private": "...",
			"public": "...",
			"raw": {...}
		}

 - 数据查询接口

 	查询已发送数量和发送成功的数量。数据用于统计用，不作为发送是否成功的接口。

 	 	http://domain/2013-02/status/{state name}?token=xxxxx GET

 	查询返回具体的查询值，内容由查询的状态决定。

返回值
------

 - 正常

 	http返回码：200

 	返回内容：发送消息在对应通道内的id值。如果是email，是Message ID，如果是twitter，为对应tweet id。有些渠道可能没有返回值。

 - 不可重试错误

	http返回码：4xx

	返回内容：具体错误信息的json字符串。这种错误属于与使用者相关的错误，在不解决发生错误的原因前，始终无法发送，比如身份验证出错，接收者不存在。这种错误在问题解决前不能重试。

 - 可重试错误

	http返回码：5xx

	返回内容：具体错误信息的json字符串。这种错误属于发送中发生的错误，比如网络不通（超时），服务器过载等。在过了一段时间之后可能会恢复，可以过一段时间重试。

支持渠道信息
-----------

 - email

	email需要到amazon aws的ses服务申请开通一个smtp帐号，或者提交要发送的邮箱名代为申请。发送时认证auth\_data如下：

 - twitter

	twitter需要到twitter develop申请client。

 - 短信

 	国内短信需要到短彩网申请帐户，国外短信需要到twilio申请帐户。或者使用公用号码发送。

 - iOS apn push

 	需要有mac develop认证，并取得相应tls证书。

 - Android GCM push

 	需要在android develop申请gcm服务，并取得相应的key。