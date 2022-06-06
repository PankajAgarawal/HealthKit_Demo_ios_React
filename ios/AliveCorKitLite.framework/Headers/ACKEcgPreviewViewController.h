//
//  ACRecordingResultViewController.h
//  AliveECG
//
//  Created by Sophie Smith on 4/5/16.
//  Copyright © 2016 AliveCor Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACKEcgRecordingConfig.h"
#import "ACKError.h"
#import "ACKEcgPreviewDelegate.h"

/**
 *  A view controller for the showing ECG recording results and AI evaluation results.
 */
@interface ACKEcgPreviewViewController : UIViewController

@property (nonatomic, copy, readonly) ACKEcgRecord * _Nullable record;

@property (nonatomic, weak) id<ACKEcgPreviewDelegate> _Nullable delegate;

/**
 *  Initializes object with the results of the ECG recording.
 *
 *  @param  record The results of the ECG recording.
 *  @return class instance
 */
- (instancetype _Nullable )initWithRecord:(ACKEcgRecord *_Nonnull)record;

@end
