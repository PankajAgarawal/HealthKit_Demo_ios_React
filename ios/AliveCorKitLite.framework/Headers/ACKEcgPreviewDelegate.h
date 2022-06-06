//
//  ACKEcgPreviewDelegate.h
//  AliveCorKitExample
//
//  Created by Alex Vlasenko on 1/9/20.
//  Copyright © 2020 AliveCor, Inc. All rights reserved.
//

#ifndef ACKEcgPreviewDelegate_h
#define ACKEcgPreviewDelegate_h

@class ACKEcgPreviewViewController;
@class ACKEcgMonitorState;
@class ACKEcgRecord;

/**
 *  Methods for managing ECG results screen: customizing cancelation and completion handlers, footer and header views.
 */
@protocol ACKEcgPreviewDelegate <NSObject>

@optional
/**
 *  Informs the delegate that the done button was pressed.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @param  record The reference to the ECG preview view controller.
 *
 */
- (void)ecgPreviewViewController:(ACKEcgPreviewViewController *_Nonnull)viewController didFinishWithRecord:(ACKEcgRecord *_Nullable)record;

/**
 *  Informs the delegate that  the cancel button was pressed.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @param  record The reference to the ECG preview view controller.
 *
 */
- (void)ecgPreviewViewController:(ACKEcgPreviewViewController *_Nonnull)viewController didCancelWithRecord:(ACKEcgRecord *_Nullable)record;

/**
 *  Asks the delegate whether the done button should be displayed.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @return YES or NO
 *
 */
- (BOOL)showDoneButtonInEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Asks the delegate whether the cancel button should be displayed.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @return YES or NO
 *
 */
- (BOOL)showCancelButtonInEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Asks the delegate for the view object to display in the header of the ACKEcgPreviewViewController.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @return instance of the view object to display in the header of the ACKEcgPreviewViewController.
 *
 */
- (UIView *_Nullable)footerViewForEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Asks the delegate for the view object to display in the header of the ACKEcgPreviewViewController.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @return instance of the view object to display in the footer of the ACKEcgPreviewViewController.
 *
 */
- (UIView *_Nullable)headerViewForEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Asks the delegate for the right navigation bar button item
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return custom right navigation item
 *
 */
- (UIBarButtonItem *_Nullable)rightItemViewForEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Asks the delegate for the left navigation bar button item
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return custom right navigation item
 *
 */
- (UIBarButtonItem *_Nullable)leftItemViewForEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Asks the delegate whether controoler shoould support landscape mode or not
 *
 *  @param  viewController The reference to the ECG monitoring view controller.
 *  @return custom right navigation item
 *
 */
- (BOOL)supportLandscapeModeForEcgPreviewViewController:(ACKEcgPreviewViewController * _Nonnull)viewController;

/**
 *  Informs the delegate that the done button was pressed.
 *
 *  @param  viewController The reference to the ECG preview view controller.
 *  @param  record The reference to the ECG preview view controller.
 *
 */
- (void)ecgPreviewViewController:(ACKEcgPreviewViewController *_Nonnull)viewController didInvertRecord:(ACKEcgRecord *_Nullable)record;

@end



#endif /* ACKEcgPreviewDelegate_h */
