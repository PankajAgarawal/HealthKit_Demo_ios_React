//
//  ACKError.h
//  ACKit
//
//  Created by Alex Vlasenko on 10/30/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ACKErrorCode) {
    /**
     * Reserved for the default state.
     */
    ACKErrorCodeNone,
    /**
     * An unknown error occurred.
     */
    ACKErrorCodeUnknown,
    /**
     * Invalid leads configuration.
     */
    ACKErrorCodeInvalidLeadsConfig,
    /**
     * Invalid ECG recording configuration.
     */
    ACKErrorCodeInvalidRecordingConfig,
    /**
     * Invalid authorization token.
     */
    ACKErrorCodeInvalidToken,
    /**
     * Invalid leads configuration.
     */
    ACKErrorCodeDeviceTypeNotSupported,
    /**
     * Bluetooth is off.  This is an error condition for Triangle devices
     */
    ACKErrorCodeBluetoothOff,
    /**
     * Bluetooth is unsupported.  This is an error condition for Triangle devices
     */
    ACKErrorCodeBluetoothUnsupported,
    /**
     * Bluetooth deivce was disconnected.  This is an error condition for Triangle devices
     */
    ACKErrorCodeBluetoothDisconnected,
    /**
     * Bluetooth pairing request wad denied.  This is an error condition for Triangle devices
     */
    ACKErrorCodeBluetoothPairingRequestDenied,
    /**
     * The RECORD_AUDIO permission is required in order to record EKG
     */
    ACKErrorCodeMicPermissionEKG,
    /**
     * The battery level of the Triangle device is too low for recording.  Only for Triangle devices
     */
    ACKErrorCodeTriangleBattery,
    /**
     * The connection to the Triangle device has failed for some reason.  Only for Triangle devices
     */
    ACKErrorCodeTiangleConnection,
    /**
     * There was mains noise in the recording, and the recording is too short to save
     */
    ACKErrorCodeMainsNoiseEarly,
    /**
     * There was an error saving an Unlock Overread.
     */
    ACKErrorCodeEvaluationInvalidOutput,
    /**
     * The Ecg recording completed, but the ecg recording duration is too short for evaluation by KardiaAI.
     */
    ACKErrorCodeEvaluationTooShort,
    /**
     * The Ecg recording completed, but the ecg can’t be evaluated by KardiaAI.
     */
    ACKErrorCodeEvaluationUnreadable,
    /**
     * The Ecg recording is completed, but the ecg kardia ai evaluation is either short or unreadable.
     */
    ACKErrorCodeElectricallyInterfered,
    /**
     * Not enough disk space to record ECG.
     */
    ACKErrorCodeNotEnoughStorage,
    /**
     * The connection to the KardiaMobile has failed or KardiaMobile encountered an error for some reason.
     */
    ACKErrorCodeAudioSession,
    /**
     * The connection to the KardiaMobile has failed or KardiaMobile encountered an error for some reason.
     */
    ACKErrorCodeAudioInsufficientPriority
};

NS_ASSUME_NONNULL_BEGIN

typedef NSString* ACKErrorDomain NS_STRING_ENUM;
extern ACKErrorDomain const ACKErrorDomainPdf;

typedef NS_ENUM(NSInteger, ACKPDFErrorCode) {
    /**
     * The ECG recording was not found at the defined path. The ECG path should be defined in the ACKEcgRecord object.
     */
    ACKPDFErrorCodeEcgPathNotFound,
    /**
     * The ECG recording is required for the PDF report.
     */
    ACKPDFErrorCodeEcgMissing,
    /**
     * The mandatory property is missing.
     */
    ACKPDFErrorCodeConfiguration,
    /**
     * The ECG file can't be opened.
     */
    ACKPDFErrorCodeFileOpen,
    /**
     * The ECG file doesn't have a recording samples.
     */
    ACKPDFErrorCodeEmptySmaples,

};


@interface ACKError : NSError

@property (nonatomic, readonly, getter=getLocalizedTitle) NSString *localizedTitle;
@property (nonatomic, readonly, getter=getLocalizedMessage) NSString *localizedMessage;
@property (nonatomic, readonly, getter=getLink) NSString *link;

+ (instancetype)errorWithCode:(ACKErrorCode)code;
+ (instancetype)errorWithCode:(ACKErrorCode)code title:(nullable NSString *)title;
+ (instancetype)errorWithCode:(ACKErrorCode)code title:(nullable NSString *)title message:(nullable NSString *)message;
+ (instancetype)errorWithCode:(ACKErrorCode)code title:(nullable NSString *)title message:(nullable NSString *)message userInfo:(NSDictionary *)userInfo;
+ (instancetype)errorWithCode:(ACKErrorCode)code title:(nullable NSString *)title message:(nullable NSString *)message link:(nullable NSString *)link;

- (instancetype)initWithCode:(ACKErrorCode)code;
- (instancetype)initWithCode:(ACKErrorCode)code title:(nullable NSString *)title;
- (instancetype)initWithCode:(ACKErrorCode)code title:(nullable NSString *)title message:(nullable NSString *)message;
- (instancetype)initWithCode:(ACKErrorCode)code title:(nullable NSString *)title message:(nullable NSString *)message link:(nullable NSString *)link;
- (instancetype)initWithCode:(ACKErrorCode)code title:(nullable NSString *)title message:(nullable NSString *)message userInfo:(NSDictionary *)userInfo;

- (instancetype)initWithDomain:(ACKErrorDomain)domain code:(NSInteger)code title:(nullable NSString *)title message:(nullable NSString *)message link:(nullable NSString *)link;

@end

NS_ASSUME_NONNULL_END
