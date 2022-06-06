//
//  ACMonitorViewController.h
//  KardiaStation
//
//  Created by Alex Vlasenko on 10/8/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACKEcgMonitorDelegate.h"
#import "ACKEcgRecordingConfig.h"

/**
 *  A view controller for the ECG recording.
 */
@class ACKEcgMonitorViewController;

NS_ASSUME_NONNULL_BEGIN

@interface ACKEcgMonitorViewController : UIViewController

@property (nonatomic, copy, readonly) ACKEcgRecord *record;

@property (nonatomic, weak, nullable) id<ACKEcgMonitorDelegate> delegate;

/**
 *  Initializes object with initial state for the ECG recording.
 *
 *  @param  config The configuration for the ECG recording.
 *  @return class instance
 */
- (nullable instancetype)initWithConfig:(ACKEcgRecordingConfig *)config;

/**
 *  Initializes object with initial state for the ECG recording.
 *
 *  @param  config The configuration for the ECG recording.
 *  @param  error The error object.
 *  @return class instance
 */
- (nullable instancetype)initWithConfig:(ACKEcgRecordingConfig *)config error:(ACKError *_Nullable*_Nullable)error;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Stops the ECG monitor, frees resources. Do call this method if you are using custom back/close buttons.
 *
 */
- (void)stopMonitor;

@end

NS_ASSUME_NONNULL_END
