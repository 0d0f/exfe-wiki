# iOS网络数据层错误处理

## 网络层错误
### 网络错误
以下错误需显示Network error提示。可以显示提醒栏让用户重试。

* NSURLErrorNotConnectedToInternet 网络栈不存在，网络此刻不通
* NSURLErrorNetworkConnectionLost 连接由于网络断开导致 （移动网络很常见）
* NSURLErrorDNSLookupFailed 域名解析失败，（配置不正确的网）
* NSURLErrorCannotFindHost 域名解析失败，（配置不正确的网）
* NSURLErrorCannotConnectToHost 连不上服务器 （配置不正确的网）
* NSURLErrorTimedOut 连接超时（60s），应该是连不上IP（域名解析成功）后的结果，常见于配置不正确的网络、和外部不通的网络［遇到过］
* NSURLErrorCancelled 因为其他错误导致请求取消（可能是在队列里面堆积太久后取消）［遇到过］

### 服务器错误
以下错误需显示Server error提示。可根据情况决定是否显示提醒栏让用户重试。

* NSURLErrorResourceUnavailable 可能等同于404
* NSURLErrorZeroByteResource 返回结果为空
* NSURLErrorBadServerResponse 返回的结果错误，如500
* NSURLErrorHTTPTooManyRedirects 重定向太多次 （服务器配置、网页代码错误）
* NSURLErrorRedirectToNonExistentLocation （服务器配置、网页代码错误）
* NSURLErrorServerCertificateUntrusted 证书错误 （一般不理？有这个错不是服务器配置错误就是客户端连接的url不对）

### 客户端错误
以下错误输出log。

* NSURLErrorBadURL 不合法的url
* NSURLErrorUnsupportedURL 不认识的url


## API 返回错误
API定义了出错的方式

### 2xx 成功
成功，可能需要处理206的情况

* 200 成功
* 206 部分成功

### 3xx 多种情况
* 304 没有修改

### 4xx 客户端错误
根据API和Meta的类型来处理，一般有缺少参数、没有授权等错误，这部分有的是代码错误，有的是用户输入不合理，需要提醒修改，有的则需要直接重试，有的是需要做跟进处理（比如作废token重新登陆）

* 401
* 403
* 404

### 5xx 服务器错误
服务器错误，不建议重试。

* 500 服务器内部错误