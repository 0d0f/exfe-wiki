//
//  ViewController.m
//  ApiClient
//
//  Created by Guangyao Chen on 12-2-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

@synthesize delegate = _delegate;
@synthesize m_nsLastText;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)sendAppContent
{
    if (_delegate)
    {
        [_delegate sendAppContent];
    }
}

-(void) onCancelText
{
    [self dismissModalViewControllerAnimated:YES];
}

-(void) onCompleteText:(NSString*)nsText
{
    [self dismissModalViewControllerAnimated:YES];
    self.m_nsLastText = nsText;
    if (_delegate)
    {
        [_delegate sendTextContent:m_nsLastText] ;
    }
}

- (void)sendTextContent
{
    TextViewController* viewController = [[[TextViewController alloc] init] autorelease];
    viewController.m_delegate = self;
    viewController.m_nsLastText = m_nsLastText;
    
    
    UINavigationController *navigatitonController = [[[UINavigationController alloc]initWithRootViewController:viewController] autorelease];
	[self presentModalViewController:navigatitonController animated:YES];
}
- (void)sendImageContent
{
    if (_delegate)
    {
        [_delegate sendImageContent];
    }
}
- (void)sendMusicContent
{
    if (_delegate)
    {
        [_delegate sendMusicContent] ;
    }
}
- (void)sendVideoContent
{
    if (_delegate)
    {
        [_delegate sendVideoContent] ;
    }
}
- (void)sendNewsContent
{
    if (_delegate)
    {
        [_delegate sendNewsContent] ;
    }
}

- (void)doOAuth
{
    if (_delegate)
    {
        [_delegate doAuth];
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn setTitle:@"发送文本消息给微信" forState:UIControlStateNormal];
    [btn setFrame:CGRectMake(80, 20, 150, 40)];
    
    [btn addTarget:self action:@selector(sendTextContent) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:btn];
    
    UIButton *btn2 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn2 setTitle:@"发送Photo消息给微信" forState:UIControlStateNormal];
    [btn2 setFrame:CGRectMake(80, 60, 150, 40)];
    [btn2 addTarget:self action:@selector(sendImageContent) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn2];
    
    
    UIButton *btn3 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn3 setTitle:@"发送Music消息给微信" forState:UIControlStateNormal];
    [btn3 setFrame:CGRectMake(80, 100, 150, 40)];
    [btn3 addTarget:self action:@selector(sendMusicContent) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn3];
    
    
    UIButton *btn4 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn4 setTitle:@"发送News消息给微信" forState:UIControlStateNormal];
    [btn4 setFrame:CGRectMake(80, 140, 150, 40)];
    [btn4 addTarget:self action:@selector(sendNewsContent) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn4];    
    
    
    UIButton *btn5 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn5 setTitle:@"发送Video消息给微信" forState:UIControlStateNormal];
    [btn5 setFrame:CGRectMake(80, 180, 150, 40)];
    [btn5 addTarget:self action:@selector(sendVideoContent) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn5];
    
    UIButton *btn6 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn6 setTitle:@"发送App消息给微信" forState:UIControlStateNormal];
    [btn6 setFrame:CGRectMake(80, 220, 150, 40)];
    [btn6 addTarget:self action:@selector(sendAppContent) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn6];
    
    UIButton *btn7 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [btn7 setTitle:@"OAuth" forState:UIControlStateNormal];
    [btn7 setFrame:CGRectMake(80, 260, 150, 40)];
    [btn7 addTarget:self action:@selector(doOAuth) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn7];
    
    m_nsLastText = @"完善的跨终端即时通讯能力，使得Mac可以与PC、手机、Pad等终端的QQ进行无缝沟通，让您的交流更畅快。 完善的跨终端即时通讯能力，使得Mac可以与PC、手机、Pad等终端的QQ进行无缝沟通，让您的交流更畅快。 ";
    
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    self.m_nsLastText = nil;
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

@end
