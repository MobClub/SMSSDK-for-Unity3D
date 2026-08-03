//
//  MOBFCore.h
//  MOBFoundation
//
//  Created by fenghj on 15/8/31.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCNotificationCenter.h>

/**
 *  应用程序崩溃通知
 */
extern NSString *const MOBFApplicationCrashNotif;

/**
 *  核心对象
 */
@interface MOBFNotificationCenter : FlyVerifyCNotificationCenter

@end
