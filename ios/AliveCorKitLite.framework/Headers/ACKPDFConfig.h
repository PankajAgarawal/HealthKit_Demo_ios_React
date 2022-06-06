//
//  ACKPDFConfig.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 4/24/20.
//  Copyright © 2020 Alex Vlasenko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKTypes.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString* ACKPaperSize NS_STRING_ENUM;
extern ACKPaperSize const ACKPaperSizeA4;
extern ACKPaperSize const ACKPaperSizeLetter;

@class ACKEcgRecord;
@class ACKPDFMetadata;
@interface ACKPDFConfig : NSObject

/**
 *  The ECG record.
 */
@property (nonatomic, copy, nullable) ACKEcgRecord *ecgRecord;
/**
 *  The patient's metadata.
 */
@property (nonatomic, copy, nullable) ACKPDFMetadata *metadata;
/**
 *  The filter type that should be applied for the ECG record. By default, filterType is equal to ACKFilterTypeEnhanced.
 */
@property (nonatomic) ACKFilterType filterType;
/**
 *  The paper size that would be applied for the PDF report. By default, paperSize is equal to ACKPaperSizeA4
 */
@property (nonatomic, copy, nullable) ACKPaperSize paperSize;
/**
 *  The xScale for the pdf report. By default, xScale = 100
 */
@property (nonatomic) NSInteger xScale;
/**
 *  The yScale for the pdf report. By defaul,t xScale = 100
 */
@property (nonatomic) NSInteger yScale;
/**
 *  The yScale for the pdf report. By defaul,t xScale = 100
 */
@property (nonatomic, copy) NSString *logoName;
/**
 *  The filename that would be assigned to the PDF report. By default, the name is equal to "ECG-<uuid>.pdf".
 */
@property (nonatomic, copy, nullable) NSString *fileName;


/**
 *  Creates the configuration object that would be used to generate a PDF report.
 *
 *  @param  ecgRecord The ECG record for which PDF report would be generated.
 *  @return class instance.
 *
 */
- (instancetype)initWithEcg:(ACKEcgRecord *)ecgRecord;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
