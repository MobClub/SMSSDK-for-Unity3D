//
//  MOBFHttpService.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-20.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCHttpService.h>


@class MOBFHttpService;

/**
 *  GET方式
 */
extern NSString *const kMOBFHttpMethodGet;

/**
 *  POST方式
 */
extern NSString *const kMOBFHttpMethodPost;

/**
 *  DELETE方式
 */
extern NSString *const kMOBFHttpMethodDelete;

/**
 *  HEAD方式
 */
extern NSString *const kMOBFHttpMethodHead;

/**
 *  HTTP返回事件
 *
 *  @param response     回复对象
 *  @param responseData 回复数据
 */
typedef void(^MOBFHttpResultEvent) (NSHTTPURLResponse *response, NSData *responseData);

/**
 *  HTTP错误事件
 *
 *  @param error 错误信息
 */
typedef void(^MOBFHttpFaultEvent) (NSError *error);

/**
 *  HTTP上传数据事件
 *
 *  @param totalBytes  总字节数
 *  @param loadedBytes 上传字节数据
 */
typedef void(^MOBFHttpUploadProgressEvent) (int64_t totalBytes, int64_t loadedBytes);

/**
 *  HTTP下载数据事件
 *
 *  @param totalBytes  总字节数
 *  @param loadedBytes 上传字节数据
 */
typedef void(^MOBFHttpDownloadProgressEvent) (int64_t totalBytes, int64_t loadedBytes);

/**
 *  HTTP服务类
 */
@interface MOBFHttpService : FlyVerifyCHttpService

@end
