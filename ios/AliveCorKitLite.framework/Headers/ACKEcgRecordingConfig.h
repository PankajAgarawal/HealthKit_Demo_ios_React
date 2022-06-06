//
//  ACKECGMonitorConfig.h
//  AliveECG
//
//  Created by Jim Qin on 7/5/17.
//  Copyright © 2017 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKTypes.h"
#import "ACKDevice.h"

NS_ASSUME_NONNULL_BEGIN

@class ACKError;

/**
 *  A configuration object that defines how the recording flow should look and function.
 *  The object includes the underlying data specified in the initializer which drives
 *  the view logic that results in computed properties.
 */
@interface ACKEcgRecordingConfig : NSObject

/**
 *  The string value that defines which hardware is used to record ECG.
 */
@property (nonatomic, readonly) ACKDeviceType deviceType;
/**
 *  The recording mode applied to the device.
 */
@property (nonatomic, readonly) ACKLeadsConfig leadsConfig;
/**
 *  The filter setting for the ecg real time preview.
 */
@property (nonatomic, readonly) ACKFilterType filterType;
/**
 *  The maximum duration of the ECG recording that should be used by ECG monitor (ACKEcgMonitorViewController).
 */
@property (nonatomic, readonly) NSInteger maxDuration;
/**
 *  The reset duration is a  duration that defines minimum value for the ecg recording.
 *  If ecg recording duration is less than reset duration, ecg monitor will reset it's state and user will need to record ecg again.
 *  Default value is 10 seconds.
 */
@property (nonatomic, readonly) NSInteger minDuration;
/**
 *  The frequency of the power grid where the ECG was recorded One of {ACKMainsFilter50Hz, ACKMainsFilter60Hz}
 */
@property (nonatomic, readonly) NSInteger frequency;
/**
 *  The sampling frequency of the signal.
 */
@property (nonatomic, readonly) NSInteger sampleRate;
/**
 *  Defines whether ECG recording trace should be hidden or not. This flag would be ignored for the ACKDeviceTypeTriangle
 */
@property (nonatomic) BOOL hideTrace;
/**
 *  Defines how the device name should be presented to the user, if not defined the default value would be used.
 */
@property (nonatomic, copy) NSString *deviceDisplayName;
/**
 *  Defines whether ECG recording trace should be hidden or not. This flag would be ignored for the ACKDeviceTypeTriangle
 */
@property (nonatomic) BOOL shouldCaptureAudio;
/**
 *  Defines the .mp4 instructions link.
 */
@property (nonatomic) NSURL *instructionsURL;
/**
 *  Defines the instructions message.
 */
@property (nonatomic) NSString *instructionsMessage;



#pragma mark - Initializers

/**
 *  Creates an instance of the configuration object for the ecg monitor.
 *  @param deviceType The kind of hardware device that generated the recording.
 *  @param leadsConfig The recording mode applied to the device.
 *  @param filterType The filter setting for the ecg real time preview.
 *  @param maxDuration The maximum duration of the ECG recording that should be used by ECG monitor (ACKEcgMonitorViewController). If maxDuration is not explicitly defined, the default value would be 30 seconds.
 *  @param frequency The frequency of the power grid where the ECG was recorded One of {ACKMainsFilter50Hz, ACKMainsFilter60Hz}. If the frequency is not explicitly defined, the default value would be ACKMainsFrequency60Hz
 *  @param sampleRate The sampling frequency of the signal. If the sampleRate is not explicitly defines, the default value would be 300
 *  @param minDuration The minimum duration of the ECG recording. The default value is 10 seconds, if the ECG is less then this time, the recording would be reset.
 *  @param error The error object.
 *  @return An instance of the recording object. Returns nil if an invalid source option
 *  is specified in respect to the specified source. E.g., A Band source with a
 *  triangleSingleLeadAmbulatory source option would fail initialization or if invalid api key is used.
 */

- (nullable instancetype)initWithDeviceType:(ACKDeviceType)deviceType
                                leadsConfig:(ACKLeadsConfig)leadsConfig
                                 filterType:(ACKFilterType)filterType
                                maxDuration:(NSInteger)maxDuration
                                  frequency:(NSInteger)frequency
                                  sampleRate:(NSInteger)sampleRate
                                 minDuration:(NSInteger)minDuration
                                      error:(ACKError *_Nullable*_Nullable)error;

- (nullable instancetype)initWithDeviceType:(ACKDeviceType)deviceType
                                leadsConfig:(ACKLeadsConfig)leadsConfig
                                 filterType:(ACKFilterType)filterType
                                maxDuration:(NSInteger)maxDuration
                                  frequency:(NSInteger)frequency
                                      error:(ACKError *_Nullable*_Nullable)error;


- (nullable instancetype)initWithDeviceType:(ACKDeviceType)deviceType
                                leadsConfig:(ACKLeadsConfig)leadsConfig
                                 filterType:(ACKFilterType)filterType
                                maxDuration:(NSInteger)maxDuration
                                      error:(ACKError *_Nullable*_Nullable)error;

- (nullable instancetype)initWithDeviceType:(ACKDeviceType)deviceType
                                leadsConfig:(ACKLeadsConfig)leadsConfig
                                 filterType:(ACKFilterType)filterType
                                      error:(ACKError *_Nullable*_Nullable)error;

- (nullable instancetype)initWithDeviceType:(ACKDeviceType)deviceType error:(ACKError *_Nullable*_Nullable)error;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
