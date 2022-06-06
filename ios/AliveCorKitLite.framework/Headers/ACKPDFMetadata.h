//
//  ACKPDFMetadata.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 4/23/20.
//  Copyright © 2020 Alex Vlasenko. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ACKPDFMetadata : NSObject

/**
 *  The patient's first name.
 */
@property (nonatomic, copy, nullable) NSString *patientFirstName;
/**
 *  The patient's first last name.
 */
@property (nonatomic, copy, nullable) NSString *patientLastName;
/**
 *  The patient's date date of birth.
 */
@property (nonatomic, copy, nullable) NSString *patientDateOfBirth;
/**
 *  The patient's age.
 */
@property (nonatomic, copy, nullable) NSString *patientAge;
/**
 *  The patient's notes.
 */
@property (nonatomic, copy, nullable) NSString *notes;
/**
 *  The patient's tags.
 */
@property (nonatomic, copy, nullable) NSString *tags;


- (BOOL)isEqualToACKPDFMetaData:(ACKPDFMetadata *)metadata;

@end

NS_ASSUME_NONNULL_END
