//
//  ECGView.h
//  AliveECG
//
//  Created by Kim Barnett on 29/07/09.
//  Copyright 2009 AliveCor Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ECGData.h"

typedef struct  {
    unsigned int index;
    int type;
}Annotation;

@interface ECGView : UIView

@property (nonatomic) NSInteger xScalePercent;
@property (nonatomic) NSInteger yScalePercent;
@property (nonatomic, readonly) NSMutableArray *annotations;
@property (nonatomic) NSInteger ecgSampleRateHz;
@property (nonatomic) ECGRecordingMode recordingMode;
@property (nonatomic, readonly) ECGDisplayMode displayMode;

// Returns the human readable labels for gain and sweep given the current scaling values.
+ (NSString *)sweepLabelTextForXScalePercent:(NSInteger)xScalePercent;
+ (NSString *)gainLabelTextForYScalePercent:(NSInteger)yScalePercent;

- (instancetype)initWithFrame:(CGRect)frame
          withEcgSampleRateHz:(NSInteger)ecgSampleRateHz
                recordingMode:(ECGRecordingMode)recordingMode
             secondaryDisplay:(BOOL)secondaryDisplay;
- (void)setRecordingMode:(ECGRecordingMode)recordingMode;
- (void)resetECG;
- (void)setAntialiasing:(BOOL)enable;
- (BOOL)getAntialiasing;
- (void)addECGFrame:(struct ECGFrame)ecgFrame;
- (void)showNormalBeatWithSampleCountDelay:(NSInteger)delay;
- (void)updateAnnotations;
- (void)displayAnnotation:(Annotation)ann;

- (void)startRenderingEcg;
- (void)stopRenderingEcg;

@end
