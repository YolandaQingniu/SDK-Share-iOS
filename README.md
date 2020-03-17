# 轻牛共享秤 SDK

SDK 的运行需要 appid 以及配置文件，商家在接入时可先使用轻牛提供的测试 appid 和测试配置文件，正式发布时必须向轻牛官方获取正式 appid 和配置文件

## 安装方式

### cocoapods 安装:

- 先安装 Cocoapods；
- 通过 pod repo update 更新 QNSDK 的 cocoapods 版本；
- 在 Podfile 对应的 target 中，添加`pod 'QNShareSDK'`，并执行 pod install；
- 在项目中使用 CocoaPods 生成的.xcworkspace 运行工程；
- 在你的代码文件头引入头文件`#import <QNShareSDK/QNShareSDK.h>`

### 手动安装:

- 下载 SDK 安装包至工程
- 引入 SDK 路径 【TARGETS】-> 【Build Setting】->【Search Paths】->【LibrarySearch Paths】中添加 SDK 路径
- 配置链接器 【TARGETS】-> 【Build Setting】-> 【Linking】-> 【Other Linker Flags】中添加 `-ObjC`、`-all_load`、`-force_load [SDK路径]` 其中之一

## 使用方式

- 初始化 sdk

  ```objc
  NSString *filePath = [[NSBundle mainBundle] pathForResource:@"123456789" ofType:@"qn"];
  [QNShareApi sharedApi] initSdk:@"123456789" firstDataFile:filePath callback:^(NSError *error) {
  //对错误做出相关处理

  }];
  ```

- 获取待解析的数据

  ```objc
  NSString *example = @"http://share.api.yolanda.hk/api/mobile/scan?c=bc9886d2d68926bc389b6e86";
  ```

- 解析数据

  ```objc
  //构建需要获取测量数据的用户信息
  QNUser *user = [[QNUser alloc] init];
  user.userId = @"123456789";
  user.height = 172;
  user.gender = @"male";
  user.birthday = [NSDate dateWithTimeIntervalSince1970:756921600];

  QNShareData *shareData = [QNUtils decodeShareDataWithCode:example user:user callblock:^(NSError *error) {
      if (error) {
          //处理错误情况
      }
  }];
  ```

- 获取结果
  ```objc
  NSArray<QNScaleItemData *> *allDatas = [shareData.scaleData getAllItem];
  ```
