//
//  MOBFApplicationUtils.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-20.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCApplication.h>

/**
 *  应用工具类
 */
@interface MOBFApplication : FlyVerifyCApplication

/**
 *  检测是否启用ATS功能
 */
+ (BOOL)enabledATS;

@end
