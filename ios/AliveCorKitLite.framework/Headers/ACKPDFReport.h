//
//  PDFFactory.h
//  AliveECG
//
//  Created by Ned Fox on 5/22/14.
//  Copyright (c) 2014 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ACKPDFConfig;
@class ACKError;
@interface ACKPDFReport : NSObject

/**
 *  Method generates the PDF report with the specific configuration.
 *
 *  @param  config The PDF report configuration.
 *  @param  error an error that occured when trying to generate a PDF.
 *  @return class instance.
 *
 */
+ (nullable NSString *)pdfPathForConfig:(ACKPDFConfig *)config error:(ACKError * _Nullable *_Nullable)error;

+ (nullable NSString *)pdfPathForConfig:(ACKPDFConfig *)config;

@end

NS_ASSUME_NONNULL_END
