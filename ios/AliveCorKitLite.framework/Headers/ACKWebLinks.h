//
//  ACKWebLinks.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 4/25/20.
//  Copyright © 2020 Alex Vlasenko. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ACKWebLinks : NSObject

/**
 *  The bluetooth authorization error help link. Help link is used on the  Bluetooth error HUD. Default value:
 *  https://www.alivecor.com/app-redirect/i-need-help-pairing-error-bt-not-authorized
 */
@property(nonatomic, copy, nullable) NSString *bluetoothNotAuthorized;

/**
 *  The generic bluetooth error  help link. Help link is used on the  Bluetooth error HUD. Default value:
 *  https://www.alivecor.com/app-redirect/i-need-help-bluetooth-error
 */
@property(nonatomic, copy, nullable) NSString *bluetoothError;

/**
 *  The microphone access help link. Help link is used on the microphone access HUD. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-mic-error-ios
 */
@property(nonatomic, copy, nullable) NSString *microphoneAccess;
/**
 *  The instructions help link. Help link is used on the kardia mobile instructions view. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-recording-km
 */
@property(nonatomic, copy, nullable) NSString *kardiaMobileSingleLead;
/**
 *  The electrical interference help link. Help link is used on the electrical interference error HUD. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-electrical-interference
 */
@property(nonatomic, copy, nullable) NSString *electricalInterference;
/**
 *  The too short recording help link (ECG recording is between 10 and 30 seconds is too short for evaluation). Help link is used on the too short HUD. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-too-short
 */
@property(nonatomic, copy, nullable) NSString *tooShort;
/**
 *  The triangle not foung help link. Help link is used on the triangle not found error HUD. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-pre-recording-error-device-not-found
 */
@property(nonatomic, copy, nullable) NSString *triangleNotFound;
/**
 *  The replace battery help link. Help link is used on the replace battery error HUD. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-battery-critical
 */
@property(nonatomic, copy, nullable) NSString *replaceBattery;
/**
 *  The instructions help link. Help link is used on the  triangle instructions view for the six lead mode. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-recording-6l-six-lead
 */
@property(nonatomic, copy, nullable) NSString *triangleSixLead;
/**
 *  The instructions help link. Help link is used on the  triangle instructions view for the single lead mode. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-recording-6l-single-lead
 */
@property(nonatomic, copy, nullable) NSString *triangleSingleLead;
/**
 *  The unreadbale recording help link (ECG recording is between 10 and 30 seconds is too short for evaluation). Help link is used on the unreadable HUD. Default link value:
 *  https://www.alivecor.com/app-redirect/i-need-help-unreadable
 */
@property(nonatomic, copy, nullable) NSString *unreadable;


@end

NS_ASSUME_NONNULL_END
