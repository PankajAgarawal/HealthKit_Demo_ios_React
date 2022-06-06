//
//  NavigationController.m
//  rnDemo
//
//  Created by Dipak Agalcha on 31/05/22.
//

#import "NavigationController.h"

@interface NavigationController ()

@end

@implementation NavigationController

// For some reason Apple decided that navigation controllers should not ask their view controllers about rotations
// This will use the top view controller to determine the rotation of the device.
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    if (self.topViewController) {
        return [self.topViewController supportedInterfaceOrientations];
    }
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        return UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskPortraitUpsideDown;
    } else {
        return UIInterfaceOrientationMaskPortrait;
    }
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    if (self.topViewController) {
        return [self.topViewController preferredInterfaceOrientationForPresentation];
    }
    return UIInterfaceOrientationPortrait;
}

- (BOOL)shouldAutorotate {
    if (self.topViewController) {
        return [self.topViewController shouldAutorotate];
    }
    return NO;
}

#pragma mark - Public

+ (instancetype)controllerWithOpaqueNavigationBarAndRootViewController:(UIViewController *)rootViewController {
    NavigationController *navigationController = [[NavigationController alloc] initWithRootViewController:rootViewController];
    navigationController.navigationBar.translucent = NO;

    return navigationController;
}

@end

