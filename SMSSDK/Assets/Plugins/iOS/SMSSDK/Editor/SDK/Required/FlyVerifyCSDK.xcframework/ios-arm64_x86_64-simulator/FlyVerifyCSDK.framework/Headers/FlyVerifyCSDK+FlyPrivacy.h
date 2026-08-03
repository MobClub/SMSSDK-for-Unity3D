//
//  FlyVerifyCSDK+Privacy.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 2020/1/21.
//  Copyright © 2020 FlyVerify. All rights reserved.
//

#import <FlyVerifyCSDK/FlyVerifyCSDK+Privacy.h>

#ifndef FlyVerifyC_FlyPrivacy_h
#define FlyVerifyC_FlyPrivacy_h

//隐私数据配置代理
@protocol FlyVerifyCPrivacyFlyDelegate <FlyVerifyCPrivacyDelegate>

@optional

/**
 用于判断是否允许SDK主动采集手机型号信息

 @return YES表示可以主动采集手机型号信息，NO表示不可以，默认为YES
 */
- (BOOL)isModelAvailable;

/**
 APP提供手机型号信息
 当SDK被拒绝主动采集手机型号信息后(isModelAvailable返回NO)，会通过此方法向App请求手机型号信息
 
 @return 手机型号信息,如果返回 nil 则表示不提供手机型号信息,默认为nil
 */
- (NSString* _Nullable)getModel;

/**
 用于判断是否允许SDK主动采集系统信息

 @return YES表示可以主动采集系统信息，NO表示不可以，默认为YES
 */
- (BOOL)isSystemInfoAvailable;

/**
 APP提供系统版本名称信息
 当SDK被拒绝主动采集系统信息后(isSystemInfoAvailable返回NO)，会通过此方法向App请求版本名称信息
 
 @return 版本名称信息,如果返回 nil 则表示不提供版本名称信息,默认为nil
 */
- (NSString* _Nullable)getSystemVersionName;


@end


@interface FlyVerifyC (FlyPrivacy)

/**
 同意隐私授权
 @param isAgree 是否同意（用户授权后的结果）
 @param privacyDataFlyDelegate 隐私数据配置
 @param handler 回掉
 */
+ (void)agreePrivacy:(BOOL)isAgree
                privacyDataFlyDelegate:(id<FlyVerifyCPrivacyFlyDelegate> _Nullable)privacyDataFlyDelegate
                             onResult:(void (^_Nullable)(BOOL success))handler;

/**
 设置隐私数据代理
 1.如果调用的agreePrivacy:privacyDataFlyDelegate:onResult:中设置过privacyDataDelegate，
 就不用再调用setPrivacyDataFlyDelegate:方法
 2.如果没有调用过agreePrivacy:privacyDataFlyDelegate:onResult:.
 先调用setPrivacyDataDelegate:方法，再调agreePrivacy:onResult:
 3.也可以单独调用setPrivacyDataFlyDelegate:方法

 @param privacyDataDelegate 隐私数据配置
 
 */
+(void)setPrivacyDataFlyDelegate:(id<FlyVerifyCPrivacyFlyDelegate> _Nullable)privacyDataDelegate;


@end


#endif /* FlyVerifyC_FlyPrivacy_h */
