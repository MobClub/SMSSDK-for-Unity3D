//
//  FlyVerifyCImageUtils.h
//  FlyVerifyCSDK
//
//  Created by flyverify on 15-1-19.
//  Copyright (c) 2015年 FlyVerify. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  圆角类型
 */
typedef NS_ENUM(NSUInteger, FlyVerifyCOvalType)
{
    /**
     *  无圆角
     */
    FlyVerifyCOvalTypeNone = 0x00,
    /**
     *  左上角
     */
    FlyVerifyCOvalTypeLeftTop = 0x01,
    /**
     *  左下角
     */
    FlyVerifyCOvalTypeLeftBottom = 0x02,
    /**
     *  右上角
     */
    FlyVerifyCOvalTypeRightTop = 0x04,
    /**
     *  右下角
     */
    FlyVerifyCOvalTypeRightBottom = 0x08,
    /**
     *  全部
     */
    FlyVerifyCOvalTypeAll = FlyVerifyCOvalTypeLeftTop | FlyVerifyCOvalTypeLeftBottom | FlyVerifyCOvalTypeRightTop | FlyVerifyCOvalTypeRightBottom
};

/**
 *  图像工具类
 */
@interface FlyVerifyCImage : NSObject

/**
 *  裁剪图片
 *
 *  @param image 原始图片
 *  @param rect  裁剪范围
 *
 *  @return 裁剪后图片
 */
+ (UIImage *)clipImage:(UIImage *)image withRect:(CGRect)rect;

/**
 *  将图片边角裁剪为圆角
 *
 *  @param image      原始图片
 *  @param size       图像尺寸
 *  @param ovalWidth  圆角宽度
 *  @param ovalHeight 圆角高度
 *  @param ovalType   圆角类型
 *
 *  @return 裁剪后图像
 */
+ (UIImage *)roundRectImage:(UIImage *)image
                   withSize:(CGSize)size
                  ovalWidth:(CGFloat)ovalWidth
                 ovalHeight:(CGFloat)ovalHeight
                   ovalType:(FlyVerifyCOvalType)ovalType;

/**
 *  等比缩放图片
 *
 *  @param image 原始图片
 *  @param size  缩放的图片尺寸
 *
 *  @return 缩放后图片
 */
+ (UIImage *)scaleImage:(UIImage *)image withSize:(CGSize)size;

/**
 *  获取图片对象
 *
 *  @param name   图片名称
 *  @param bundle 资源包对象
 *
 *  @return 图片对象
 */
+ (UIImage *)imageName:(NSString *)name bundle:(NSBundle *)bundle;

/**
 *  通过指定视图生成图片
 *
 *  @param view 视图对象
 *
 *  @return 图片对象
 */
+ (UIImage *)imageByView:(UIView *)view;

/**
 *  通过制定视图生成图片
 *
 *  @param view   视图对象
 *  @param opaque 是否为不透明图片，YES，不透明，NO，透明
 *
 *  @return 图片对象
 */
+ (UIImage *)imageByView:(UIView *)view opaque:(BOOL)opaque;

/**
 *  通过指定window生成图片
 *
 *  @param window window
 *
 *  @return 图片对象
 */
+ (UIImage *)imageWithWindow:(UIWindow*)window;

/**
 *  屏幕图片-需要主线程访问
 *
 *  @return 图片对象
 */
+ (UIImage *)getScreenHotImage;
@end
