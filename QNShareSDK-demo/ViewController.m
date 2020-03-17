//
//  ViewController.m
//  QNShareSDK-demo
//
//  Created by qiudongquan on 2020/3/17.
//  Copyright © 2020 QingNiu. All rights reserved.
//

#import "ViewController.h"
#import <QNShareSDK/QNShareSDK.h>

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UITextView *codeTextView;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property(nonatomic, strong) NSArray<QNScaleItemData *> *dataSource;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"123456789" ofType:@"qn"];
    [[QNShareApi sharedApi] initSdk:@"123456789" firstDataFile:filePath callback:^(NSError *error) {
       //对错误做出相关处理
        
    }];
    
}

- (IBAction)analysisCode:(UIButton *)sender {
    [self.codeTextView resignFirstResponder];
    
    QNUser *user = [[QNUser alloc] init];
    user.userId = @"123456789";
    user.height = 172;
    user.gender = @"male";
    user.birthday = [NSDate dateWithTimeIntervalSince1970:756921600];
    
    QNShareData *shareData = [QNUtils decodeShareDataWithCode:self.codeTextView.text user:user callblock:^(NSError *error) {
        if (error) {
            //处理错误情况
        }
    }];
    
    if (shareData == nil) {
        self.dataSource = [NSArray array];
    } else {
        self.dataSource = [shareData.scaleData getAllItem];
    }
    
    [self.tableView reloadData];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellItem"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"cellItem"];
    }
    QNScaleItemData *itemData = self.dataSource[indexPath.row];
    cell.textLabel.text = itemData.name;
    cell.detailTextLabel.text = itemData.valueType == QNValueTypeInt ? [NSString stringWithFormat:@"%.0f",itemData.value] : [NSString stringWithFormat:@"%.2f",itemData.value];
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 44;
}

@end
