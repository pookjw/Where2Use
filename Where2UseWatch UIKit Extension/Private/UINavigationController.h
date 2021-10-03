//
//  UINavigationController.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

@class UIViewController;
@class UINavigationBar;

@interface UINavigationController : UIViewController
@property(nonatomic,readonly) UINavigationBar *navigationBar;
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController NS_DESIGNATED_INITIALIZER;
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
@end
