//
//  ACKRecordingResultTraceView.h
//  AliveECG
//
//  Created by Sophie Smith on 4/5/16.
//  Copyright © 2016 AliveCor Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACKTypes.h"

@class ACKEcgFileView;
@class ACKEcgRecord;

/**
 *  Methods for managing trace view behavior.
 */
extern const CGFloat ACKRecordingResultTraceViewAutomaticDimension;

@protocol ACKRecordingResultTraceViewDelegate<NSObject>

@optional

/**
 *  Override this method to customize height for the chart view depending on the leads configuration. Method is used for the backward compatibility with the Kardia App.
 *  If you want to override height for the specific lead and to keep second lead without changes, return ACKRecordingResultTraceViewAutomaticDimension
 */
- (CGFloat)recordingResultTraceViewHeightForLeadsConfig:(ACKLeadsConfig)leadsConfig;

/**
 *  The method signals that the invert button was pressed.
 */
- (void)recordingResultTraceViewPressedInvertEcgButton;
/**
 *  The method signals that the algorithm info button was pressed.
 */
- (void)recordingResultTraceViewPressedAlgorithmInfoButton;

@end

@interface ACKRecordingResultTraceView : UIView

@property (nonatomic, readonly) UIButton *invertButton;

- (instancetype)initWithEcg:(ACKEcgRecord *)ecg fileView:(ACKEcgFileView *)fileView largeLayout:(BOOL)largeLayout supportsLandscape:(BOOL)supportsLandscape delegate:(id<ACKRecordingResultTraceViewDelegate>)delegate;

// Standardized height for display based on current recording mode, layout, orientation, etc.
- (NSInteger)standardHeightForSingleLead;

@end
