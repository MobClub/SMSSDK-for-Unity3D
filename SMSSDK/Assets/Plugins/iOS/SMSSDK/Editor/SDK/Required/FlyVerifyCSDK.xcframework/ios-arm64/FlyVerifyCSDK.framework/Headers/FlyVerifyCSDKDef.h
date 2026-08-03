//
//  FlyVerifyCSDKDef.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 2018/8/22.
//  Copyright © 2024年 FlyVerify. All rights reserved.
//

#ifndef FlyVerifyCSDKDef_h
#define FlyVerifyCSDKDef_h
#import <Foundation/Foundation.h>

/**
 *  国际域名类型
 */
typedef NS_ENUM(NSUInteger, FlyVerifyCSDKDomainType){
    /**
     *  默认（大陆域名）
     */
    FlyVerifyCSDKDomainTypeDefault  = 0,
    /**
     *  美国
     */
    FlyVerifyCSDKDomainTypeUS = 1,
    /**
     *  日本
     */
    FlyVerifyCSDKDomainTypeJapan = 2,
};


/**
 *  网络类型
 */
typedef NS_ENUM(NSUInteger, FlyVerifyCNetworkType)
{
    /**
     *  无网咯
     */
    FlyVerifyCNetworkTypeNone         = 0,
    /**
     *  蜂窝网络
     */
    FlyVerifyCNetworkTypeCellular     = 2,
    /**
     *  WIFI
     */
    FlyVerifyCNetworkTypeWifi         = 1,
    /**
     *  2G网络
     */
    FlyVerifyCNetworkTypeCellular2G   = 3,
    /**
     *  3G网络
     */
    FlyVerifyCNetworkTypeCellular3G   = 4,
    /**
     *  4G网络
     */
    FlyVerifyCNetworkTypeCellular4G   = 5,
    /**
     *  5G网络
     */
    FlyVerifyCNetworkTypeCellular5G   = 6,
};


/**
 IP版本

 - FlyVerifyCIPVersion4: IPv4
 - FlyVerifyCIPVersion6: IPv6
 */
typedef NS_ENUM(NSUInteger, FlyVerifyCIPVersion)
{
    FlyVerifyCIPVersion4 = 0,
    FlyVerifyCIPVersion6 = 1,
    FlyVerifyCIPVersionAuto = 2
};

/**
 网络类型

 - FlyVerifyCNetTypeAuto: 自动
 - FlyVerifyCNetTypeWifi: wifi
 - FlyVerifyCNetTypeCell: 蜂窝
 */
typedef NS_ENUM(NSUInteger, FlyVerifyCNetType)
{
    FlyVerifyCNetTypeWifi = 0,
    FlyVerifyCNetTypeCell = 1,
    FlyVerifyCNetTypeAuto = 2
};


#endif /* FlyVerifyCSDKDef_h */
