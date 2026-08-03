//
//  MOBFLogService.h
//  MOBFoundation
//
//  Created by 冯鸿杰 on 17/2/16.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCLogService.h>


/**
 日志服务协议
 */
@protocol MOBFLogServiceDelegate <FlyVerifyCLogServiceDelegate>

@end

/**
 日志服务
 */
@interface MOBFLogService : FlyVerifyCLogService

@end
