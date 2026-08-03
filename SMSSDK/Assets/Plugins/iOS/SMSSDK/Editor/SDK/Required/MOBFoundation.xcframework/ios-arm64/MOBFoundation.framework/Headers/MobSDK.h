//
//  MobSDK.h
//  MOBFoundation
//
//  Created by liyc on 17/2/23.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyC.h>

/**
 MobSDK
 */
@interface MobSDK : FlyVerifyC

/**
 获取应用标识
 
 @return 应用标识
 */
+ (NSString * _Nullable)appKey;

/**
 获取应用密钥

 @return 应用密钥
 */
+ (NSString * _Nullable)appSecret;


/**
 注册appKey、appSecret

 @param appKey appKey
 @param appSecret appSecret 可以为空
 */
+ (void)registerAppKey:(NSString * _Nonnull)appKey
             appSecret:(NSString * _Nullable)appSecret;

/**
 注册appKey、appSecret

 @param appKey appKey
 @param appSecret appSecret 可以为空
 @param privacyLevel 隐私协议级别(需要同意一次=2,不需要同意=0,建议使用2,避免政策变动，功能不可用)
 */
+ (void)registerAppKey:(NSString * _Nonnull)appKey
             appSecret:(NSString * _Nullable)appSecret
          privacyLevel:(int)level;

/**
 注册appKey、appSecret

 @param appKey appKey
 @param appSecret appSecret 可以为空
 @param privacyLevel 隐私协议级别(需要同意一次=2,不需要同意=0,建议使用2,避免政策变动，功能不可用)
 @param force 强制https

 */
+ (void)registerAppKey:(NSString * _Nonnull)appKey
             appSecret:(NSString * _Nullable)appSecret
          privacyLevel:(int)level
            forceHttps:(BOOL)force;

@end
