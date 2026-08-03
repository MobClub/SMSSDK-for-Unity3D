//
//  MobSDK+Privacy.h
//  MOBFoundation
//
//  Created by liyc on 2020/1/21.
//  Copyright © 2020 MOB. All rights reserved.
//

#import <MOBFoundation/MobSDK.h>
#import <FlyVerifyCSDK/FlyVerifyCSDK+Privacy.h>

#ifndef MobSDK_Privacy_h
#define MobSDK_Privacy_h

//隐私数据配置代理
@protocol MOBFoundationPrivacyDelegate <FlyVerifyCPrivacyDelegate>

@end


@interface MobSDK (Privacy)
/**
 上传隐私协议授权状态
 @param isAgree 是否同意（用户授权后的结果）
 @param handler 回掉
 */
+ (void)uploadPrivacyPermissionStatus:(BOOL)isAgree
                             onResult:(void (^_Nullable)(BOOL success))handler;

/**
 上传隐私协议授权状态
 @param isAgree 是否同意（用户授权后的结果）
 @param privacyDataDelegate 隐私数据配置
 @param handler 回掉
 */
+ (void)uploadPrivacyPermissionStatus:(BOOL)isAgree
                  privacyDataDelegate:(id<MOBFoundationPrivacyDelegate> _Nullable)privacyDataDelegate
                             onResult:(void (^_Nullable)(BOOL success))handler;
@end


#endif /* MobSDK_Privacy_h */
