//
//  ACMonitorViewControllerDelegate.h
//  ACKit
//
//  Created by Alex Vlasenko on 10/30/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#ifndef ACMonitorViewControllerDelegate_h
#define ACMonitorViewControllerDelegate_h
#import <UIKit/UIKit.h>
#import "ACKTypes.h"
#import "ECGData.h"

@class ACKEcgMonitorViewController;
@class ACKEcgRecord;
@class ACKError;
@class ACKEcgRecordingConfig;

/**
 *  Methods for tracking ECG recording progress and completion handlers.
 */
@protocol ACKEcgMonitorDelegate <NSObject>

@optional

/**
 *  Tells the delegate that ECG recording was canceled.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @param  error The error which was encountered while canceling ECK recording or nil if there were no errors.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didCancelWithError:(nullable ACKError *)error;

/**
 *  Tells the delegate that settings button was pressed.
 *
 *  @param viewController The reference to the ECG monitoring view controller.
 *  @param config   The ECG monitor configuration.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didPressSettingWithConfig:(nullable ACKEcgRecordingConfig *)config;

/**
 *  Tells the delegate that ECG recording was completed.
 *
 *  @param viewController The reference to the ECG monitoring view controller.
 *  @param record   The ecg record.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didCompleteRecording:(nullable ACKEcgRecord *)record;


/**
 *  Tells the delegate that ECG recording encountered an error. Method is used only for reporting errors, that are happening while recording ECG. 
 *
 *  @param viewController The view controller that is responsible for the ECG monitoring.
 *  @param error    The error encountered while recording ECG.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didEncounterError:(nullable ACKError *)error;

/**
 *  Asks the delegate whether the cancel button should be displayed.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return YES or NO
 *
 */
- (BOOL)showCancelButtonInEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController;

/**
 *  Asks the delegate whether the settings button should be displayed.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return YES or NO
 *
 */
- (BOOL)showSettingsButtonInEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController;

/**
 *  Asks the delegate for a custom button to display in the right view of the nav bar.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return custom right navigation item
 *
 */
- (UIBarButtonItem *_Nullable)rightItemViewForEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController;

/**
 *  Asks the delegate for a custom button to display in the left view of the nav bar.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return custom left navigation item
 *
 */
- (UIBarButtonItem *_Nullable)leftItemViewForEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController;

/**
 *  Asks the delegate whether confirmation dialog should have additional information.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return message that needs to be displayed when confirming ECG recording.
 *
 */
- (NSString *_Nullable)confirmRecordingMessageForEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController;

/**
 *  Asks the delegate whether confirmation dialog should have additional information.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return YES or NO depending on whether app needs to show device information or not.
 *
 */
- (BOOL)showDeviceInfoInConfirmRecordingForEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController;

/**
 *  Tells the delegate that the leads have been changed.
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @param  config new leads configuration.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didChangeLeadsConfig:(ACKLeadsConfig)config;

/**
 *  Tells the delegate that ECG recording encountered an audio error.
 *  This delegate method would be called only for theultrasonic devices: Kardia Mobile (ACKDeviceTypeMobile), Omron Complete (ACKDeviceTypeSakuraOne).
 *  When overriding this make sure that application prodides correct instructions to the user.
 *  Sometimes the OS gives us an audio session with properties we can't support (e.g. sample rate), usually because another application or hardware is active.
 *  In this case, we instruct the user to close other audio apps (ACKErrorCodeAudioSession error), then exit ourselves and hope we get the properties we asked for on the next launch.
 *  When didEncounterAudioError is not overiden, audio error would be handled by the SDK and application would be closed after showing an alert message to the user.
 *
 *  @param viewController The view controller that is responsible for the ECG monitoring.
 *  @param error    The error encountered while recording ECG.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didEncounterAudioError:(nullable ACKError *)error;

/**
 *  During recording, will be called periodically with real-time filtered ECG samples, so the view controller can display live preview.
 *
 *  @param viewController The view controller that is responsible for the ECG monitoring.
 *  @param ecgFrame The most recent samples from each ECG lead.
 *
 */
- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didReceiveEcgFrame:(struct ECGFrame)ecgFrame;

@end


#endif /* ACMonitorViewControllerDelegate_h */
