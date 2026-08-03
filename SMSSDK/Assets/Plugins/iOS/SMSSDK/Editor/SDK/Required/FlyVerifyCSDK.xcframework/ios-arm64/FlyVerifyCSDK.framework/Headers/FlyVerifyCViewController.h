//
//  FlyVerifyCViewControllerUtils.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 15-1-19.
//  Copyright (c) 2015年 FlyVerify. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  视图控制器工具类
 */
@interface FlyVerifyCViewController : NSObject

/**
 *  获取当前视图控制器
 *
 *  @return 视图控制器
 */
+ (UIViewController *)currentViewController;

/**
 *  获取当前视图控制器
 *
 *  @param window 窗口
 *
 *  @return 视图控制器
 */
+ (UIViewController *)currentViewControllerFromWindow:(UIWindow *)window;

@end
