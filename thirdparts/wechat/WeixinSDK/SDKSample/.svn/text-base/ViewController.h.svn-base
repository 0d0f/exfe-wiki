//
//  ViewController.h
//  ApiClient
//
//  Created by Guangyao Chen on 12-2-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TextViewController.h"

@protocol viewDelegate <NSObject>
- (void) sendTextContent:(NSString*)nsText;
- (void) sendAppContent;
- (void) sendImageContent;
- (void) sendNewsContent ; 
- (void) sendMusicContent ; 
- (void) sendVideoContent ; 
- (void) doAuth;
@end

@interface ViewController : UIViewController < TextViewControllerDelegate >
{
    NSString* m_nsLastText;
}

@property (nonatomic, assign) id<viewDelegate> delegate;
@property (nonatomic, retain) NSString* m_nsLastText;

@end
