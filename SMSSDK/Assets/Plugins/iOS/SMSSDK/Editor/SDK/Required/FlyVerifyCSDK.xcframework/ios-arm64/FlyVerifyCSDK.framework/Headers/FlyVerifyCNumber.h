//
//  FlyVerifyCNumberUtils.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 15-1-20.
//  Copyright (c) 2015年 FlyVerify. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  数值工具类
 */
@interface FlyVerifyCNumber : NSObject

/**
 *  获取随机整型值
 *
 *  @param max 最大随机数
 *
 *  @return 随机整数
 */
+ (NSInteger)randomInteger:(NSInteger)max;

@end
