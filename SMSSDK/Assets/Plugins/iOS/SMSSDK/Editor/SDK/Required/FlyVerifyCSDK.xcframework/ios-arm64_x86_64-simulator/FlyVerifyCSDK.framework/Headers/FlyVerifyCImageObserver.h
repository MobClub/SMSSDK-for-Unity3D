//
//  FlyVerifyCImageObserver.h
//  FlyVerifyCSDK
//
//  Created by fenghj on 16/1/21.
//  Copyright © 2016年 FlyVerify. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  图片观察者
 */
@interface FlyVerifyCImageObserver : NSObject

/**
 *  图片链接
 */
@property (nonatomic, strong, readonly) NSURL *url;

@end
