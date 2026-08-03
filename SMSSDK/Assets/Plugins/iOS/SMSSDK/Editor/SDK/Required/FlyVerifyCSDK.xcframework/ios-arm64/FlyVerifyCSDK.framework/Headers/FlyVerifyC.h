//
//  FlyVerifyC.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 17/2/23.
//  Copyright © 2017年 FlyVerify. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCSDKDef.h>

/**
 FlyVerifyC
 */
@interface FlyVerifyC : NSObject

/**
 获取版本号

 @return 版本号
 */
+ (NSString * _Nonnull)version;

/**
 获取应用标识
 
 @return 应用标识
 */
+ (NSString * _Nullable)flyVerifyKey;

/**
 获取应用密钥

 @return 应用密钥
 */
+ (NSString * _Nullable)flyVerifySecret;

/**
 获取当前国际域名

 @return 域名
 */
+ (NSString *_Nullable)getInternationalDomain;

/**
 设置国际域名

 @param domainType 域名类型
 */
+ (void)setInternationalDomain:(FlyVerifyCSDKDomainType)domainType;

/**
 变更应用密钥，针对服务器刷新应用密钥后，可以通过该方法进行修改

 @param appSecret 应用密钥 可以为空
 */
+ (void)changeAppSecret:(NSString * _Nullable)appSecret;

/**
 初始化key、secret

 @param key key
 @param secret secret 可以为空
 */
+ (void)initKey:(NSString * _Nonnull)key
         secret:(NSString * _Nullable)secret;

/**
 注册key、secret

 @param key key
 @param secret secret 可以为空
 @param level 隐私协议级别(需要同意一次=2,不需要同意=0,建议使用2,避免政策变动，功能不可用)
 */
+ (void)initKey:(NSString * _Nonnull)key
         secret:(NSString * _Nullable)secret
   privacyLevel:(int)level;

/**
 注册key、secret

 @param key key
 @param secret secret 可以为空
 @param level 隐私协议级别(需要同意一次=2,不需要同意=0,建议使用2,避免政策变动，功能不可用)
 @param force 强制https

 */
+ (void)initKey:(NSString * _Nonnull)key
         secret:(NSString * _Nullable)secret
   privacyLevel:(int)level
     forceHttps:(BOOL)force;

/**
 强制https
 
 @param force 是否强制https
 */
+ (void)forceHttps:(BOOL)force;

/**
 强制ipv6
 
 @param force 是否强制ipv6
 */
+ (void)forceIpv6:(BOOL)force;


/**
 设置隐私等级
 
 @param level 隐私协议级别(需要同意一次=2,不需要同意=0,建议使用2,避免政策变动，功能不可用)
 */
+ (void)setPrivacyLevel:(int)level;

#pragma mark - User


/**
 设置用户

 @param uid 用户标识，对应应用自身用户系统的用户唯一标志，不一定是实际的用户ID，可以通过数据变换的方式（如：MD5（userID））来生成该ID，但一定要能够唯一标识用户。设置nil表示注销用户，解除绑定
 @param nickname 昵称
 @param avatar 头像
 @param userData 用户自定义数据
 */
+ (void)setUserWithUid:(NSString * _Nullable)uid
              nickName:(NSString * _Nullable)nickname
                avatar:(NSString * _Nullable)avatar
              userData:(NSDictionary * _Nullable)userData;

/**
 设置用户
 
 @param uid 用户ID 用户标识，对应应用自身用户系统的用户唯一标志，不一定是实际的用户ID，可以通过数据变换的方式（如：MD5（userID））来生成该ID，但一定要能够唯一标识用户。设置nil表示注销用户，解除绑定
 @param nickname 昵称
 @param avatar 头像
 @param sign 签名
 @param userData 用户自定义数据
 */
+ (void)setUserWithUid:(NSString * _Nullable)uid
              nickName:(NSString * _Nullable)nickname
                avatar:(NSString * _Nullable)avatar
                  sign:(NSString * _Nullable)sign
              userData:(NSDictionary * _Nullable)userData;


/**
 清空用户
 */
+ (void)clearUser;

/**
 是否允许crash捕捉
 */
+ (void)enableCatchCrash:(BOOL)enable;

/**
 是否允许crash处理时，暂时线程环境
 */
+ (void)enableCrashSuspendThreads:(BOOL)enable;

/**
 是否允许crash处理时，rasise 信号
 */
+ (void)enableCrashRaiseSig:(BOOL)enable;

@end
