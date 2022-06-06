//
//  ACKTypes.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 1/8/20.
//  Copyright © 2020 AliveCor, Inc. All rights reserved.
//

#ifndef ACKTypes_h
#define ACKTypes_h

/**
 *  The filter type that will be applied to the ECG recording.
 */
typedef NS_ENUM(NSInteger, ACKFilterType) {
    ACKFilterTypeEnhanced = 1,
    ACKFilterTypeOriginal
};

/**
 *  The recording mode applied to the device (Either single lead of six lead).
 */
typedef NS_ENUM(NSInteger, ACKLeadsConfig) {
    ACKLeadsConfigSingle = 1,
    ACKLeadsConfigSix
};

/**
 *  The frequency of the power grid where the ECG was recorded One of {ACKMainsFilter50Hz, ACKMainsFilter60Hz}
 */
typedef NS_ENUM(NSUInteger, ACKMainsFrequency) {
    ACKMainsFrequency60Hz = 60,
    ACKMainsFrequency50Hz = 50,
};

/**
 *  The sampling frequency of the signal
 */
typedef NS_ENUM(NSUInteger, ACKSampleRate) {
    ACKSampleRate125Hz = 0,
    ACKSampleRate250Hz,
    ACKSampleRate300Hz,
    ACKSampleRate500Hz,
    ACKSampleRate600Hz,
};

/**
 *  Represents the results of both the KardiaAI determination and corresponding status code for the determination.
 */
typedef NSString * ACKAlgorithmDetermination NS_STRING_ENUM;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationNoAnalysis;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationUnreadable;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationTooShort;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationTooLong;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationUnclassified;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationNormal;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationAtrialFibrillation;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationBradycardia;
extern ACKAlgorithmDetermination _Nonnull ACKAlgorithmDeterminationTachycardia;

/**
 *  The kind of the device used for the ECG recording.
 */
typedef NSString * ACKDeviceType NS_STRING_ENUM;
extern ACKDeviceType _Nonnull ACKDeviceTypeUnknown;
extern ACKDeviceType _Nonnull ACKDeviceTypeTriangle;
extern ACKDeviceType _Nonnull ACKDeviceTypeMobile;
extern ACKDeviceType _Nonnull ACKDeviceTypeBand;
extern ACKDeviceType _Nonnull ACKDeviceTypeSakuraOne;


#endif /* ACKTypes_h */
