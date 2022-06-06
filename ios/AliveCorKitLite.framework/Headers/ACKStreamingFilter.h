//
//  ACKStreamingFilter.h
//  AliveCorKitLite
//
//  Created by Oleksandr Vlasenko on 5/18/21.
//  Copyright © 2021 Alex Vlasenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class ACKError;
@interface ACKStreamingFilter : NSObject

/**
 * Create an instance of the ACKStreamingFilter.
 *
 * @param filterType a filter type that needs to be used.
 * @param sampleRate The sampling frequency of the signal
 * @param mainsFrequency The frequency of the power grid where the ECG was recorded One of {ACKMainsFilter50Hz, ACKMainsFilter60Hz}
 * @param error The error encountered while instantiating ACKStreamingFilter
 *
 * @return Instance of the ACKStreamingFilter
 */
- (instancetype)initWithFilterType:(ACKFilterType)filterType
                        sampleRate:(ACKSampleRate)sampleRate
                    mainsFrequency:(ACKMainsFrequency)mainsFrequency
                             error:(ACKError * _Nullable *_Nullable)error;

/**
 * Process a sample.
 *
 * @param sample An ECG sample in mV.
 *
 * @return A filtered ECG sample.
 */
- (double)filterSample:(double)sample;

@end

NS_ASSUME_NONNULL_END
