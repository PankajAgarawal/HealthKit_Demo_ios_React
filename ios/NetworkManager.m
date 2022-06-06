//
//  NetworkManager.m
//  rnDemo
//
//  Created by Dipak Agalcha on 31/05/22.
//

#import "NetworkManager.h"

#import "NetworkManager.h"
#import <AFNetworking/AFNetworking.h>
#import <AliveCorKitLite/AliveCorKitLite.h>

@implementation NetworkManager

+ (void)authSDKWithCompletionHandler:(void (^)(NSError *error, ACKConfiguration *config))completionHandler
{
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    AFURLSessionManager *manager = [[AFURLSessionManager alloc] initWithSessionConfiguration:configuration];

    NSDictionary *parameters = @{@"bundleId":@"bid1", @"partnerId": @"PKtxN7pRrqW1blMCcH4Ac66ta5rflozk", @"patientMrn":@"TestApp", @"teamId":@"Fs0ZK1raZi5KidNtCyK9b4nyh6gkq4ah"};

    NSURLRequest *request = [[AFJSONRequestSerializer serializer] requestWithMethod:@"POST" URLString:@"https://sdk-auth-partner-staging.herokuapp.com/token" parameters:parameters error:nil];

    NSURLSessionDataTask *dataTask = [manager dataTaskWithRequest:request uploadProgress:nil downloadProgress:nil completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
      NSLog(@"Token Response :- %@",responseObject);
        dispatch_async(dispatch_get_main_queue(), ^{
            if (error) {
                completionHandler(error, nil);
                return;
            }
            else
            {
                [ACKManager initWithApiKey:responseObject[@"jwt"] isDebugMode:YES statusListener: ^(NSError * _Nullable error, ACKConfiguration * _Nullable config) {
                   
                    if (error == nil) {
                        //SDK is ready for work
                        completionHandler(nil, config);
                    } else {
                        if (error.code == ACKErrorCodeInvalidToken) {
                            //Attempt to fix token issue
                            [self authSDKWithCompletionHandler:completionHandler];
                        }
                    }
                }];
            }
        });
    }];
    [dataTask resume];
}


@end
