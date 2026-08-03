//
//  UIView+FlyVerifyCWebCache.h
//  FlyVerifyCSDK
//
//  Created by wukx on 2018/6/6.
//  Copyright © 2024年 FlyVerify. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^FlyVerifyCSetImageBlock)(UIImage * _Nullable image, NSError * _Nullable error);

@interface UIView (FlyVerifyCWebCache)

- (void)flyverifyc_internalSetImageWithURL:(nullable NSURL *)url
                       setImageBlock:(nullable FlyVerifyCSetImageBlock)setImageBlock;

@end
