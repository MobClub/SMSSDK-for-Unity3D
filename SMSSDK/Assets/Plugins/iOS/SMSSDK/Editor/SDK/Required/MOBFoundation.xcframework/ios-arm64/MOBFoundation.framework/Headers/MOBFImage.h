//
//  MOBFImageUtils.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-19.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FlyVerifyCSDK/FlyVerifyCImage.h>

/**
 *  圆角类型
 */
typedef NS_ENUM(NSUInteger, MOBFOvalType)
{
    /**
     *  无圆角
     */
    MOBFOvalTypeNone = 0x00,
    /**
     *  左上角
     */
    MOBFOvalTypeLeftTop = 0x01,
    /**
     *  左下角
     */
    MOBFOvalTypeLeftBottom = 0x02,
    /**
     *  右上角
     */
    MOBFOvalTypeRightTop = 0x04,
    /**
     *  右下角
     */
    MOBFOvalTypeRightBottom = 0x08,
    /**
     *  全部
     */
    MOBFOvalTypeAll = MOBFOvalTypeLeftTop | MOBFOvalTypeLeftBottom | MOBFOvalTypeRightTop | MOBFOvalTypeRightBottom
};

/**
 *  图像工具类
 */
@interface MOBFImage : FlyVerifyCImage

@end
