//
//  ECGRecord.h
//  ACKit
//
//  Created by Alex Vlasenko on 10/18/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKTypes.h"

NS_ASSUME_NONNULL_BEGIN
@class ACKDevice;
@class ACKEcgEvaluation;
@class ACKEcgRecordingConfig;

/**
 *  ACKEcgRecord class keeps the information about ECG recording, the configuration that was used during recording,
 *  and device specification that was used for the recording. Object of this class would be produced by ACKEcgMonitorViewController.
 *  ACKEcgRecord is the main data holder and is used as datasource in all UI components within the SDK
 *
 */
@interface ACKEcgRecord : NSObject

/**
 *  A unique identifier of the ecg recording.
 */
@property (nonatomic, copy, readonly, nullable) NSString *uuid;
/**
 *  The path to the raw recording ATC file. The 'raw' ecg recording is baseline corrected and mains-filtered.
 */
@property (nonatomic, copy, readonly, nullable) NSString *originalPath;
/**
 *  The path to the enhanced filtered ATC file.
 */
@property (nonatomic, copy, readonly, nullable) NSString *enhancedPath;
/**
 *  The path to the audio notes file. Audio notes are saved in m4a format.
 */
@property (nonatomic, copy, readonly, nullable) NSString *audioNotesPath;
/**
 *  The measurement date/time. This property is not required for displaying ECG chart.
 */
@property (nonatomic, copy, readonly, nullable) NSDate *recordedAt;
/**
 *  The measurement time zone offset. This property is not required for displaying ECG chart.
 */
@property (nonatomic, readonly) NSNumber *timeZoneOffset;
/**
 *  The path to the directory where recorded ecgs are stored.
 */
@property (nonatomic, copy, readonly) NSString *filesDirectory;
/**
 *  The duration of the ECG recording in milliseconds.
 */
@property (nonatomic, copy, readonly, nullable) NSNumber *duration;
/**
 *  The divice that was used for the ECG recording.
 */
@property (nonatomic, copy, readonly, nullable) ACKDevice *device;
/**
 *  The configuration that was used for the ECG recording.
 */
@property (nonatomic, copy, readonly) ACKEcgRecordingConfig *config;
/**
 *  The results of the Kardia AI evaluation.
 */
@property (nonatomic, copy, readonly, nullable) ACKEcgEvaluation *evaluationResult;
/**
 *  The placeholder for custom properties.
 */
@property (nonatomic, copy, nullable) NSDictionary *metadata;


/**
 *  The init methods are used internally when ECG recording is completed.
 *  It's possible to use them to restore object and to pass it in ACKEcgFileView, ACKScrollView, ACKRecordingResultTraceView.
 *
 *  @param  uuid A unique identifier of the ecg recording.
 *  @return duration The duration of the ECG record.
 *  @return config The configuration that would be used to record ECG. (Or the configuration that was used to record ECG).
 *  @return device The device that was used to record ECG.
 *  @return recordedAt The measurement date of the ECG recording.
 *  @return evaluation The KAI evaluation of the recorded ECG.
 *
 */
- (instancetype)initWithUUID:(NSString * _Nullable)uuid duration:(NSNumber * _Nullable)duration config:(ACKEcgRecordingConfig *)config device:(ACKDevice * _Nullable)device recordedAt:(NSDate * _Nullable)recordedAt timeZoneOffset:(NSNumber * _Nullable)timeZoneOffset evaluation:(ACKEcgEvaluation * _Nullable)evaluation;

- (instancetype)initWithUUID:(NSString * _Nullable)uuid duration:(NSNumber * _Nullable)duration config:(ACKEcgRecordingConfig *)config device:(ACKDevice *_Nullable)device recordedAt:(NSDate *_Nullable)recordedAt timeZoneOffset:(NSNumber * _Nullable)timeZoneOffset;

/**
 *  Creates a lightweight the instance of the ACKEcgRecord. Could be used to display ACKEcgFileView, ACKScrollView, ACKRecordingResultTraceView
 *
 *  @param  ecgPath The path to the ecg record.
 *  @param  deviceType The device type that was used to record ECG.
 *  @param  filterType The filter that was applied for rendering.
 *  @param  leadsConfig The leads configuration that was used for the ECG recoding.
 *  @param  evaluation The KAI evaluation result.
 *  @return the class instance.
 *
 */
- (instancetype)initWithEcgPath:(NSString *)ecgPath
                     deviceType:(ACKDeviceType)deviceType
                     filterType:(ACKFilterType)filterType
                    leadsConfig:(ACKLeadsConfig)leadsConfig
                     evaluation:(ACKEcgEvaluation * _Nullable)evaluation;


- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
