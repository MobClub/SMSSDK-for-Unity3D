//
//  FlyVerifyCRSAKey.h
//  FlyVerifyCSDK
//
//  Created by fenghj on 15/7/29.
//  Copyright (c) 2015年 FlyVerify. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FlyVerifyCBigInteger;

@interface FlyVerifyCRSAKey : NSObject

/**
 *  bits in key
 */
@property (nonatomic) int bits;

/**
 *  modulus
 */
@property (nonatomic, strong) FlyVerifyCBigInteger *n;

/**
 *  public exponent
 */
@property (nonatomic, strong) FlyVerifyCBigInteger *e;

/**
 *  private exponent
 */
@property (nonatomic, strong) FlyVerifyCBigInteger *d;

@end
