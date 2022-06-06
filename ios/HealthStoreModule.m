//
//  HealthModul.m
//  rnDemo
//
//  Created by Pankaj on 07/04/22.
//

#import "HealthStoreModule.h"
#import <React/RCTLog.h>
#import <React/RCTEventEmitter.h>
#import "rnDemo-Swift.h"
#import "ECGViewController.h"
#import "AppDelegate.h"
#import "ModuleWithEmitter.h"

@interface HealthStoreModule() <ECGDelegate>
{
  AppDelegate *appdelegate;
}
@property (strong, nonatomic) HealthDataManager *dataManager;

@end


@implementation HealthStoreModule


// ------------------------------------------------------------------------------------
// HealthStore init
// ------------------------------------------------------------------------------------
-(instancetype)init
{
  self = [super init];
  
  if (self)
  {
    self.dataManager = [[HealthDataManager alloc] init];
  }
  
  return  self;
}

RCT_EXPORT_MODULE(HealthStore);

// ------------------------------------------------------------------------------------
// MARK: - Get Steps Data
// ------------------------------------------------------------------------------------

RCT_EXPORT_METHOD(getStepsFrom:(NSString *)startDate
                  endDate:(NSString *)endDate
                  resolver: (RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
  
  // Permission request
  [self.dataManager requestAuth];
  
  // Start to end Date Setup
  NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
  [dateFormat setDateFormat:@"dd-MM-yyyy"];
  NSDate *today = [dateFormat dateFromString:endDate];
  NSDate *lastMonth = [dateFormat dateFromString:startDate];
  
  // Get steps Data
  [self.dataManager getStepsFrom:today To:lastMonth completion:^(NSArray<NSDictionary<NSString *,NSNumber *> *> * record, NSError * error) {
    
    if(record)
    {
      // Get all steps data
      NSArray *stepsData = [NSArray arrayWithObjects:record, nil];
      
      // Convert stepsdata (NSArray) to jsondata (NSData)
      NSData *jsonData = [NSJSONSerialization dataWithJSONObject:stepsData options:NSJSONWritingPrettyPrinted error:&error];
      
      // Convert jsondata to Jsonstring
      NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
      
      // Send Json String data to rect module with the help of handler
      resolve(jsonString);
      
    }
    else
    {
      // Error handler
      reject(@"",@"",error);
    }
    
  }];
  
}

// ------------------------------------------------------------------------------------
// MARK: - Get Distances Data
// ------------------------------------------------------------------------------------

RCT_EXPORT_METHOD(getDistanceDataFrom:(NSString *)startDate
                  endDate:(NSString *)endDate
                  resolver: (RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
  
  // Permission request
  [self.dataManager requestAuth];
  
  // Start to end Date Setup
  NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
  [dateFormat setDateFormat:@"dd-MM-yyyy"];
  NSDate *today = [dateFormat dateFromString:endDate];
  NSDate *lastMonth = [dateFormat dateFromString:startDate];
  
  // Get distances data
  [self.dataManager getDistanceFrom:today To:lastMonth completion:^(NSArray<NSDictionary<NSString *,NSNumber *> *> * record, NSError * error) {
    
    if(record)
    {
      // Get all distances data
      NSArray *distancesData = [NSArray arrayWithObjects:record, nil];
      
      // Convert stepsdata (NSArray) to jsondata (NSData)
      NSData *jsonData = [NSJSONSerialization dataWithJSONObject:distancesData options:NSJSONWritingPrettyPrinted error:&error];
      
      // Convert jsondata to Jsonstring
      NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
      
      // Send Json String data to rect module with the help of handler
      resolve(jsonString);
      
    }
    else
    {
      // Error handler
      reject(@"",@"",error);
    }
    
  }];
  
}

// ------------------------------------------------------------------------------------
// MARK: - Get Burn Calories Data
// ------------------------------------------------------------------------------------

RCT_EXPORT_METHOD(getBurnCaloriesFrom:(NSString *)startDate
                  endDate:(NSString *)endDate
                  resolver: (RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
  
  // Permission request
  [self.dataManager requestAuth];
  
  // Start to end Date Setup
  NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
  [dateFormat setDateFormat:@"dd-MM-yyyy"];
  NSDate *today = [dateFormat dateFromString:endDate];
  NSDate *lastMonth = [dateFormat dateFromString:startDate];
  
  // Get burn calories data
  [self.dataManager getBurnCaloriesFrom:today To:lastMonth completion:^(NSArray<NSDictionary<NSString *,NSNumber *> *> * record, NSError * error) {
    
    if(record)
    {
      // Get all burn calories data
      NSArray *burnCaloriesData = [NSArray arrayWithObjects:record, nil];
      
      // Convert stepsdata (NSArray) to jsondata (NSData)
      NSData *jsonData = [NSJSONSerialization dataWithJSONObject:burnCaloriesData options:NSJSONWritingPrettyPrinted error:&error];
      
      // Convert jsondata to Jsonstring
      NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
      
      // Send Json String data to rect module with the help of handler
      resolve(jsonString);
      
    }
    else
    {
      // Error handler
      reject(@"",@"",error);
    }
    
  }];
  
}

// ------------------------------------------------------------------------------------
// MARK: - Get Current Heart Rate Data
// ------------------------------------------------------------------------------------

RCT_EXPORT_METHOD(getCurrentHeartRate:
                  resolver: (RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
  
  // Permission request
  [self.dataManager requestAuth];

  // Get Current Heart Rate
  [self.dataManager getCurrentHeartRatesWithCompletion:^(NSDictionary<NSString *,id> * record, NSError * error) {
    
    if(record)
    {
      // Convert HeartRate data (NSDictionary) to jsondata (NSData)
      NSData *jsonData = [NSJSONSerialization dataWithJSONObject:record options:NSJSONWritingPrettyPrinted error:&error];
      
      // Convert jsondata to Jsonstring
      NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];

      // Send Json String data to rect module with the help of handler
      resolve(jsonString);
      
    }
    else
    {
      // Error handler
      reject(@"",@"",error);
    }

  }];
  
}

// ------------------------------------------------------------------------------------
// MARK: - Get ECG Data
// ------------------------------------------------------------------------------------
RCT_EXPORT_METHOD(getECGData:
                  resolver: (RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
  
  NSLog(@"Get ECG Data Call");
  
  dispatch_async(dispatch_get_main_queue(), ^{
    
    ECGViewController *ecgVC = [[ECGViewController alloc] init];
    
    UINavigationController* contactNavigator = [[UINavigationController alloc] initWithRootViewController:ecgVC];
    
    self->appdelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    
    ecgVC.delegate = self;
    
    [ecgVC authorizeSDK];
    
    [self->appdelegate.window.rootViewController presentViewController:contactNavigator animated:NO completion:nil];
    
  });
}

// ------------------------------------------------------------------------------------
// MARK: - ECG VC Delegate
// ------------------------------------------------------------------------------------
- (void)ecgRecordingFinishedWithSuccess:(NSString *)pdfPath
{
  ModuleWithEmitter *module = [ModuleWithEmitter allocWithZone:nil];
  [module sendEventwithPdfPath:pdfPath];
  
  [appdelegate.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
  
}

- (void)ecgRecordingFinishedWithError:(NSError *)error
{
  [appdelegate.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
}

@end
