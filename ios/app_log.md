# Log Tool
选用RKLog (包含在RestKit里面)作为我们的Log系统。
##使用方式
将NSLog(…)换成诸如RKLogInfo(…)即可。

    #import <RestKit/RestKit.h>
    
    // NSLog
    NSLog(@"This is log by %@.", @"Apple");
    // RKLog
    RKLogInfo(@"This is log by %@.", @"RKLog");

##日志分级
分为6级

* RKLogCritical
* RKLogError
* RKLogWarning
* RKLogInfo
* RKLogDebug
* RKLogTrace

###Critical
严重错误，一旦出现这个错误，程序终止。
###Error
错误，当前某个操作出现错误。
###Warning
有错误，但是当前操作可以进行。
###Info
提供运行信息
以上是运行时输出的Log种类
###Debug
提供调试信息，比如看变量内容。
###Trace
提供访问信息，比如到达某行代码、进出某个方法。
以上六种是调试版本默认输出的种类

##模块和过滤
RestKit定义了如下模块

* App
* RestKit
* RestKit/CoreData
* RestKit/CoreData/Cache
* Restkit/Network
* RestKit/Network/CoreData
* RestKit/ObjectMapping
* RestKit/Search
* RestKit/Support
* RestKit/Testing
* RestKit/UI

和如下等级

* RKLogLevelOff
* RKLogLevelCritical
* RKLogLevelError
* RKLogLevelWarning
* RKLogLevelInfo
* RKLogLevelDebug
* RKLogLevelTrace

其中RKLogLevelOff用来关闭Log。

除了RKLogLevelOff外，其他都包含更严重级别的信息，比如RKLogLevelWarning表示输出Critical、Error和Waning的Log。

另有定义RKLogLevelDefault，分别对应DEBUG的RKLogLevelTrace（所有Log）和非DEBUG的RKLogLevelInfo(Info及以上级别的Log)。

通过配置RKLogConfigureByName(name, level)来调整每个模块的Log等级。

    RKLogConfigureByName("RestKit/Network", RKLogLevelTrace);
    RKLogConfigureByName("RestKit/CoreData", RKLogLevelDebug);

App本身可以直接指定输出等级

    RKLogSetAppLoggingLevel(RKLogLevelDefault); //App模块按照默认等级输出Log

模块名字支持统配

    RKLogConfigureByName("*", RKLogLevelOff); //所有模块都禁止输出Log
