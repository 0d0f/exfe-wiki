
obile Web Performance - 移动端性能优化
----------------------

## Linode & ENV

    Server:         lighttpd/1.4.28
    X-Powered-By:   PHP/5.5.1-1~precise+1

## CLI 终端

### curl

    # Mobile
    time curl -A'Mozilla/5.0 (iPhone; CPU iPhone OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3' https://exfe.com

    # 0
    real  0m1.355s
    user  0m0.037s
    sys   0m0.009s

    # 1
    real  0m1.351s
    user  0m0.037s
    sys   0m0.009s

    # 2
    real  0m1.365s
    user  0m0.037s
    sys   0m0.010s

    # 3
    real  0m1.333s
    user  0m0.036s
    sys   0m0.011s

    # 4
    real  0m1.339s
    user  0m0.039s
    sys   0m0.010s

    # x5 avg:
    real  1.34s
    user  0.0372s
    sys   0.0098s

### phantomjs

    # user-agent: mobile

    phantomjs netsniff.js https://exfe.com > exfe/m0.har

    yslow -i basic --format plain exfe/m0.har

    size: 72.8K (72872 bytes)
    overall score: A (94)
    url: https://exfe.com/
    # of requests: 4
    ruleset: ydefault
    page load time: 2167


    phantomjs netsniff.js 'https://exfe.com/#!token=9496dbc23cf293d7dfad8445a5753b2e/routex' > exfe/m1.har

    yslow -i basic --format plain exfe/m1.har

    size: 274.7K (274784 bytes)
    overall score: B (87)
    url: https://exfe.com/#!token=9496dbc23cf293d7dfad8445a5753b2e/routex
    # of requests: 9
    ruleset: ydefault
    page load time: 5374


## Static Resources

以下设置服务器没有开启（只针对 css js images 文件, css 有开启 gzip )

* gzip
* cache-control
* expires

### Images


### CSS


### JS


### HTTP 请求



## Performance

### 静态文件

  * gzip cache-control expires
  * 单独域名 (例如: static.exfe.com)
  * no-cookies
  * 启用 http, 放弃 https ? (待测试验证 [http vs https][])

  * 图片
    - 优化压缩
    - 去除空图链接

  * CSS
    - add top
    - 优化精简 css

  * JS
    - add bottom


### 根据业务优化加载流程

  * 合并 mobiledirector 和 exfemobile => exfemobile
  * 根据路由分拆文件
  * 先加载 core 文件
  * 根据 matched route, 异步加载其业务逻辑代码

### Offline Application Cache


## Links

* [Async Attribute][]
* [Defer Attribute][]
* [Make the Web Faster][]
* [Best Practices for Speeding Up Your Web Site][]
* [http vs https][]

[Async Attribute]: http://caniuse.com/#search=async
[Defer Attribute]: http://caniuse.com/#search=defer
[Make the Web Faster]: https://developers.google.com/speed/
[Best Practices for Speeding Up Your Web Site]: http://developer.yahoo.com/performance/rules.html
[http vs https]: http://stackoverflow.com/questions/149274/http-vs-https-performance
