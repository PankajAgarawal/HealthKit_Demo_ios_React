//
//  ACKEvaluationResult.h
//  AliveCorKit
//
//  Created by Alex Vlasenko on 12/13/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  This class keeps information about ECG evaluation made by KardiaAI.
 */
@interface ACKEcgEvaluation : NSObject
/**
 *  The Kardia AI lib version that is used in AliveCorKit.
 */
@property (nonatomic, readonly) NSString *kaiVersion;
/**
 *  The result of the Kardia AI evaluation.
 */
@property (nonatomic, readonly) ACKAlgorithmDetermination kaiResult;
/**
 *  The average beats per minute measured by device.
 *  The minimum HR is 30, max 220 bpm. If the detected heart rate falls outside those bounds, OR the signal is too noisy to reliably estimate HR, 0 is returned.
 */
@property (nonatomic, readonly) CGFloat averageHeartRate;
/**
 *  Errors that occurred during evaluation if there are any.
 */
@property (nonatomic, readonly) NSArray *errors;
/**
 *  Tells whether ECG is inverted or not.
 */
@property (nonatomic) BOOL isInverted;
/**
 *  The text of the diagnosis description.
 *  Example 1: Normal.
 *  Example 2: Too short.
 */
- (NSString *)algorithmResultTitle;
/**
 *  The algorithm result description. Description includes: analysisDescription, disclaimer, additional information.
 *  Example 1: No rhythm abnormalities detected in your EKG. Kardia cannot detect signs of a heart attack. If you believe you are having a medical emergency, call emergency services.
 *  Exampe 2: our EKG recording must be at least 30 seconds to allow Instant Analysis algorithms to perform an analysis.
 */
- (NSString *)algorithmResultDescription;

/**
 *  The algorithm analysis description.
 *  Example: No rhythm abnormalities detected in your EKG.
 */
- (NSString *)analysisDescription;

/**
 *  The disclaimer.
 *  Example: "%@ cannot detect signs of a heart attack. If you believe you are having a medical emergency, call emergency services.\nDO NOT change your medication without talking to your doctor."
 */
- (NSString *)disclaimer;

/**
 *  The additional information that may be added to the particular analysis results.
 *  Example: For the ACAlgorithmResultTypeUnclassified KAI result additional information would be: "Atrial fibrillation was not detected and your EKG does not fall under the algorithmic classifications of Normal, Bradycardia, or Tachycardia. This may be caused by other arrhythmias, unusually fast or slow heart rates, or poor quality recordings."
 */
- (NSString *)additionaInformation;

/**
 *  The algorithm result descriptve title. TODO: add example
 *  Example 1: Normal
 *  Example 2: Your EKG recording was interrupted
 */
- (NSString *)algorithmResultDescriptiveTitle;
/**
 *  The color of the diagnosis description.
 */
- (UIColor *)algorithmResultColor;

/**
 Map a set of booleans from a legacy ecg object to an EcgAlgorithmDetermination.

 @param afibDetected The ECG's afibDetected bit
 @param nsrDetected The ECG's nsrDetected bit
 @param noiseDetected The ECG's noiseDetected bit
 @param durationMilliseconds The ECG's recorded duration.
 @return The new determination that was mapped to.
 */
+ (ACKAlgorithmDetermination)ecgAlgorithmDeterminationForAfibDetected:(BOOL)afibDetected
                                                          nsrDetected:(BOOL)nsrDetected
                                                        noiseDetected:(BOOL)noiseDetected
                                                 durationMilliseconds:(NSInteger)durationMilliseconds;

- (instancetype)initWithKaiVersion:(NSString *)kaiVersion kaiResult:(NSString *)kaiResult averageHeartRate:(CGFloat)averageHeartRate isInverted:(BOOL)isInverted errors:(NSArray * _Nullable)errors;

- (instancetype)initWithKaiVersion:(NSString *)kaiVersion kaiResult:(NSString *)kaiResult averageHeartRate:(CGFloat)averageHeartRate isInverted:(BOOL)isInverted;


@end

NS_ASSUME_NONNULL_END
