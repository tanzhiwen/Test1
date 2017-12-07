//
//  NSObject+MiracleModel.h
//  YYModelDesc
//
//  Created by TANZHIWEN on 2017/12/7.
//  Copyright © 2017年 TANZHIWEN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (MiracleModel)


/**
 创建返回一个json实例 是线程安全的
 @return json
 */
+(nullable instancetype)miracle_modelWithJson:(id)json;


/**
 创建并返回一个字典  这里的如果dic的字段不匹配model中的属性 是线程安全的
 
 基本的规则是： `NSString` or `NSNumber` -> c number, such as BOOL, int, long, float, NSUInteger...
 `NSString` -> NSDate, parsed with format "yyyy-MM-dd'T'HH:mm:ssZ", "yyyy-MM-dd HH:mm:ss" or "yyyy-MM-dd".
 `NSString` -> NSURL.
 `NSValue` -> struct or union, such as CGRect, CGSize, ...
 `NSString` -> SEL, Class.
 
 @return
 */
+(nullable instancetype)miracle_modelWithDict:(NSDictionary *)dict;

/**
 通过json给model赋值：一个json中的dic，string，date 映射到model中的属性，返回是否成功
 */
-(BOOL)miracle_modelSetWithJson:(id)json;

/**
 通过字典dict给model赋值：返回是否成功
*/
-(BOOL)miracle_modelSetWithDict:(NSDictionary *)dict;

//通过属性生成一个json object  可以看下[NSJSONSerialization isValidJSONObject] 了解下
-(nullable id)miracle_modelToJsonObject;


-(nullable NSData *)miracle_modelToJsonData;

-(nullable NSString *)miracle_modelToJsonString;

-(nullable id)miracle_modelCopy;

-(void)miracle_modelEncodeWithCoder:(NSCoder *)aCoder;

-(id)miracle_modelInitWithCoder:(NSCoder *)aDecoder;

@end

//是
@interface NSArray (MiracleModel)

// 返回一个json数组
+(nullable NSArray *)miracle_modelArrayWithClass:(Class)cls json:(id)json;

@end

@interface NSDictionary (MiracleModel)

// 返回一个json 字典
+(nullable NSDictionary *)miracle_modelDictWithClass:(Class)cls json:(id)json;


@end

@protocol MiracleModel<NSObject>

@optional

/**
 这里自定义的属性映射，主要是涉及到不匹配的属性的时候怎么处理：  例子：
 json:
 {
 "n":"Harry Pottery",
 "p": 256,
 "ext" : {
 "desc" : "A book written by J.K.Rowling."
 },
 "ID" : 100010
 }
 
 model:
 @interface YYBook : NSObject
 @property NSString *name;
 @property NSInteger page;
 @property NSString *desc;
 @property NSString *bookID;
 @end
 
 @implementation YYBook
 + (NSDictionary *)modelCustomPropertyMapper {
 return @{@"name"  : @"n",
 @"page"  : @"p",
 @"desc"  : @"ext.desc",
 @"bookID": @[@"id", @"ID", @"book_id"]};
 }
 @end
 */

+(nullable NSDictionary<NSString *, id> *)modelCustomPropertyMapper;


/**
 这个主要讲的容器属性：
 如果你的属性是一个容器对象，例如 NSSArray NSSet NSDictionary ,实现的时候是返回一个属性的映射，告诉你哪个对象应该放到对应的NSSArray中去
 Example:
 @class YYShadow, YYBorder, YYAttachment;
 
 @interface YYAttributes
 @property NSString *name;
 @property NSArray *shadows;
 @property NSSet *borders;
 @property NSDictionary *attachments;
 @end
 
 @implementation YYAttributes
 + (NSDictionary *)modelContainerPropertyGenericClass {
 return @{@"shadows" : [YYShadow class],
 @"borders" : YYBorder.class,
 @"attachments" : @"YYAttachment" };
 }
 @end
 
 @return A class mapper.
 */

+(nullable NSDictionary<NSString *,id> *)modelContainerPropertyGenericClass;

// 如果你希望通过json 获取多不同的多个class，就使用这种方式，
/**
 Example:
 
 @class YYCircle, YYRectangle, YYLine;
 
 @implementation YYShape
 
 + (Class)modelCustomClassForDictionary:(NSDictionary*)dictionary {
 if (dictionary[@"radius"] != nil) {
 return [YYCircle class];
 } else if (dictionary[@"width"] != nil) {
 return [YYRectangle class];
 } else if (dictionary[@"y2"] != nil) {
 return [YYLine class];
 } else {
 return [self class];
 }

 */

+(nullable Class)modelCustomClassForDict:(NSDictionary *)dict;


// 黑名单和白名单的意思相反，黑名单：在其中不会被转换   白名单：只有在名单中的属性才会被转换
+(nullable NSArray<NSString *> *)modelPropertyBlacklist;

+(nullable NSArray<NSString *> *)modelPropertyWhitelist;


-(NSDictionary *)modelCustomWillTransformFromDict:(NSDictionary *)dict;

-(BOOL)modelCustomTransformFromDict:(NSDictionary *)dict;

-(BOOL)modelCustomTransformToDict:(NSMutableDictionary *)dict;


@end

NS_ASSUME_NONNULL_END

