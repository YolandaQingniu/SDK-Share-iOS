//
//  QNShareApi.h
//  QNShareSDK
//
//  Created by Yolanda on 2020/3/17.
//  Copyright © 2020 QingNiu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QNCallBackConst.h"

/**
此SDK为轻牛旗下共享秤数据分析，使用时需要向轻牛官方获取 "appId" 否则无法正常使用该SDK

当前版本【 0.0.1 】

SDK最低配置8.0的系统

工程的配置说明:
2.引入SDK路径 【TARGETS】-> 【Build Setting】->【Search Paths】->【LibrarySearch Paths】中添加SDK路径
3.配置链接器 【TARGETS】-> 【Build Setting】-> 【Linking】-> 【Other Linker Flags】中添加 "-ObjC"、"-all_load"、"-force_load [SDK路径]" 其中之一

*/

NS_ASSUME_NONNULL_BEGIN

/**
 秤端体重单位的显示

 - QNUnitKG: 所有的设备都支持该单位的显示
 - QNUnitLB: 若设备不支持该单位的显示，即便设置为 "QNUnitLB" 类型也会显示 "QNUnitKG" 类型
 - QNUnitJIN: 若设备不支持该单位的显示，即便设置为 "QNUnitJIN" 类型也会显示 "QNUnitKG" 类型
 - QNUnitST: 若设备不支持该单位的显示，而支持 "QNUnitLB" 的显示，则会显示 "QNUnitLB", 倘若 "QNUnitLB" 也不支持，则会显示 "QNUnitKG"
 */
typedef NS_ENUM(NSUInteger, QNUnit) {
    QNUnitKG = 0,
    QNUnitLB = 1,
    QNUnitJIN = 2,
    QNUnitST = 3,
};

@interface QNShareApi : NSObject

/** 是否打开调试开关 默认为NO (建议发布版本时,设置为NO) */
@property (nonatomic, assign, class) BOOL debug;

/**
 初始化SDK
 
 @return QNBleApi
 */
+ (QNShareApi *)sharedApi;


- (instancetype)init NS_UNAVAILABLE;

/**
 注册SDK
 必须先注册SDK后使用其他操作
 appid以及初始配置文件请向轻牛官方洽谈
 
 @param appId 需要向官方获取正确的appid
 @param dataFile 配置文件路径
 @param callback 结果回调
 */
- (void)initSdk:(NSString *)appId firstDataFile:(NSString *)dataFile callback:(QNResultCallback)callback;

/**
 根据提供的kg数值的体重，转化为指定单位的数值
 
 @param weight 默认单位的重量（体脂秤为KG ）
 @param unit  KG、LB、JIN、ST 为体脂秤单位 (不支持ST的转换，查询文档获取相关转化方法)
 @return 结果回调
 */
- (double)convertWeightWithTargetUnit:(double)weight unit:(QNUnit)unit;

@end

NS_ASSUME_NONNULL_END
