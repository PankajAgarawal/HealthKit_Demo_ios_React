//
//  ACKConfiguration.h
//  AliveCorKitLite
//
//  Created by Alex Vlasenko on 12/19/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  This class keeps information about configuration and/or restrictions specific to the partner.
 */
@interface ACKConfiguration : NSObject

/**
 *  List of supported devices.
 */
@property (nonatomic, copy, readonly) NSArray<ACKDeviceType> *supportedDevices;

/**
 *  Whether or not app needs to show device confirmation dialog.
 */
@property (nonatomic, assign, readonly) BOOL showRecordingConfirmation;

/**
 *  The date when the SDK authorization should expire.
 */
@property (nonatomic, copy, readonly) NSDate *expirationDate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDictionary:(nullable NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
