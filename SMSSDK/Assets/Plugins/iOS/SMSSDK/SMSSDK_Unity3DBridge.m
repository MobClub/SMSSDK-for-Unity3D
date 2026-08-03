
//
//  SMSSDK_Unity3DBridge.m
//  SMSSDK_Unity3DBridge
//
//  Created by JunJie Pang on 16/8/1.
//  Copyright © 2016年 liys. All rights reserved.
//

#import "SMSSDK_Unity3dBridge.h"

#import <SMS_SDK/SMSSDK.h>
#import <MOBFoundation/MOBFoundation.h>
#import <MOBFoundation/MobSDK+Privacy.h>

#if defined (__cplusplus)
extern "C" {
#endif

    void __iosGetversion (void *observer)
	{
        if (observer)
        {
            NSMutableDictionary *resultDic = [NSMutableDictionary dictionaryWithCapacity:3];
            [resultDic setObject:[NSNumber numberWithInt:6]
                          forKey:@"action"];
            NSString *observerStr = [NSString stringWithCString:observer
                                                       encoding:NSUTF8StringEncoding];
            [resultDic setObject:[NSNumber numberWithInt:1]
                          forKey:@"status"];

            NSString *versionString = [SMSSDK sdkVersion];
            [resultDic setObject:versionString forKey:@"res"];
            NSString *resultString = [MOBFJson jsonStringFromObject:resultDic];
            UnitySendMessage([observerStr UTF8String], "_callBack", [resultString UTF8String]);
        }
	}

    void __iosGetsupportedcountrycode (void *observer)
	{
        if (observer)
        {
            NSString *observerStr = [NSString stringWithCString:observer
                                                       encoding:NSUTF8StringEncoding];
            [SMSSDK getCountryZone:^(NSError *error, NSArray *zonesArray) {
                NSMutableDictionary *resultDic = [NSMutableDictionary dictionaryWithCapacity:3];
                [resultDic setObject:[NSNumber numberWithInt:3] forKey:@"action"];

                if (!error)
                {
                    NSString *zoneString = [MOBFJson jsonStringFromObject:zonesArray];
                    [resultDic setObject:[NSNumber numberWithInt:1]
                                  forKey:@"status"];
                    [resultDic setObject:zoneString
                                  forKey:@"res"];
                    NSString *resultString = [MOBFJson jsonStringFromObject:resultDic];
                    //转化回到JSONString的状
                    UnitySendMessage([observerStr UTF8String], "_callBack", [resultString UTF8String]);
                }
                else
                {
                    NSMutableDictionary * resultErrorMsg =[NSMutableDictionary dictionaryWithObjectsAndKeys:@(error.code),
                                                           @"code",
                                                           error.domain,
                                                           @"domain",
                                                           error.userInfo,
                                                           @"userInfo",
                                                           nil];
                    [resultDic setObject:[NSNumber numberWithInt:2] forKey:@"status"];
                    NSString *resultMsg = [MOBFJson jsonStringFromObject:resultErrorMsg];
                    [resultDic setObject:resultMsg forKey:@"res"];

                    //转化回到JSONString的状态码
                    NSString *resultStr = [MOBFJson jsonStringFromObject:resultDic];
                    UnitySendMessage([observerStr UTF8String], "_callBack", [resultStr UTF8String]);
                }
            }];

        }
	}

    void __iosGetcode (int method, void * phoneNumber, void * zone, void * tmpCode, void *observer)
	{
        if (phoneNumber
            && zone
            && observer) {
            NSString  *phoneNumberStr = [NSString stringWithCString:phoneNumber
                                                           encoding:NSUTF8StringEncoding];
            NSString *zoneStr = [NSString stringWithCString:zone
                                                   encoding:NSUTF8StringEncoding];

            NSString *tempCodeStr = nil;
            if(tmpCode)
                tempCodeStr = [NSString stringWithCString:tmpCode
                                                 encoding:NSUTF8StringEncoding];

            NSString *observerStr  = [NSString stringWithCString:observer
                                                        encoding:NSUTF8StringEncoding];

            [SMSSDK getVerificationCodeByMethod:method
                                    phoneNumber:phoneNumberStr
                                           zone:zoneStr
                                       template:tempCodeStr
                                         result:^(NSError *error) {

                NSMutableDictionary *resultDic = [NSMutableDictionary dictionaryWithCapacity:3];
                [resultDic setObject:[NSNumber numberWithInt:1]
                              forKey:@"action"];

                if (!error )
                {
                    NSString *resultMsg = @"getCodeSuccess";
                    [resultDic setObject:resultMsg forKey:@"res"];
                    [resultDic setObject:[NSNumber numberWithInt:1] forKey:@"status"];
                    //转化回到JSONString的状
                    if (method == SMSGetCodeMethodSMS)
                    {
                        NSLog(@"getTextCode Success_%s",[resultMsg UTF8String]);
                    }
                    else
                    {
                        NSLog(@"getVoiceCode Success_%s",[resultMsg UTF8String]);
                    }

                    NSString *resultStr = [MOBFJson jsonStringFromObject:resultDic];
                    UnitySendMessage([observerStr UTF8String], "_callBack", [resultStr UTF8String]);

                }
                else
                {
                    NSMutableDictionary * resultErrorMsg =[NSMutableDictionary dictionaryWithObjectsAndKeys:@(error.code),
                                                           @"code",
                                                           error.domain,
                                                           @"domain",
                                                           error.userInfo,
                                                           @"userInfo",
                                                           nil];
                    //转化回到JSONString的状态码
                    [resultDic setObject:[NSNumber numberWithInt:2] forKey:@"status"];
                    NSString *resultMsg= [MOBFJson jsonStringFromObject:resultErrorMsg];
                    [resultDic setObject:resultMsg forKey:@"res"];
                    NSString *resultStr = [MOBFJson jsonStringFromObject:resultDic];

                    // 参数1: unity中的场景对象名称,
                    //参数2: unity中场景对象要执行的方法
                    //参数3: ios向unity传递的参数
                    UnitySendMessage([observerStr UTF8String], "_callBack", [resultStr UTF8String]);
                }
            }];
        }
	}

    void __iosCommitcode (void * phoneNumber, void * zone, void * code, void *observer)
	{
        NSString *phoneNumberStr = nil;
        NSString *zoneStr = nil;
        NSString *verificationCodeStr = nil;
        NSString *observerStr = nil;

        if (phoneNumber
            && zone
            && code
            && observer) {
            phoneNumberStr = [NSString stringWithCString:phoneNumber
                                                encoding:NSUTF8StringEncoding];
            zoneStr = [NSString stringWithCString:zone
                                         encoding:NSUTF8StringEncoding];
            verificationCodeStr = [NSString stringWithCString:code
                                                     encoding:NSUTF8StringEncoding];
            observerStr = [NSString stringWithCString:observer
                                             encoding:NSUTF8StringEncoding];

            [SMSSDK commitVerificationCode:verificationCodeStr
                               phoneNumber:phoneNumberStr
                                      zone:zoneStr
                                    result:^(NSError *error) {

                NSMutableDictionary *resultDic = [NSMutableDictionary dictionaryWithCapacity:3];
                [resultDic setObject:[NSNumber numberWithInt:2] forKey:@"action"];

                if (!error)
                {
                    NSString *resultMsg = @"commitVerifyCode Success";
                    [resultDic setObject:[NSNumber numberWithInt:1] forKey:@"status"];
                    [resultDic setObject:resultMsg forKey:@"res"];
                    NSString *resultString = [MOBFJson jsonStringFromObject:resultDic];
                    //转化回到JSONString的状
                    UnitySendMessage([observerStr UTF8String], "_callBack", [resultString UTF8String]);
                }
                else
                {
                    NSMutableDictionary * resultErrorMsg =[NSMutableDictionary dictionaryWithObjectsAndKeys:@(error.code),
                                                           @"code" ,
                                                           error.domain,
                                                           @"domain",
                                                           error.userInfo,
                                                           @"userInfo",
                                                           nil];
                    [resultDic setObject:[NSNumber numberWithInt:2] forKey:@"status"];
                    //转化回到JSONString的状态码
                    NSString *resultMsg = [MOBFJson jsonStringFromObject:resultErrorMsg];
                    [resultDic setObject:resultMsg forKey:@"res"];
                    NSString *resultStr = [MOBFJson jsonStringFromObject:resultDic];

                    UnitySendMessage([observerStr UTF8String], "_callBack", [resultStr UTF8String]);

                }
            }];
        }
	}

    void __iosSubmitpolicygrantresult (BOOL isAgree, void *observer)
	{
        if (!observer) {
            return;
        }

        NSString *observerStr = [NSString stringWithCString:observer
                                                   encoding:NSUTF8StringEncoding];
        [MobSDK uploadPrivacyPermissionStatus:isAgree onResult:^(BOOL success) {
            NSMutableDictionary *mDict = [NSMutableDictionary dictionary];
            // Success = 1, Fail = 2
            [mDict setObject:[NSNumber numberWithInt:1] forKey:@"status"];
            // action == SubmitPolicyGrantResult
            [mDict setObject:[NSNumber numberWithInt:10] forKey:@"action"];
            [mDict setObject:[NSNumber numberWithBool:success] forKey:@"res"];

            NSString *jsonStr = [MOBFJson jsonStringFromObject:mDict];
            //参数1: unity中的场景对象名称,
            //参数2: unity中场景对象要执行的方法
            //参数3: ios向unity传递的参数
            UnitySendMessage([observerStr UTF8String], "_callBack", [jsonStr UTF8String]);
        }];
	}


#if defined (_cplusplus)
}
#endif

@implementation SMSSDK_Unity3DBridge
@end
