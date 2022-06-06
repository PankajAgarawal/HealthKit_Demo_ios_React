//
//  ACKPDPPreviewController.h
//  AliveECG
//
//  Created by Jim Qin on 8/16/16.
//  Copyright © 2016 AliveCor Inc. All rights reserved.
//

#import <QuickLook/QuickLook.h>

NS_ASSUME_NONNULL_BEGIN


@interface ACKPDPPreviewController : QLPreviewController
/**
 Instantiates a pdf view controller that displays the specified pdf. The pdf file is expected to be a temporary file
 which this view controller deletes after the view controller is dismissed.

 @param filePath The file path to the pdf file. Note, the file will be deleted after the viewcontroller is dismissed.
 @param title The navigation bar title text.
 @param supportsLandscape Defines whether landscape mode is supported or not.
 @return An instace of ACKPDPPreviewController.
 */
+ (instancetype)viewControllerWithPdfFilePath:(NSString *)filePath
                           navigationBarTitle:(NSString *)title
                            supportsLandscape:(BOOL)supportsLandscape;

+ (instancetype)viewControllerWithPdfFilePath:(NSString *)filePath navigationBarTitle:(NSString *)title;



@end

NS_ASSUME_NONNULL_END
