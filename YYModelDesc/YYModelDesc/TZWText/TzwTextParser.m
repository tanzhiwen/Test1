//
//  TzwTextParser.m
//  YYModelDesc
//
//  Created by TANZHIWEN on 2017/12/7.
//  Copyright © 2017年 TANZHIWEN. All rights reserved.
//

#import "TzwTextParser.h"

@implementation TzwTextParser{
    UIFont *_font;
    NSMutableArray *_headerFonts; ///< h1~h6
    UIFont *_boldFont;
    UIFont *_italicFont;
    UIFont *_boldItalicFont;
    UIFont *_monospaceFont;
    
    
    NSRegularExpression *_regexEscape;          ///< escape
    NSRegularExpression *_regexHeader;          ///< #header
    NSRegularExpression *_regexH1;              ///< header\n====
    NSRegularExpression *_regexH2;              ///< header\n----
    NSRegularExpression *_regexBreakline;       ///< ******
    NSRegularExpression *_regexEmphasis;        ///< *text*  _text_
    NSRegularExpression *_regexStrong;          ///< **text**
    NSRegularExpression *_regexStrongEmphasis;  ///< ***text*** ___text___
    NSRegularExpression *_regexUnderline;       ///< __text__
    NSRegularExpression *_regexStrikethrough;   ///< ~~text~~
    NSRegularExpression *_regexInlineCode;      ///< `text`
    NSRegularExpression *_regexLink;            ///< [name](link)
    NSRegularExpression *_regexLinkRefer;       ///< [ref]:
    NSRegularExpression *_regexList;            ///< 1.text 2.text 3.text
    NSRegularExpression *_regexBlockQuote;      ///< > quote
    NSRegularExpression *_regexCodeBlock;       ///< \tcode \tcode
    NSRegularExpression *_regexNotEmptyLine;
}

-(instancetype)init{
    self = [super init];
    _fontSize = 14;
    _headerFontSize = 20;
    [self updateFonts];
    [self setColorWithBrightTheme];
//    [self initRegex];
    return self;
}

-(void)setFontSize:(CGFloat)fontSize{
    if (fontSize < 1) {
        fontSize = 12;
        _fontSize = fontSize;
        [self updateFonts];
    }
}

- (void)setHeaderFontSize:(CGFloat)headerFontSize {
    if (headerFontSize < 1) headerFontSize = 20;
    _headerFontSize = headerFontSize;
    [self updateFonts];
}

-(void)updateFonts{
    _textColor = [UIColor blackColor];
    _headerFonts = [NSMutableArray new];
    for (NSInteger i=0; i<6; i++) {
        CGFloat size = _headerFontSize -(_headerFontSize - _fontSize)/5 *i;
        [_headerFonts addObject:[UIFont systemFontOfSize:size]];
    }
//    _boldFont = YYTextFontWithBold(_font);
//    _italicFont = YYTextFontWithItalic(_font);
//    _boldItalicFont = YYTextFontWithBoldItalic(_font);
    _monospaceFont = [UIFont fontWithName:@"Menlo" size:_fontSize]; // Since iOS 7
    if (!_monospaceFont) _monospaceFont = [UIFont fontWithName:@"Courier" size:_fontSize];
}












































@end
