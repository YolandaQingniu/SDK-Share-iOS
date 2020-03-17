//
//  QNErrorCode.h
//  QNDeviceSDKDemo
//
//  Created by Yolanda on 2018/3/31.
//  Copyright © 2018年 Yolanda. All rights reserved.
//

typedef NS_ENUM(NSInteger, QNBleErrorCode) {
    QNBleErrorCodeInvalidateAppId = 1001,
    QNBleErrorCodeNotInitSDK = 1002,
    QNBleErrorCodeFirstDataFileURL = 1003,
    QNBleErrorCodePackageName = 1004,
    QNBleErrorCodeBundleID = 1005,
    QNBleErrorCodeInitFile = 1006,
    
    QNBleErrorCodeIllegalArgument = 1201,
    QNBleErrorCodeUserIdEmpty = 1204,
    QNBleErrorCodeUserGender = 1205,
    QNBleErrorCodeUserHeight = 1206,
    QNBleErrorCodeUserBirthday = 1207,
    QNBleErrorCodeUserAthleteType = 1209,
    QNBleErrorCodeUserShapeGoalType = 1210,

    QNBleErrorCoder = 1301,
    QNBleErrorCoderInvalid = 1302,
};
