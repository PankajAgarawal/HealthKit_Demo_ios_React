//
//  ECGViewController.m
//  rnDemo
//
//  Created by Dipak Agalcha on 31/05/22.
//

#import "ECGViewController.h"
#import <AliveCorKitLite/AliveCorKitLite.h>
#import <MBProgressHUD/MBProgressHUD.h>
#import "NetworkManager.h"
#import "NavigationController.h"
@interface ECGViewController () <ACKEcgMonitorDelegate, ACKEcgPreviewDelegate, ACKPDFInteractionControllerDelegate>
{
  ACKConfiguration *ackConfi;
  BOOL firstTimeInit;
}
@property (nonatomic, nullable, copy) ACKEcgRecord *record;
@property (nonatomic, nullable) UIViewController *pdfOwnerViewController;
@end

@implementation ECGViewController

//--------------------------------------------------------------------------------------------
#pragma mark  Life cycle
//--------------------------------------------------------------------------------------------

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

//--------------------------------------------------------------------------------------------
#pragma mark  Authorized SDK
//--------------------------------------------------------------------------------------------

- (void) authorizeSDK {
  
  dispatch_async(dispatch_get_main_queue(), ^{
    MBProgressHUD* hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.label.text = @"Provisioning...";
  });
  
  [NetworkManager authSDKWithCompletionHandler:^(NSError * _Nonnull error, ACKConfiguration * _Nonnull config) {
    
    dispatch_async(dispatch_get_main_queue(), ^{
      if (error == nil) {
        self->ackConfi = config;
        if (!self->firstTimeInit) {
          self->firstTimeInit = YES;
          [self startEcgMonitor];
        }
        
      } else {
        [self showAlertWithTitle:@"Error" message:error.localizedDescription];
      }
      [MBProgressHUD hideHUDForView:self.view animated:YES];
    });
  }];
  
}

//--------------------------------------------------------------------------------------------
#pragma mark  Start ECG Monitor
//--------------------------------------------------------------------------------------------

- (void)startEcgMonitor {
  
    __weak __typeof__(self) weakSelf = self;
  
    [[ACKManager sharedInstance] checkStatusWithListener:^(NSError * _Nullable error, ACKConfiguration * _Nullable config) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (error == nil) {
              [weakSelf presetEcgRecordingController];
            } else {
                [self showAlertWithTitle:@"Configuration Error" message:@"Looks like SDK was not provisioned, check ACKManager methods to get more details"];
                return;
            }
        });
    }];
}

- (void)presetEcgRecordingController {
  
  NSInteger duration = 30;
  ACKDeviceType deviceType = (ACKDeviceTypeTriangle);
  ACKLeadsConfig leadsConfig = (ACKLeadsConfigSix);
  ACKFilterType filterType = (ACKFilterTypeEnhanced);
  
  if (!duration || !deviceType || !leadsConfig || !filterType) {
    [self showAlertWithTitle:@"Settings Error" message:@"Looks like some settings are missing"];
    return;
  }
  
  ACKError *error;
  ACKEcgRecordingConfig *config = [[ACKEcgRecordingConfig alloc] initWithDeviceType:deviceType leadsConfig:leadsConfig filterType:filterType maxDuration:duration error:&error];
  
  if (!config && error) {
    [self showAlertWithTitle:@"Settings Error" message:error.localizedTitle];
    return;
  }
  
  ACKEcgMonitorViewController *monitorViewController = [[ACKEcgMonitorViewController alloc] initWithConfig:config];
  monitorViewController.delegate = self;
  
  if (self.navigationController) {
    NavigationController *newController = [NavigationController controllerWithOpaqueNavigationBarAndRootViewController:monitorViewController];
    [self presentViewController:newController animated:YES completion:nil];
  }
  
}


//--------------------------------------------------------------------------------------------
#pragma mark  Alert
//--------------------------------------------------------------------------------------------


