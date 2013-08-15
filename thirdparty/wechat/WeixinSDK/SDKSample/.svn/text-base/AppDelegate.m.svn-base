//
//  AppDelegate.m
//  ApiClient
//
//  Created by Guangyao Chen on 12-2-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

#import "ViewController.h"
#import "WXApi.h"

@implementation AppDelegate

@synthesize window = _window;
@synthesize viewController = _viewController;

- (void)dealloc
{
    [_window release];
    [_viewController release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        self.viewController = [[[ViewController alloc] initWithNibName:@"ViewController_iPhone" bundle:nil] autorelease];
    } else {
        self.viewController = [[[ViewController alloc] initWithNibName:@"ViewController_iPad" bundle:nil] autorelease];
    }
    self.viewController.delegate = self;
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    
    
    // 1. 向微信注册
    [WXApi registerApp:@"wxd930ea5d5a258f4f"]; 
    

    
    return YES;
}

- (void) viewContent:(WXMediaMessage *) msg
{
    // 3. 显示微信传过来的内容    
    WXAppExtendObject *obj = msg.mediaObject;
    
    NSString *strTitle = [NSString stringWithFormat:@"消息来自微信"];
    NSString *strMsg = [NSString stringWithFormat:@"标题：%@ \n内容：%@ \n附带信息：%@ \n缩略图:%u bytes\n\n", msg.title, msg.description, obj.extInfo, msg.thumbData.length];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    
    [alert show];
    
    [alert release];

}

/*
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    // 2. 处理微信启动本app的请求
    WXAppLaunchData *launchData = [WXApi handleOpenURL:url];
    
    
    if (launchData.launchType == WXAppLaunchTypeUnknown)
    {
        // 不是微信通过url启动app
        return YES;
    }
    else if (launchData.launchType == WXAppLaunchTypeNotSupport)
    {
        // 请求不支持。 微信版本较新。
        return YES;
    }
    else if (launchData.launchType == WXAppLaunchTypeRequestContent)
    {
        

        return YES;
    }
    else if (launchData.launchType == WXAppLaunchTypeSendReturn)
    {
        。 不需要做处理
        return YES;
    }
    else if (launchData.launchType == WXAppLaunchTypeViewContent)
    {
       
             
       
    }
    
    return YES;
}

*/

- (void)doAuth
{
    SendAuthReq* req = [[[SendAuthReq alloc] init] autorelease];
    req.scope = @"username,post_timeline";
    req.state = @"xxx";
    
    [WXApi sendReq:req];
}

-(void) onSentTextMessage:(BOOL) bSent
{
    // 通过微信发送消息后， 返回本App
    
    NSString *strTitle = [NSString stringWithFormat:@"发送结果"];
    NSString *strMsg = [NSString stringWithFormat:@"发送文本消息结果:%u", bSent];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    
    [alert show];
    
    [alert release];

}
-(void) onSentMediaMessage:(BOOL) bSent
{
    // 通过微信发送消息后， 返回本App
    
    NSString *strTitle = [NSString stringWithFormat:@"发送结果"];
    NSString *strMsg = [NSString stringWithFormat:@"发送媒体消息结果:%u", bSent];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    
    [alert show];
    
    [alert release];
}

-(void) onSentAuthRequest:(NSString *) userName accessToken:(NSString *) token expireDate:(NSDate *) expireDate errorMsg:(NSString *) errMsg
{
    
}

-(void) onShowMediaMessage:(WXMediaMessage *) message
{
    // 微信启动， 有消息内容。
    [self viewContent:message];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (alertView.tag == 99)
    {
        GetMessageFromWXResp* resp = [[[GetMessageFromWXResp alloc] init] autorelease];
        resp.text = @"微信要我提供内容， 但我有东西可以提供";
        resp.bText = YES;
        
        [WXApi sendResp:resp];
    }
}

-(void) onRequestAppMessage
{
    // 微信请求App提供内容， 需要app提供内容后使用OnGetTextMessage 或者 OnGetMediaMessage返回
    NSString *strTitle = [NSString stringWithFormat:@"提供内容"];
    NSString *strMsg = [NSString stringWithFormat:@"微信要我提供内容， 但我没东西可以提供"];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    alert.tag = 99;
    [alert show];
    
    [alert release];

}

-(void) onReq:(BaseReq*)req
{
    if([req isKindOfClass:[GetMessageFromWXReq class]])
    {
        [self onRequestAppMessage];
    }
    else if([req isKindOfClass:[ShowMessageFromWXReq class]])
    {
        ShowMessageFromWXReq* temp = (ShowMessageFromWXReq*)req;
        [self onShowMediaMessage:temp.message]; 
    }
    
}

