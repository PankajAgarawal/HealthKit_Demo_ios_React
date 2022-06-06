//
//  ECGFile.h
//  AliveECG
//
//  Created by Kim Barnett on 1/06/10.
//  Copyright 2010 AliveCor Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECGData.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    kECGFileLead1,
    kECGFileLead2,
    kECGFileLead3,
    kECGFileLead4,
    kECGFileLead5,
    kECGFileLead6
} ECGFileLead;

typedef struct {
    char dateRecorded[32];
    char recordingUUID[40];
    char phoneUDID[44];
    char phoneModel[32];
    char recorderSW[32];
    char recorderHW[32];
    char location[52];
}AliveFileInfo;

typedef struct {
    UInt8 format;
    UInt16 samplingRate;
    UInt16 resolution_nV;
    UInt8 flags;
    UInt16 reserved;
}AliveFileFormat;

@interface ECGFile : NSObject

@property (nonatomic, assign) AliveFileInfo *aliveFileInfo;
@property (nonatomic, assign) AliveFileFormat *aliveFileFormat;
@property (nonatomic, assign) UInt32 totalSamples;
@property (nonatomic, assign) UInt32 totalSamples2;
@property (nonatomic, assign) UInt32 totalSamples3;
@property (nonatomic, assign) UInt32 totalSamples4;
@property (nonatomic, assign) UInt32 totalSamples5;
@property (nonatomic, assign) UInt32 totalSamples6;
@property (nonatomic, assign) UInt32 fileVersion;
@property (nonatomic, assign) int mainsFrequency;
@property (readonly) UInt32 offsetECG;
@property (readonly) UInt32 offsetECG2;
@property (readonly) UInt32 offsetECG3;
@property (readonly) UInt32 offsetECG4;
@property (readonly) UInt32 offsetECG5;
@property (readonly) UInt32 offsetECG6;
@property (nonatomic, readonly) BOOL multilead;

+ (BOOL)atcFileIsDualLead:(NSString *)filename;
+ (ECGFile *)openedEcgFileWithAtcPath:(NSString *)path;

- (BOOL)open:(NSString *)filename;

- (void)resetChecksum;
- (void)saveBeatDetection:(UInt32)sampleCount beatType:(UInt16)type;
- (float)calcAverageHR;
- (UInt32)getBeatSample:(UInt32)beatIndex;
- (UInt16)getBeatType:(UInt32)beatIndex;
- (UInt32)getNumberOfBeats;
- (void)resetBeatArray;

- (NSInteger)read:(void *)buffer length:(NSInteger)len;
- (NSInteger)readFrames:(struct ECGFrame *)buffer fromSample:(unsigned long long)fromSample length:(NSUInteger)samples;
- (NSInteger)readSamples:(SInt16 *)buffer fromSample:(unsigned long long)fromSample length:(NSUInteger)samples forLead:(ECGFileLead)lead;
- (NSInteger)readSamples:(SInt16 *)buffer fromSample:(unsigned long long)fromSample length:(NSUInteger)samples;
- (void)close;

- (void)writeBeatDetections;

// Convenience methods to retrieve properties from the ECGFile in swift, because accessing c-structs isn't very nice.
- (nullable NSString *)recordingUUID;
- (nullable NSString *)iso8601DateRecordedString;

@end

NS_ASSUME_NONNULL_END