- (void)showAlertWithTitle:(NSString *)title message:(NSString*)message {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
    }];
    [alert addAction:action];
    [self presentViewController:alert animated:YES completion:^{
    }];
}


//--------------------------------------------------------------------------------------------
#pragma mark  ACKEcgMonitorDelegate
//--------------------------------------------------------------------------------------------

- (BOOL)showCancelButtonInEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController {
    return YES;
}

- (BOOL)showSettingsButtonInEcgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController {
    return NO;
}

- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didCompleteRecording:(nullable ACKEcgRecord *)record {

    UIViewController *vc;
   
    ACKEcgPreviewViewController *resultViewController = [[ACKEcgPreviewViewController alloc] initWithRecord:record];
    resultViewController.delegate = self;
    vc = resultViewController;
    
    if (viewController.navigationController) {
        [(UINavigationController *)viewController.navigationController pushViewController:vc animated:YES];
    }
    
    // PDF report will be displyed above this ViewController
    self.pdfOwnerViewController = vc;
    // Need to memorize record for PDF report
    self.record = record;
}

- (void)ecgMonitorViewController:(ACKEcgMonitorViewController * _Nonnull)viewController didCancelWithError:(nullable ACKError *)error {
  
  [self.delegate ecgRecordingFinishedWithError:error];
  
  [viewController dismissViewControllerAnimated:true completion:^{
  }];
  
}


//--------------------------------------------------------------------------------------------
#pragma mark  ACKEcgPreviewDelegate
//--------------------------------------------------------------------------------------------

- (void)ecgPreviewViewController:(ACKEcgPreviewViewController *)viewController didFinishWithRecord:(ACKEcgRecord *)record {
  
  NSLog(@"Record Average Heart Rate:- %f",record.evaluationResult.averageHeartRate);
  
  ACKPDFConfig *config = [[ACKPDFConfig alloc] initWithEcg:record];
  NSString *pdfPath = [ACKPDFReport pdfPathForConfig:config];
  NSLog(@"PDF PATH:- %@",pdfPath);
  
  [self.delegate ecgRecordingFinishedWithSuccess:pdfPath];
  
  [viewController dismissViewControllerAnimated:true completion:^{
  }];
}

- (void)ecgPreviewViewController:(ACKEcgPreviewViewController *)viewController didCancelWithRecord:(ACKEcgRecord *)record {
  
  NSError *err;
  [self.delegate ecgRecordingFinishedWithError:err];
  
  [viewController dismissViewControllerAnimated:YES completion:^{
    //[self dismissViewControllerAnimated:false completion:nil];
  }];
}

- (BOOL)showDoneButtonInEcgPreviewViewController:(ACKEcgPreviewViewController *)viewController {
    return YES;
}

- (BOOL)showCancelButtonInEcgPreviewViewController:(ACKEcgPreviewViewController *)viewController {
    return YES;
}

//--------------------------------------------------------------------------------------------
#pragma mark ACKPDFInteractionControllerDelegate
//--------------------------------------------------------------------------------------------

- (void)pdfInteractionController:(ACKPDFInteractionController * _Nonnull)controller willPresentPdfForConfig:(ACKPDFConfig *)config {
    NSLog(@"AliveCorKitLiteController willPresentPdfForConfig");
}

- (void)pdfInteractionController:(ACKPDFInteractionController * _Nonnull)controller didPresentPdf:(NSString * _Nullable)pdfPath forConfig:(ACKPDFConfig *)config withError:(ACKError * _Nullable)error {
    NSLog(@"AliveCorKitLiteController didPresentPdf");
}

- (void)pdfInteractionController:(ACKPDFInteractionController * _Nonnull)controller encryptPDFWithPassword:(NSString * _Nullable)password withConfig:(nonnull ACKPDFConfig *)config completionHandler:(nonnull void (^)(NSError * _Nullable, NSString * _Nullable))completionHandler {
    NSLog(@"AliveCorKitLiteController encryptPDFWithPassword");
}


@end
