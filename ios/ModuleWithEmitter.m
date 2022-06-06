//
//  ModuleWithEmitter.m
//  rnDemo
//
//  Created by Dipak Agalcha on 02/06/22.
//

#import "ModuleWithEmitter.h"
#import <React/RCTLog.h>
#import "rnDemo-Swift.h"

@interface ModuleWithEmitter(){
  bool hasListeners;
}

@end

@implementation ModuleWithEmitter

RCT_EXPORT_MODULE(ModuleWithEmitter);

// ------------------------------------------------------------------------------------
// MARK: - init ModuleWithEmitter
// ------------------------------------------------------------------------------------
+ (id)allocWithZone:(NSZone *)zone {
    static ModuleWithEmitter *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [super allocWithZone:zone];
    });
    return sharedInstance;
}

// ------------------------------------------------------------------------------------
// MARK: - Set Observing
// ------------------------------------------------------------------------------------
- (NSArray<NSString *> *)supportedEvents {
    return @[@"onSessionConnect"];
}

// Will be called when this module's first listener is added.
-(void)startObserving {
    hasListeners = YES;
}

// Will be called when this module's last listener is removed, or on dealloc.
-(void)stopObserving {
    hasListeners = NO;
}

// ------------------------------------------------------------------------------------
// MARK: - Send Event Native Module to JaveScript Module
// ------------------------------------------------------------------------------------
- (void)sendEventwithPdfPath:(NSString*)path {
  if (hasListeners) {
    [self sendEventWithName:@"onSessionConnect" body:@{@"pdfPath": path}];
  }
}

@end

