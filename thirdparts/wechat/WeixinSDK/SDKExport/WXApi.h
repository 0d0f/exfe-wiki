//
//  MMApi.h
//  ApiClient
//
//  Created by Guangyao Chen on 12-2-28.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "WXApiObject.h"

#pragma mark - 
@protocol WXApiDelegate <NSObject>

@optional
/*
 *收到一个来自微信的请求，处理完后调用sendResp
 *req是自动释放的
 */
-(void) onReq:(BaseReq*)req;
/*
 *发送一个sendReq后，收到微信的回应
 *resp是自动释放的
 */
-(void) onResp:(BaseResp*)resp;


@end


#pragma mark -

/*
 * 微信Api接口函数
 */
@interface WXApi : NSObject

/*
 * 向微信注册App信息
 * app启动后(例如在：didFinishLaunchingWithOptions)向微信注册信息，注册成功后在微信App列表中将显示此App图标.
 */
+(BOOL) registerApp:(NSString *) appid;

/*
 * 处理微信通过URL启动App时， 传递的数据
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用
 */
+(BOOL) handleOpenURL:(NSURL *) url delegate:(id<WXApiDelegate>) delegate;

/*
 * 检查微信是否已被用户安装
 */
+(BOOL) isWXAppInstalled;

/*
 * 微信版本是否支持api操作
 */
+(BOOL) isWXAppSupportApi;

/*
 * 得到微信的itunes安装地址
 */
+(NSString *) getWXAppInstallUrl;

/*
 * 打开微信
 */
//+(BOOL) returnWXApp;

+(BOOL) openWXApp;

/*
 *发送请求到微信,等待微信返回onResp
 *req调用函数后，请自己释放
 */
+(BOOL) sendReq:(BaseReq*)req;

/*
 *收到微信onReq的请求，发送对应的应答给微信，并切换到微信界面
 *resp调用函数后，请自己释放
 */
+(BOOL) sendResp:(BaseResp*)resp;



@end