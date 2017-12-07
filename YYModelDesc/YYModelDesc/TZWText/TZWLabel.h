//
//  TZWLabel.h
//  YYModelDesc
//
//  Created by TANZHIWEN on 2017/12/7.
//  Copyright © 2017年 TANZHIWEN. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark 结构体的内容

typedef NS_ENUM(NSInteger,TZWTextVerticalAlignment){
    TZWTextVerticalAlignmentTop = 0,
    TZWTextVerticalAlignmentCenter = 1,
    TZWTextVerticalAlignmentBottom = 2,
};

@interface TZWLabel : UIView<NSCoding>

@property (nonatomic,copy) NSString *text;

@property (nonatomic,strong) UIFont *font;

@property (nonatomic,strong) UIColor *shadowColor;

@property (nonatomic) CGSize shadowOffSet;

@property (nonatomic) CGFloat shadowBlurRadius;

@property (nonatomic)NSTextAlignment textAlignment;

@property (nonatomic)  TZWTextVerticalAlignment textVerticalAlignment;

@property (nonatomic,copy) NSAttributedString *attributedText;

@property (nonatomic) NSLineBreakMode lineBreakMode;

/**
 The truncation token string used when text is truncated. Default is nil.
 When the value is nil, the label use "…" as default truncation token.
 */
@property (nonatomic,copy)NSAttributedString *truncationToken;

@property (nonatomic) NSUInteger numberOfLines;

//@property (nonatomic,strong) id<YYTextParse> textParser;

//@property (nullable, nonatomic, strong) YYTextLayout *textLayout;


#pragma mark text的容器配置
@property (nonatomic,copy) UIBezierPath *textContainerPath;

@property (nonatomic,copy) NSArray<UIBezierPath *> *exclusionPaths;

@property (nonatomic) UIEdgeInsets textContainerInset;

@property (nonatomic,getter=isVertical) BOOL vertical;

//@property (nonatomic,copy) id<YYTextLinePositionModifier> linePositionModifier;

//@property (nullable, nonatomic, copy) YYTextDebugOption *debugOption;

#pragma mark 获取的是layout container

@property (nonatomic) CGFloat preferredMaxLayoutWidth;

#pragma mark 手势处理的东西
//@property (nonatomic,copy)  YYTextAction textTapAction;
//
//@property (nonatomic,copy)  YYTextAction textLongPressAction;
//
//@property (nonatomic,copy)  YYTextAction highlightTapAction;
//
//@property (nonatomic,copy)  YYTextAction highlightLongPressAction;


#pragma mark 配置显示模式

//布局和呈现代码是否正在运行
//异步后台线程。
@property (nonatomic) BOOL displaysAsynchronously;

/**
 如果值是YES，而层是异步呈现的，那么它就会是异步的
 设置label.layer。内容在显示前为nil。当异步显示被启用时，该层的内容将会被启用
 在后台渲染过程完成后进行更新。如果渲染过程
 无法在 时间内完成(1 / 60秒)，旧内容仍然保留
 为显示。您可以通过设置图层来手动清除内容。内容为零
 在您更新标签的属性之后，或者您可以将这个属性设置为YES。
 */

@property (nonatomic) BOOL clearContentBeforeAsynchronouslyDisplay;

/**
 如果值是YES，并且该层是异步呈现的，那么它将添加
 当层的内容发生变化时，在图层上的渐变动画。
 */
@property (nonatomic) BOOL fadeOnAsynchrounouslyDisplay;

/**
 如果值是YES，那么它将在某个范围内添加一个渐变动画
 的文字变得突出。
*/
@property (nonatomic) BOOL fadeOnHighlight;

/**
 忽略公共属性(例如文本、字体、textColor、attributedText…)和
 只使用“textLayout”显示内容。
 默认值是“NO”。
 如果你只通过“textLayout”来控制标签内容，那么就进行讨论
 您可以将这个值设置为YES以获得更高的性能。
*/
@property (nonatomic) BOOL ignoreCommonProperties;

/*
 小帖示:
 1 .工作如果你只需要一个UILabel替代显示富文本和接收链接触摸事件，
 您不需要调整显示模式属性。
 2。如果您有性能问题，您可以启用异步显示模式
 通过将“displaysasynchronUNK”设置为YES。
 3 .项目如果你想获得最高的性能，你应该做文本布局
 在后台线程中“YYTextLayout”类。这里有一个例子:
 
 YYLabel *label = [YYLabel new];
 label.displaysAsynchronously = YES;
 label.ignoreCommonProperties = YES;
 
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
 
 // Create attributed string.
 NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:@"Some Text"];
 text.yy_font = [UIFont systemFontOfSize:16];
 text.yy_color = [UIColor grayColor];
 [text yy_setColor:[UIColor redColor] range:NSMakeRange(0, 4)];
 
 // Create text container
 YYTextContainer *container = [YYTextContainer new];
 container.size = CGSizeMake(100, CGFLOAT_MAX);
 container.maximumNumberOfRows = 0;
 
 // Generate a text layout.
 YYTextLayout *layout = [YYTextLayout layoutWithContainer:container text:text];
 
 dispatch_async(dispatch_get_main_queue(), ^{
 label.size = layout.textBoundingSize;
 label.textLayout = layout;
 });
 });
 
 */
@end








































