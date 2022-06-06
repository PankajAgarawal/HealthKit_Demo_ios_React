//
//  ECGFileView.h
//  AliveECG
//
//  Created by Kim Barnett on 1/06/10.
//  Copyright 2010 AliveCor Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACKTypes.h"
#import "ECGData.h"

@class ACKEcgRecord;
@protocol ACKEcgFileViewDelegate;

/**
 *  The view class for displaying ecg chart.
 */
@interface ACKEcgFileView : UIView

/**
 *  Renders ECG.
 *  @param  ecg The ecg record made using one of the AliveCor's supported devices.
 *  @param  xScale The X axis scale in percents.
 *  @param  yScale The Y axis scale in percents.
 *  @param  scrollingDisabled Defines whether scrolling for the ECG view will be enabled or disabled..
 */
- (void)renderEcg:(ACKEcgRecord *)ecg xScale:(NSInteger)xScale yScale:(NSInteger)yScale scrollingDisabled:(BOOL)scrollingDisabled;

/**
 *  Renders ECG.
 *  @param  ecgPath The path to the ecg record.
 *  @param  filterType The filter type that was used to record ECG.
 *  @param  isInverted Whether ECG is inverted or not.
 *  @param  xScale The X axis scale in percentages.
 *  @param  yScale The Y axis scale in percentages.
 *  @param  scrollingDisabled Defines whether scrolling for the ECG view will be enabled or disabled.
 */
- (void)renderEcgAtPath:(NSString *)ecgPath filterType:(ACKFilterType)filterType isInverted:(BOOL)isInverted xScale:(NSInteger)xScale yScale:(NSInteger)yScale scrollingDisabled:(BOOL)scrollingDisabled;

/**
 *  Inverts the ECG chart.
 */
- (void)invertECG;
/**
 *  Resets the ECG chart.
 */
- (void)reset;

- (void)setXScale:(NSInteger)percent;
- (void)setYScale:(NSInteger)percent;


@property(nonatomic) CGFloat scrollOffset;

/**
 *  The color of the ECG's chart.
 */
@property(nonatomic) UIColor *traceColor;
/**
 *  The color of the ECG's background grid.
 */
@property(nonatomic) UIColor *ecgBackgroundColor;
/**
 *  Defines whether antialiasing is enbaled or not.
 */
@property(nonatomic, assign) BOOL antialiasing;
/**
 *  The X axis scale in percents.
 */
@property(nonatomic, readonly, assign) NSInteger xScale;
/**
 *  The Y axis scale in percents.
 */
@property(nonatomic, readonly, assign) NSInteger yScale;
/**
 *  The size of the grid in pixels.
 */
@property(nonatomic, readonly, assign) CGFloat majorGridPixelSize;
/**
 *  The size of the view in pixels.
 */
@property(nonatomic, readonly, assign) NSInteger pixelLength;
/**
 *  Defines whether ECG chart is inverted or not.
 */
@property(nonatomic, readonly, assign) BOOL inverted;
/**
 *  The delegate for tracking touches in ACKEcgFileView.
 */
@property(nonatomic, weak) id <ACKEcgFileViewDelegate> delegate;

/**
 *  Sets the most leads that should be displayed.
 */
@property(nonatomic) ECGDisplayMode maximumDisplayMode;

/**
 *  actual number of leads being displayed.
 */
@property(nonatomic, readonly) ECGDisplayMode displayMode;

@property(nonatomic, assign) NSInteger xScalePercent;
@property(nonatomic, assign) NSInteger yScalePercent;

@property(nonatomic) NSString *filename;

@end

/**
 *  Methods for tracking tocuhes in ACKEcgFileView.
 */
@protocol ACKEcgFileViewDelegate <NSObject>
@optional
- (void)touched;
@end
