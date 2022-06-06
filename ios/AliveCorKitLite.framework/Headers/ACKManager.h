//
//  AliveCorKitManager.h
//  AliveCorKitLite
//
//  Created by Alex Vlasenko on 12/19/19.
//  Copyright © 2019 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKDevice.h"
#import "ACKConfiguration.h"
#import "ACKError.h"
#import "ACKWebLinks.h"

typedef void (^ACKStatusListener)(NSError * _Nullable error, ACKConfiguration *_Nullable config);

NS_ASSUME_NONNULL_BEGIN

/**
 *  This class is an entry point for the SDK usage both for AliveCorKitLite and AliveCorKit.
 *  The consumer must initialize this class during app startup with the partner’s API key.
 *  Partner’s API key is used to validate the authenticity of the partner. All interactions with the library will fail if this class will not be initialized.
 *
 */
@interface ACKManager : NSObject

/**
 *  The  version of the SDK.
 */
@property (nonatomic, readonly) NSString *version;
/**
 *  The API key that is being used to authorize SDK usage.
 */
@property (nonatomic, readonly) NSString *apiKey;
/**
 *  The applications name
 */
@property (nonatomic, readonly) NSString *appName;
/**
 *  The path to the directory where recorded ecgs are stored.
 */
@property (nonatomic, readonly) NSString *ecgFilesDirectory;
/**
 *  Defines configuration and/or restrictions specific to the partner.
 */
@property (nonatomic, readonly) ACKConfiguration *configuration;
/**
 *  Defines web links that would be used on the HUD screens
 */
@property (nonatomic) ACKWebLinks *links;
/**
 *  Tells whether the SDK is running in debug mode or not.
 */
@property (nonatomic, readonly) BOOL isDebugMode;


+ (instancetype)sharedInstance;

/**
 *  Initializes the library with the API key and listens to the provisioning state of the SDK. If an API key is valid and SDK usage is allowed a config object would be returned in the listener, otherwise error object would be emitted.
 */
+ (instancetype)initWithApiKey:(NSString *)apiKey isDebugMode:(BOOL)isDebugMode statusListener:(nullable ACKStatusListener)statusListener;

/**
 *  Initialises the library with the API key and application's name and listens to the provisioning state of the SDK. If an API key is valid and SDK usage is allowed a config object would be returned in the listener, otherwise error object would be emitted.
 */
+ (instancetype)initWithApiKey:(NSString *)apiKey isDebugMode:(BOOL)isDebugMode appName:(NSString *)appName statusListener:(nullable ACKStatusListener)statusListener;

/**
 *  Refresh API key, if auth token has expired.
 */
- (void)updateApiKey:(NSString *)apiKey;

/**
 *  Resets paired device.
 */
- (void)forgetDevice;

/**
 *  Connects to the server and authorises the SDK usage.
 *  If for some reason SDK can't be provisioned, the client app would get an error object, otherwise, the client's application should get a configuration object with the list of allowed devices and expiration date.
 */
- (void)checkStatusWithListener:(nullable ACKStatusListener)statusListener;

- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
