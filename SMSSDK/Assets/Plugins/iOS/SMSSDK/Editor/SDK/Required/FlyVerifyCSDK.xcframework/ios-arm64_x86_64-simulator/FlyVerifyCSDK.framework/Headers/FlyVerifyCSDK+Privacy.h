//
//  FlyVerifyCSDK+Privacy.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 2020/1/21.
//  Copyright © 2020 FlyVerify. All rights reserved.
//

#import <FlyVerifyCSDK/FlyVerifyC.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#ifndef FlyVerifyC_Privacy_h
#define FlyVerifyC_Privacy_h

//隐私数据配置代理
@protocol FlyVerifyCPrivacyDelegate <NSObject>

@optional

/**
 用于判断是否允许SDK主动采集经纬度信息

 @return YES表示可以主动采集经纬度信息，NO表示不可以，默认为YES
 */
- (BOOL)isLocInfoEnable;

/**
 APP提供经纬度信息
 当SDK被拒绝主动采集经纬度信息后(isLocInfoEnable返回NO)，会通过此方法向App请求经纬度信息
 
 @return 经纬度信息,如果返回 nil 则表示不提供地理位置信息,默认为nil
 */
- (CLLocation* _Nullable)getLoc;

/**
 用于判断是否允许SDK主动采集wifi信息

 @return YES表示可以主动采集wifi信息，NO表示不可以，默认为YES
 */
- (BOOL)isWiFiInfoEnable;

/**
 APP提供wifi地址信息
 当SDK被拒绝主动采集wifi地址信息后(isWiFiInfoEnable返回NO)，会通过此方法向App请求wifi地址信息
 
 @return wifi名称信息,如果返回 nil 则表示不提供wifi地址信息,默认为nil
 */
- (NSString* _Nullable)getBSSID;

/**
 APP提供wifi名称信息
 当SDK被拒绝主动采集wifi名称信息后(isWiFiInfoEnable返回NO)，会通过此方法向App请求wifi名称信息
 
 @return wifi名称信息,如果返回 nil 则表示不提供wifi名称信息,默认为nil
 */
- (NSString* _Nullable)getSSID;

/**
 用于判断是否允许SDK主动采集idfv信息

 @return YES表示SDK可以主动采集idfv信息，NO表示不可以，默认为YES
 */
- (BOOL)isIdfvEnable;

/**
 APP提供idfv信息
 当SDK被拒绝主动采集idfv信息后(isIdfvEnable返回NO)，会通过此方法向App请求idfv信息
 
 @return idfa信息,如果返回 nil 则表示不提供idfv信息,默认为nil
 */
- (NSString* _Nullable)getIdfv;

/**
 用于判断是否允许SDK主动采集idfa信息

 @return YES表示SDK可以主动采集idfa信息，NO表示不可以，默认为YES
 */
- (BOOL)isIdfaEnable;

/**
 APP提供 idfa 信息
 当SDK被拒绝主动采集 idfa 信息后(isIdfaEnable返回NO)，会通过此方法向App请求idfa信息
 
 @return idfa信息,如果返回nil则表示不提供idfa信息,默认为nil
 */
- (NSString* _Nullable)getIdfa;

/**
 用于判断是否允许SDK主动采集ip信息
 
 @return YES表示SDK可以主动采集ip信息，NO表示不可以，默认为YES
 */
- (BOOL)isIpEnable;

/**
 APP提供 蜂窝 ipv4 信息
 当SDK被拒绝主动采集 蜂窝 ipv4 信息后(isIpEnable返回NO)，会通过此方法向App请求 蜂窝 ipv4 信息
 
 @return 蜂窝 ipv4信息,如果返回nil则表示不提供蜂窝ipv4信息,默认为nil
 */
- (NSString* _Nullable)getCellIpv4;

