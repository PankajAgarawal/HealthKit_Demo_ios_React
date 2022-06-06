//
//  ACKPDFInteractionController.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 4/24/20.
//  Copyright © 2020 Alex Vlasenko. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ACKPDFConfig;
@class ACKError;

/**
 *  Methods for managing PDF creation progress.
 */
@class ACKPDFInteractionController;
@protocol ACKPDFInteractionControllerDelegate <NSObject>

/**
 *  Informs the delegate that PDF generation will be started.
 *
 *  @param  controller The reference to the ACKPDFInteractionController controller.
 *  @param  config The configuration of the PDF report.
 *
 */
- (void)pdfInteractionController:(ACKPDFInteractionController * _Nonnull)controller willPresentPdfForConfig:(ACKPDFConfig *)config;

/**
 *  Informs the delegate whether PDF report for the specific ecg record, was created or not.
 *
 *  @param  controller The reference to the ACKPDFInteractionController controller.
 *  @param  config The configuration of the PDF report.
 *  @param  pdfPath The file path to the PDF report.
 *  @param  error an error that occured when trying to display PDF.
 *
 */
- (void)pdfInteractionController:(ACKPDFInteractionController * _Nonnull)controller didPresentPdf:(NSString * _Nullable)pdfPath forConfig:(ACKPDFConfig *)config withError:(ACKError * _Nullable)error;

/**
 *  Asks  the delegate to encrypt the PDF report.
 *
 *  @param  controller The reference to the ACKPDFInteractionController controller.
 *  @param  password The password for PDF encryption.
 *  @param  config The PDF configuration.
 *  @param  completionHandler returns file path to the encrypted PDF file or error if encryption failed.
 *
 */
- (void)pdfInteractionController:(ACKPDFInteractionController * _Nonnull)controller encryptPDFWithPassword:(NSString * _Nullable)password withConfig:(ACKPDFConfig *)config completionHandler:(void (^)(NSError * _Nullable error, NSString * _Nullable pdfPath))completionHandler;


@end

/**
 *  The controller for managing the PDF creation process.
 */
@interface ACKPDFInteractionController : NSObject

@property (nonatomic, weak, nullable) id<ACKPDFInteractionControllerDelegate> delegate;

/**
 *  Creates the instance of the InteractionController.
 *
 *  @param  config The PDF report configuration.
 *  @param  error an error that occured when trying to create the instance of the class.
 *  @return class instance.
 *
 */
- (instancetype)initWithConfig:(ACKPDFConfig *)config error:(ACKError * _Nullable *_Nullable)error;
- (instancetype)initWithConfig:(ACKPDFConfig *)config;
- (instancetype)init NS_UNAVAILABLE;

/**
 *  Presents the instance of the ACKPDPPreviewController above predefined view controller.
 *
 *  @param  config The PDF report configuration.
 *  @param  viewController The parent UIViewController. ACKPDPPreviewController will be discplayed above viewController
 *  @param  supportsLandscape Defines whether landscape mode is supported or not.
 *  @param  showEncryptionPrompt Enable or disable encryption prompt in the PDF report flow..
 *  @param  encryptionRequired For some countries(NORWAY) encryption is mandatory. Application is supposed to manage encryption logic.
 *
 */
- (void)presentPdfPreviewForConfig:(ACKPDFConfig *)config
                  onViewController:(__kindof UIViewController *)viewController
                 supportsLandscape:(BOOL)supportsLandscape
              showEncryptionPrompt:(BOOL)showEncryptionPrompt
                encryptionRequired:(BOOL)encryptionRequired;
@end

NS_ASSUME_NONNULL_END
