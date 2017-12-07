//
//  TzwTextParser.h
//  YYModelDesc
//
//  Created by TANZHIWEN on 2017/12/7.
//  Copyright © 2017年 TANZHIWEN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol TzwTextParserDelegate <NSObject>

@required
- (BOOL)parseText:(NSMutableAttributedString *)text selectedRange:(NSRangePointer)selectedRange;
@end

@interface TzwTextParser : NSObject<TzwTextParserDelegate>

@property (nonatomic) CGFloat fontSize;         ///< default is 14
@property (nonatomic) CGFloat headerFontSize;   ///< default is 20
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *controlTextColor;
@property (nonatomic, strong) UIColor *headerTextColor;
@property (nonatomic, strong) UIColor *inlineTextColor;
@property (nonatomic, strong) UIColor *codeTextColor;
@property (nonatomic, strong) UIColor *linkTextColor;

- (void)setColorWithBrightTheme;
- (void)setColorWithDarkTheme;

@end

@interface TzwTextSimpleEmotionParser:NSObject<TzwTextParserDelegate>
//自定义表情符号映射器。
//键是指定的普通字符串，例如@“:smile:”。
//值是一个UIImage，它将在文本中替换指定的纯字符串。
@property (copy) NSDictionary<NSString *, __kindof UIImage *> *emoticonMapper;

@end
