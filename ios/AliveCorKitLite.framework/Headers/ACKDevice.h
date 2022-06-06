//
//  ACKDevice.h
//  AliveCorKit
//
//  Created by Alex Vlasenko on 12/13/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "ACKTypes.h"

NS_ASSUME_NONNULL_BEGIN
/**
 *  This class keeps information about the device that was used to record ECG.
 */
@interface ACKDevice : NSObject

/**
 *  The string value that defines which hardware is used to record ECG.
 */
@property (nonatomic, readonly) ACKDeviceType deviceType;
/**
 *  The hardware revision. Available only for ACKDeviceTypeTriangle.
 */
@property (nonatomic, copy, readonly, nullable) NSString *hardwareRevision;
/**
 *  The firmware revision. Available only for ACKDeviceTypeTriangle.
 */
@property (nonatomic, copy, readonly, nullable) NSString *firmwareRevision;
/**
 *  The serial number. Available only for ACKDeviceTypeTriangle.
 */
@property (nonatomic, copy, readonly, nullable) NSString *serialNumber;
/**
 *  The battery level. Available only for ACKDeviceTypeTriangle.
 */
@property (nonatomic, readonly) CGFloat batteryLevel;
/**
 *  The unique identifier of the device, returns a string description of the UUID, such as "E621E1F8-C36C-495A-93FC-0C247A3E6E5F". Available only for ACKDeviceTypeTriangle.
 */
@property (nonatomic, copy, readonly, nullable) NSString *uuid;

- (instancetype)initWithDeviceType:(ACKDeviceType)deviceType;
- (instancetype)initWithDeviceType:(ACKDeviceType)deviceType uuid:(nullable NSString *)uuid;
- (instancetype)initWithDeviceType:(ACKDeviceType)deviceType hardwareRevision:(nullable NSString *)hardwareRevision firmwareRevision:(nullable NSString *)firmwareRevision serialNumber:(nullable NSString *)serialNumber batteryLevel:(CGFloat)batteryLevel uuid:(nullable NSString *)uuid;

- (instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
