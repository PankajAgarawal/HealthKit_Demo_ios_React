//
//  ECGScrollView.h
//  AliveECG
//
//  Created by Sophie Smith on 4/26/16.
//  Copyright © 2016 AliveCor Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ACKEcgFileView;

NS_ASSUME_NONNULL_BEGIN

@interface ACKScrollView : UIView

@property (readonly) UIScrollView *scrollView;
@property (nonatomic) ACKEcgFileView *fileView;
@property (nonatomic) BOOL scrollEnabled;

- (instancetype)initWithEcgFileView:(ACKEcgFileView *)fileView;

@end

NS_ASSUME_NONNULL_END