-(void) onResp:(BaseResp*)resp
{
    if([resp isKindOfClass:[SendMessageToWXResp class]])
    {
        NSString *strTitle = [NSString stringWithFormat:@"发送结果"];
        NSString *strMsg = [NSString stringWithFormat:@"发送媒体消息结果:%d", resp.errCode];
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        
        [alert show];
        
        [alert release];
    }
    else if([resp isKindOfClass:[SendAuthResp class]])
    {
        NSString *strTitle = [NSString stringWithFormat:@"Auth结果"];
        NSString *strMsg = [NSString stringWithFormat:@"Auth结果:%d", resp.errCode];
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        
        [alert show];
        
        [alert release];
    }
}


- (void) sendImageContent
{
    // 4. 发送内容给微信
    
    WXMediaMessage *message = [WXMediaMessage message];
    //message.title = @"你不是真正的快乐";
    //message.description = @"五月天<后青春期的诗>";
    [message setThumbImage:[UIImage imageNamed:@"res2.jpg"]];
    
    WXImageObject *ext = [WXImageObject object];
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"res2" ofType:@"jpg"];
    ext.imageData = [NSData dataWithContentsOfFile:filePath] ;
    
//    Byte* pBuffer = (Byte *)malloc(BUFFER_SIZE);
//    memset(pBuffer, 0, BUFFER_SIZE);
//    NSData* data = [NSData dataWithBytes:pBuffer length:BUFFER_SIZE];
//    free(pBuffer);
//    
//    ext.fileData = data;
    
    message.mediaObject = ext;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
    req.bText = NO;
    req.message = message;
    [WXApi sendReq:req];
}

- (void) sendNewsContent 
{
    WXMediaMessage *message = [WXMediaMessage message];
    message.title = @"麦当劳“销售过期食品”其实不是卫生问题";
    message.description = @"3.15晚会播出当晚，麦当劳该店所在辖区的卫生、工商部门就连夜登门调查，并对腾讯财经等媒体公布初步结果；而尽管未接到闭店处罚通知，麦当劳中国总部还是在发布道歉声明后暂停了该店营业。\
    \
    不得不承认，麦当劳“销售过期食品”固然是事实，但这个“过期”仅仅是他们自己定义的过期，普通中国家庭也不会把刚炸出来30分钟的鸡翅拿去扔掉。麦当劳在食品卫生上的严格程度，不仅远远超出了一般国内企业，而且也超出了一般中国民众的心理预期和生活想象。大多数人以前并不知道，麦当劳厨房的食品架上还有计时器，辣鸡翅等大多数食品存放半个小时之后，按规定就应该扔掉。也正因如此，甚至有网友认为央视3.15晚会的曝光是给麦当劳做的软广告。\
    \
    央视视频中反映的情况，除了掉到地上的的食品未经任何处理继续加工显得很过分外，其它的问题都源于麦当劳自己制定的标准远远超出了国内一般快餐店的标准。比如北京市卫生监督所相关负责人介绍，麦当劳内部要求熟菜在70℃环境下保存2小时，是为了保存食品风味，属于企业内部卫生规范。目前的检查结果显示，麦当劳的保温盒温度在93℃，但在这种环境下保存的熟菜即便超过2小时，对公众也没有危害。也就是说麦当劳的一些保持时间标准是基于保持其食品的独特风味的要求，并非食品发生变质可能损害消费者身体健康的标准，麦当劳这家门店超时存放食品的行为，违反的是企业制定的内部标准，并不违反食品安全规定，政府应该依据法律法规来监管食品卫生，而不是按照食品公司自己制定的标准，从这个角度来看，麦当劳在食品卫生上没有责任（除了使用掉在地上的食物）。…[详细]\
    \
    但三里屯麦当劳的行为确实违背了诚信\
    麦当劳的内部卫生规定虽然并未被作为卖点进行宣扬，但洋快餐在中国是便捷和卫生的代名词，却是不争的事实。谁也不是活雷锋，麦当劳制定的严苛内部标准，为的是树立自己的品牌优势，进而在市场定位上取得明显的价格优势，或者说让自己“贵得有理由”。但如果他的员工在执行上不能贯彻这一企业标准，相对于其价格水平而言，就有欺诈和损害消费者权益之嫌，这也是不言而喻的。从这个意义上来说，央视曝光麦当劳的问题并无不妥，麦当劳至少涉嫌消费欺诈，因为它没有向消费者提供它向人们承诺的标准的食品。也就是说，工商部门而非食品卫生监管部门约谈麦当劳，也并非师出无名。";
    [message setThumbImage:[UIImage imageNamed:@"res2.jpg"]];
    
    WXWebpageObject *ext = [WXWebpageObject object];
    ext.webpageUrl = @"http://view.news.qq.com/zt2012/mdl/index.htm";
    
    message.mediaObject = ext;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
    req.bText = NO;
    req.message = message;
    [WXApi sendReq:req];
}