/**
 APP提供 蜂窝ipv6 信息
 当SDK被拒绝主动采集 蜂窝ipv6 信息后(isIpEnable返回NO)，会通过此方法向App请求蜂窝ipv6信息
 
 @return 蜂窝ipv6信息,如果返回nil则表示不提供蜂窝ipv6信息,默认为nil
 */
- (NSString* _Nullable)getCellIpv6;

/**
 APP提供 wifi ipv4 信息
 当SDK被拒绝主动采集 wifi ipv4 信息后(isIpEnable返回NO)，会通过此方法向App请求蜂窝wifi ipv4信息
 
 @return wifi ipv4 信息,如果返回nil则表示不提供 wifi ipv4 信息,默认为nil
 */
- (NSString* _Nullable)getWifiIpv4;

/**
 APP提供 wifi ipv6 信息
 当SDK被拒绝主动采集 wifi ipv6 信息后(isIpEnable返回NO)，会通过此方法向App请求蜂窝wifi ipv6信息
 
 @return wifi ipv6 信息,如果返回nil则表示不提供 wifi ipv6 信息,默认为nil
 */
- (NSString* _Nullable)getWifiIpv6;

/**
 APP提供 所有 ipv4, ipv6 信息
 当SDK被拒绝主动采集 ipv4, ipv6 信息后(isIpEnable返回NO)，会通过此方法向App请求 所有ipv4, ipv6信息
 
 @return ipv4, ipv6 信息,如果返回nil则表示不提供 ipv4, ipv6 信息,默认为nil
 */
- (NSDictionary* _Nullable)getIpInfoAll;


/**
 用于判断是否允许SDK主动采集社交平台信息

 @return YES表示SDK可以自行采集社交平台信息，NO表示不可以，默认为YES
 */
- (BOOL)isSocietyPlatformDataEnable;

/**
 用于判断是否允许SDK主动采集设备网络信息

 @return YES表示SDK可以自行采集设备网络信息，NO表示不可以，默认为YES
 */
- (BOOL)isDeviceNetInfoEnable;

/**
 APP提供 网络类型 信息
 当SDK被拒绝主动采集 网络类型 信息后(isDeviceNetInfoEnable返回NO)，会通过此方法向App请求网络类型 信息
 
 
 @return 网络类型 信息,如果返回nil则表示不提供网络类型 信息,默认为none
 */
- (FlyVerifyCNetworkType)getCurrentNetworkType;

/**
 APP提供 蜂窝网络类型 信息
 当SDK被拒绝主动采集 蜂窝网络类型 信息后(isDeviceNetInfoEnable返回NO)，会通过此方法向App请求 蜂窝网络类型 信息
 
 
 @return 蜂窝网络类型 信息,如果返回nil则表示不提供 蜂窝网络类型 信息,默认为nil
 */
- (NSString* _Nullable)getCurrentRadioAccessTechnology;

/**
 APP提供 运营商名称 信息
 当SDK被拒绝主动采集 运营商名称 信息后(isDeviceNetInfoEnable返回NO)，会通过此方法向App请求运营商名称 信息
 
 @return 运营商名称 信息,如果返回nil则表示不提供 运营商名称 信息,
 */
- (NSString* _Nullable)getCarrierName;

/**
 APP提供 运营商国家码 信息
 当SDK被拒绝主动采集 运营商国家码 信息后(isDeviceNetInfoEnable返回NO)，会通过此方法向App请求 运营商国家码 信息
 
 @return 运营商国家码 信息,如果返回nil则表示不提供 运营商国家码 信息,
 */
- (NSString* _Nullable)getMobileCountryCode;

/**
 APP提供 运营商网络编号 信息
 当SDK被拒绝主动采集 运营商网络编号 信息后(isDeviceNetInfoEnable返回NO)，会通过此方法向App请求 运营商网络编号 信息
 
 @return 运营商网络编号 信息,如果返回nil则表示不提供 运营商网络编号 信息,
 */
- (NSString* _Nullable)getMobileNetworkCode;


