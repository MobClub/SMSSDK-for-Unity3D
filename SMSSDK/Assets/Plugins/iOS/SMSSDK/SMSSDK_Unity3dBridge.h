//
//  SMSSDK_Unity3DBridge.h
//  SMSSDK_Unity3DBridge
//
//  Created by JunJie Pang on 16/8/1.
//  Copyright © 2016年 liys. All rights reserved.
//

#import <Foundation/Foundation.h>

#if defined (__cplusplus)
extern "C" {
#endif
    
    extern void __iosGetversion (void *observer);
    extern void __iosGetsupportedcountrycode (void *observer);
    extern void __iosGetcode (int method, void * phoneNumber, void * zone, void * tmpCode, void *observer);
    extern void __iosCommitcode (void * phoneNumber, void * zone, void * code, void *observer);
    extern void __iosSubmitpolicygrantresult (BOOL isAgree, void *observer);

#if defined (__cplusplus)
}
#endif

@interface SMSSDK_Unity3DBridge : NSObject

@end
    
