//
//  UIImageView+FlyVerifyCWebCache.h
//  FlyVerifyCSDK
//
//  Created by wukx on 2018/6/6.
//  Copyright © 2024年 FlyVerify. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (FlyVerifyCWebCache)

- (void)flyverifyc_setImageWithURL:(nullable NSURL *)url;

- (void)flyverifyc_setImageWithURL:(nullable NSURL *)url
            placeholderImage:(nullable UIImage *)placeholder;

@end
