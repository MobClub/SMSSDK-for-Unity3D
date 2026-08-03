//
//  FlyVerifyCImageServiceTypeDef.h
//  FlyVerifyCSDK
//
//  Created by fenghj on 15/6/8.
//  Copyright (c) 2015年 FlyVerify. All rights reserved.
//

#ifndef FlyVerifyCSDK_FlyVerifyCImageServiceTypeDef_h
#define FlyVerifyCSDK_FlyVerifyCImageServiceTypeDef_h

#import <UIKit/UIKit.h>


/**
 图片缓存处理
 
 @param imageData 图片的数据
 */
typedef NSData* (^FlyVerifyCImageGetterCacheHandler)(NSData *imageData);

/**
 *  图片加载返回
 *
 *  @param image 图片对象
 *  @param error 错误信息
 */
typedef void (^FlyVerifyCImageGetterResultHandler)(UIImage *image, NSError *error);

/**
 *  图片加载返回
 *
 *  @param imageData 图片数据
 *  @param error 错误信息
 */
typedef void (^FlyVerifyCImageDataGetterResultHandler)(NSData *imageData, NSError *error);

#endif
