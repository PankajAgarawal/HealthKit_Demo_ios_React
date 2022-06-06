//
//  ACKBluetoothPairingControllerDelegate.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 5/17/20.
//  Copyright © 2020 Alex Vlasenko. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ACKDevice;
@class ACKError;
@class ACKBluetoothPairingController;

@protocol ACKBluetoothPairingControllerDelegate

- (void)bluetoothControllerReadyToScan:(ACKBluetoothPairingController *)bluetoothDeviceController;
- (void)bluetoothDeviceController:(ACKBluetoothPairingController *)bluetoothDeviceController
        didDiscoverTriangleDevice:(ACKDevice *)device;
- (void)bluetoothDeviceControllerPairingDidSucceed:(ACKBluetoothPairingController *)bluetoothDeviceController;
- (void)bluetoothDeviceControllerDeviceNotFound:(ACKBluetoothPairingController *)bluetoothDeviceController;
- (void)bluetoothDeviceController:(ACKBluetoothPairingController *)bluetoothDeviceController
      didEncounterConnectionError:(ACKError *)error;

@end

@interface ACKBluetoothPairingController : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithDelegate:(id<ACKBluetoothPairingControllerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
