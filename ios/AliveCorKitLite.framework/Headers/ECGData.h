//
//  ECGData.h
//  ACEcgMonitor
//
//  Created by Alexander Valys on 11/20/16.
//  Copyright © 2016 AliveCor, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef SInt16 ECGSample;

static const ECGSample kECGNullSample = INT16_MAX;

typedef enum {
    kECGRecordingModeSingleLead,
    kECGRecordingModeDualLead
} ECGRecordingMode;

typedef enum {
    kECGDisplayModeSingleLead,
    kECGDisplayModeDualLead,
    kECGDisplayModeTriLead,
    kECGDisplayModeSixLead
} ECGDisplayMode;


@interface ECGRecordingSettings : NSObject

+ (NSInteger)leadCountForECGDisplayMode:(ECGDisplayMode)ecgDisplayMode;

@end

// ECGFrame represents synchronized ECG data across multiple channels
struct ECGFrame {
    ECGSample lead1;
    ECGSample lead2;
    ECGSample lead3;
    ECGSample aVR;
    ECGSample aVL;
    ECGSample aVF;
};

NS_ASSUME_NONNULL_END
