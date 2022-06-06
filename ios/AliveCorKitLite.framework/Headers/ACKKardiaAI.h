//
//  ACKKardiaAI.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 1/8/20.
//  Copyright © 2020 AliveCor, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKTypes.h"
#import "ACKEcgEvaluation.h"
#import "ACKError.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Helps to evaluate ECG recording using Kardia AI.
*/
@interface ACKKardiaAI : NSObject

+ (instancetype)initWithError:(ACKError * _Nullable *_Nullable)error;

/**
 * Evaluates ECG record with given samples(millivolts) from a C-style array.  Samples are copied into internal storage.
 *
 * @param samplesMV A pointer to an array of samples.  Double-precision millivolts.  Samples will be copied.
 * @param length The number of samples.
 * @param sampleRate The sampling frequency of the signal.
 * @param frequency The frequency of the power grid where the ECG was recorded One of {ACKMainsFilter50Hz, ACKMainsFilter60Hz}
 *
 * @return The Kardia AI evaluation results
 */
- (ACKEcgEvaluation *)evaluateMVSamples:(const double *)samplesMV length:(NSUInteger)length sampleRate:(ACKSampleRate)sampleRate frequency:(ACKMainsFrequency)frequency;

- (ACKEcgEvaluation *)evaluateATCSamples:(const short *)samplesATC length:(NSUInteger)length sampleRate:(ACKSampleRate)sampleRate frequency:(ACKMainsFrequency)frequency;

- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
