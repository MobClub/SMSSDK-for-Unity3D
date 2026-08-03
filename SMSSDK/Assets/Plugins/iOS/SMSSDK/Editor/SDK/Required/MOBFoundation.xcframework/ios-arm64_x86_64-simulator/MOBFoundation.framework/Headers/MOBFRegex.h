//
//  MOBFRegex.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-20.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlyVerifyCSDK/FlyVerifyCRegex.h>

/**
 *  替换处理
 *
 *  @param captureCount    捕获数量
 *  @param capturedStrings 捕获字符串集合
 *  @param capturedRanges  捕获字符串范围集合
 *  @param stop            是否停止捕获标识
 *
 *  @return 替换后的字符串
 */
typedef NSString *(^MOBFReplacingOccurrencesHandler) (NSInteger captureCount, NSString *const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop);

/**
 正则表达式选项
 
 - MOBFRegexOptionsNoOptions: 无匹配
 - MOBFRegexOptionsCaseless: 不区分字母大小写的模式
 - MOBFRegexOptionsComments: 忽略掉正则表达式中的空格和#号之后的字符
 - MOBFRegexOptionsIgnoreMetacharacters: 将正则表达式整体作为字符串处理
 - MOBFRegexOptionsDotAll: 允许.匹配任何字符，包括换行符
 - MOBFRegexOptionsMultiline: 允许^和$符号匹配整段文本的开头和结尾
 - MOBFRegexOptionsUseUnixLineSeparators: 设置\n为唯一的行分隔符，否则所有的都有效。
 - MOBFRegexOptionsUnicodeWordBoundaries: 使用Unicode TR#29标准作为词的边界，否则所有传统正则表达式的词边界都有效
 */
typedef NS_ENUM(NSUInteger, MOBFRegexOptions)
{
    MOBFRegexOptionsNoOptions               = 0,
    MOBFRegexOptionsCaseless                = 1 << 0,
    MOBFRegexOptionsComments                = 1 << 1,
    MOBFRegexOptionsIgnoreMetacharacters    = 1 << 2,
    MOBFRegexOptionsDotAll                  = 1 << 3,
    MOBFRegexOptionsMultiline               = 1 << 4,
    MOBFRegexOptionsUseUnixLineSeparators   = 1 << 5,
    MOBFRegexOptionsUnicodeWordBoundaries   = 1 << 6,
};

/**
 *  正则表达式工具类
 */
@interface MOBFRegex : FlyVerifyCRegex

@end
