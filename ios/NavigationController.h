//
//  NavigationController.h
//  rnDemo
//
//  Created by Dipak Agalcha on 31/05/22.
//

#import <UIKit/UIKit.h>

@interface NavigationController : UINavigationController
+ (instancetype)controllerWithOpaqueNavigationBarAndRootViewController:(UIViewController *)rootViewController;
@end
