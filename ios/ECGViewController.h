//
//  ECGViewController.h
//  rnDemo
//
//  Created by Dipak Agalcha on 31/05/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN


@protocol ECGDelegate <NSObject>
- (void) ecgRecordingFinishedWithSuccess:(NSString*)pdfPath;
- (void) ecgRecordingFinishedWithError:(NSError*)error;
@end


@interface ECGViewController : UIViewController
@property (retain, nonatomic) id<ECGDelegate> delegate;
- (void)authorizeSDK;
@end




NS_ASSUME_NONNULL_END
