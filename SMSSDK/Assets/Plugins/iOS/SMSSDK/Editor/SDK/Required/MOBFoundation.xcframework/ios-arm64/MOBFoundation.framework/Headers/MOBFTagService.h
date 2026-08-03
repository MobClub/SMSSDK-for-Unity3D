//
//  MOBFTagService.h
//  MOBFoundation
//
//  Created by liyc on 2017/10/27.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCTagService.h>

/**
 *  错误消息类型
 */
typedef NS_ENUM(NSUInteger, MOBFErrorTagMsgType){
    /*
     *  标签为空
     */
    MOBFErrorTagMsgTypeGetTagEmpty          = 109996,
    /*
     *  获取标签失败
     */
    MOBFErrorTagMsgTypeGetTagFailed         = 109997,
    /**
     *  上传标签超出字符限制
     */
    MOBFErrorTagMsgTypeCharacterLimitError  = 109998,
    /**
     *  上传无效参数
     */
    MOBFErrorTagMsgTypeInvalidParamError    = 109999,
};

@interface MOBFTagService : FlyVerifyCTagService

@end
