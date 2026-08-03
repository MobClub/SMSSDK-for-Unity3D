//
//  FlyVerifyCTagService.h
//  FlyVerifyCSDK
//
//  Created by liyc on 2017/10/27.
//  Copyright © 2017年 flyverify. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  错误消息类型
 */
typedef NS_ENUM(NSUInteger, FlyVerifyCErrorTagMsgType){
    /*
     *  标签为空
     */
    FlyVerifyCErrorTagMsgTypeGetTagEmpty          = 109996,
    /*
     *  获取标签失败
     */
    FlyVerifyCErrorTagMsgTypeGetTagFailed         = 109997,
    /**
     *  上传标签超出字符限制
     */
    FlyVerifyCErrorTagMsgTypeCharacterLimitError  = 109998,
    /**
     *  上传无效参数
     */
    FlyVerifyCErrorTagMsgTypeInvalidParamError    = 109999,
};

@interface FlyVerifyCTagService : NSObject

/**
 上传标记我的用户

 @param tags   用户信息
 @param result 回调信息
 */
+ (void)tagUserUpload:(NSDictionary *)tags
              result:(void (^)(NSError *error))result;

/**
 获取标签

 @param handler 回调
 */
+ (void)userTags:(void (^) (NSDictionary *userTags, NSError *error))handler;

/**
 上传位置信息

 @param accuracy 精度
 @param latitude 纬度
 @param longitude 经度
 @param tag 完整地理信息JSON数据
 @param result 回调信息
 */
+ (void)uploadLocation:(CGFloat)accuracy
              latitude:(CGFloat)latitude
             longitude:(CGFloat)longitude
                   tag:(NSDictionary *)tag
                result:(void (^)(NSError *error))result;

@end
