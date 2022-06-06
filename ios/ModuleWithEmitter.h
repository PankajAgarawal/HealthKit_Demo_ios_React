//
//  ModuleWithEmitter.h
//  rnDemo
//
//  Created by Dipak Agalcha on 02/06/22.
//

#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

NS_ASSUME_NONNULL_BEGIN

@interface ModuleWithEmitter : RCTEventEmitter <RCTBridgeModule>
+ (id)allocWithZone:(struct _NSZone *)zone;
- (void)sendEventwithPdfPath:(NSString*)path;
@end

NS_ASSUME_NONNULL_END