/**
用于判断是否允许SDK主动采集分辨率信息

@return YES表示SDK可以自行采集分辨率信息，NO表示不可以，默认为YES
*/
- (BOOL)isScreenInfoEnable;

/**
 APP提供 分辨率 信息
 当SDK被拒绝主动采集 分辨率 信息后(isScreenInfoEnable返回NO)，会通过此方法向App请求分辨率信息
 
 @return 分辨率信息
 */
- (CGSize)getScreenSize;


- (BOOL)kbiAtAir;
@end


@interface FlyVerifyC (Privacy)


/**
 获取用户隐私协议
 
 @param type 协议类型 (1= url类型, 2=  富文本类型)
 @param result 返回回调（data：字典类型 title=标题,content=内容(type=1，返回url,type = 2时返回富文本)       error:详细错误信息）
 */
+ (void)getPrivacyPolicy:(NSString * _Nullable)type
             compeletion:(void (^ _Nullable)(NSDictionary * _Nullable data,NSError * _Nullable error))result DEPRECATED_MSG_ATTRIBUTE("use -[getPrivacyPolicy:language:compeletion:] method instead.");

/**
 获取用户隐私协议
 
 @param type 协议类型 (1= url类型, 2=  富文本类型)
 @param language 隐私协议支持语言（）
 @param result 返回回调（data：字典类型 title=标题,content=内容(type=1，返回url,type = 2时返回富文本)       error:详细错误信息）
 */
+ (void)getPrivacyPolicy:(NSString * _Nullable)type
                language:(NSString * _Nullable)language
             compeletion:(void (^ _Nullable)(NSDictionary * _Nullable data,NSError * _Nullable error))result DEPRECATED_MSG_ATTRIBUTE("deprecated");

/**
 同意隐私授权
 @param isAgree 是否同意（用户授权后的结果）
 @param handler 回掉
 */
+ (void)agreePrivacy:(BOOL)isAgree onResult:(void (^_Nullable)(BOOL success))handler;

/**
 同意隐私授权
 @param isAgree 是否同意（用户授权后的结果）
 @param privacyDataDelegate 隐私数据配置
 @param handler 回掉
 */
+ (void)agreePrivacy:(BOOL)isAgree
                  privacyDataDelegate:(id<FlyVerifyCPrivacyDelegate> _Nullable)privacyDataDelegate
                             onResult:(void (^_Nullable)(BOOL success))handler;

/**
 设置隐私数据代理
 1.如果调用的agreePrivacy:privacyDataDelegate:onResult:中设置过privacyDataDelegate，
 就不用再调用setPrivacyDataDelegate:方法
 2.如果没有调用过agreePrivacy:privacyDataDelegate:onResult:.
 先调用setPrivacyDataDelegate:方法，再调agreePrivacy:onResult:
 3.也可以单独调用setPrivacyDataDelegate:方法

 @param privacyDataDelegate 隐私数据配置
 
 */
+(void)setPrivacyDataDelegate:(id<FlyVerifyCPrivacyDelegate> _Nullable)privacyDataDelegate;

/**
 设置是否允许弹窗
 @param show 是否允许展示隐私协议二次弹窗（最好设置为YES，否则可能会导致部分功能无法使用，默认为YES）
 */
+ (void)setAllowShowPrivacyWindow:(BOOL)show  DEPRECATED_MSG_ATTRIBUTE("deprecated");

/**
 设置隐私协议弹窗色调
 @param backColor 弹窗背景色调
 @param colors 弹窗按钮色调数组（首个元素为拒绝按钮色调，第二个元素为同意按钮色调）
 */
+ (void)setPrivacyBackgroundColor:(UIColor *_Nullable)backColor
             operationButtonColor:(NSArray <UIColor *>*_Nullable)colors  DEPRECATED_MSG_ATTRIBUTE("deprecated");

@end


#endif /* FlyVerifyC_Privacy_h */
