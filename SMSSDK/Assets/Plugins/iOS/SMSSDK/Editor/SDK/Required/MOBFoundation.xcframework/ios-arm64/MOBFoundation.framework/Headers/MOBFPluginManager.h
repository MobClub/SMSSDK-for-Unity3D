//
//  MOBFPluginManager.h
//  MOBFoundation
//
//  Created by fenghj on 15/6/2.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMOBFPlugin.h"
#import <FlyVerifyCSDK/FlyVerifyCPluginManager.h>

/**
 *  插件创建事件处理
 *
 *  @return 插件对象
 */
typedef id<IMOBFPlugin>(^MOBFPluginConstructHandler) (void);

/**
 *  插件管理器
 */
@interface MOBFPluginManager : FlyVerifyCPluginManager

@end
