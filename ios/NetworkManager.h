//
//  NetworkManager.h
//  rnDemo
//
//  Created by Dipak Agalcha on 31/05/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ACKConfiguration;
@interface NetworkManager : NSObject

+ (void)authSDKWithCompletionHandler:(void (^)(NSError *error, ACKConfiguration *config))completionHandler;

@end

NS_ASSUME_NONNULL_END