-(void) sendMusicContent
{
    WXMediaMessage *message = [WXMediaMessage message];
    message.title = @"五月天<后青春期的诗>";
    message.description = @"人群中哭着你只想变成透明的颜色\
    你再也不会梦或痛或心动了\
    你已经决定了你已经决定了\
    你静静忍着紧紧把昨天在拳心握着\
    而回忆越是甜就是越伤人\
    越是在手心留下密密麻麻深深浅浅的刀割\
    你不是真正的快乐\
    你的笑只是你穿的保护色\
    你决定不恨了也决定不爱了\
    把你的灵魂关在永远锁上的躯壳\
    这世界笑了于是你合群的一起笑了\
    当生存是规则不是你的选择\
    于是你含着眼泪飘飘荡荡跌跌撞撞地走着\
    你不是真正的快乐\
    你的笑只是你穿的保护色\
    你决定不恨了也决定不爱了\
    把你的灵魂关在永远锁上的躯壳\
    你不是真正的快乐\
    你的伤从不肯完全的愈合\
    我站在你左侧却像隔着银河\
    难道就真的抱着遗憾一直到老了\
    然后才后悔着\
    你不是真正的快乐\
    你的笑只是你穿的保护色\
    你决定不恨了也决定不爱了\
    把你的灵魂关在永远锁上的躯壳\
    你不是真正的快乐\
    你的伤从不肯完全的愈合\
    我站在你左侧却像隔着银河\
    难道就真的抱着遗憾一直到老了\
    你值得真正的快乐\
    你应该脱下你穿的保护色\
    为什么失去了还要被惩罚呢\
    能不能就让悲伤全部结束在此刻\
    重新开始活着";
    [message setThumbImage:[UIImage imageNamed:@"res3.jpg"]];

    
    WXMusicObject *ext = [WXMusicObject object];
    ext.musicUrl = @"http://mp3.baidu.com/j?j=2&url=http%3A%2F%2Fzhangmenshiting2.baidu.com%2Fdata2%2Fmusic%2F265579%2F265579.mp3%3Fxcode%3Df090290cfcbb632279614d12dac32591";
    
    message.mediaObject = ext;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
    req.bText = NO;
    req.message = message;
    [WXApi sendReq:req];
}

-(void) sendVideoContent
{
    WXMediaMessage *message = [WXMediaMessage message];
    message.title = @"步步惊奇";
    message.description = @"只能说胡戈是中国广告界的一朵奇葩！！！这次真的很多人给跪了、、、";
    [message setThumbImage:[UIImage imageNamed:@"res2.jpg"]];
    
    WXVideoObject *ext = [WXVideoObject object];
    ext.videoUrl = @"http://www.tudou.com/programs/view/6vx5h884JHY/?fr=1";
    
    message.mediaObject = ext;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
    req.bText = NO;
    req.message = message;
    [WXApi sendReq:req];
}

- (void) sendTextContent:(NSString*)nsText
{
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
    req.bText = YES;
    req.text = nsText;
    [WXApi sendReq:req];
}

#define BUFFER_SIZE 1024 * 100
- (void) sendAppContent
{
    // 4. 发送内容给微信
    
    WXMediaMessage *message = [WXMediaMessage message];
    message.title = @"这是App消息";
    message.description = @"你看不懂啊， 看不懂啊， 看不懂！";
    [message setThumbImage:[UIImage imageNamed:@"res2.jpg"]];
    
    WXAppExtendObject *ext = [WXAppExtendObject object];
    ext.extInfo = @"<xml>test</xml>";
    
    Byte* pBuffer = (Byte *)malloc(BUFFER_SIZE);
    memset(pBuffer, 0, BUFFER_SIZE);
    NSData* data = [NSData dataWithBytes:pBuffer length:BUFFER_SIZE];
    free(pBuffer);
      
    ext.fileData = data;
    
    message.mediaObject = ext;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
    req.bText = NO;
    req.message = message;
    [WXApi sendReq:req];
}

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    return  [WXApi handleOpenURL:url delegate:self];
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return  [WXApi handleOpenURL:url delegate:self];
}


- (void)applicationWillResignActive:(UIApplication *)application
{
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
     */
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    /*
     Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
     */
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    /*
     Called when the application is about to terminate.
     Save data if appropriate.
     See also applicationDidEnterBackground:.
     */
}

@end
