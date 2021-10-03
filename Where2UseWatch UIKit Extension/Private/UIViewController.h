//
//  UIViewController.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/1/21.
//

#import <Foundation/Foundation.h>

@class UIResponder;
@class UIView;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIModalPresentationStyle) {
    UIModalPresentationFullScreen = 0,
    UIModalPresentationPageSheet,
    UIModalPresentationFormSheet,
    UIModalPresentationCurrentContext,
    UIModalPresentationCustom,
    UIModalPresentationOverFullScreen,
    UIModalPresentationOverCurrentContext,
    UIModalPresentationPopover,
    UIModalPresentationBlurOverFullScreen,
    UIModalPresentationNone = -1,
    UIModalPresentationAutomatic = -2,
};

@protocol UIViewControllerTransitioningDelegate;

@interface UIViewController : UIResponder
@property(null_resettable, nonatomic,strong) UIView *view;
@property(nonatomic,assign) UIModalPresentationStyle modalPresentationStyle;
@property (nullable, nonatomic, weak) id <UIViewControllerTransitioningDelegate> transitioningDelegate;
@property(nullable, nonatomic,copy) NSString *title;
- (void)loadViewIfNeeded;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (void)viewWillLayoutSubviews;
- (void)viewDidLayoutSubviews;
- (void)presentViewController:(UIViewController *)viewControllerToPresent animated: (BOOL)flag completion:(void (^ __nullable)(void))completion NS_SWIFT_DISABLE_ASYNC;
- (void)dismissViewControllerAnimated: (BOOL)flag completion: (void (^ __nullable)(void))completion NS_SWIFT_DISABLE_ASYNC;
@end

@class UINavigationItem;
@class UINavigationController;

@interface UIViewController (UINavigationControllerItem)

@property(nonatomic,readonly,strong) UINavigationItem *navigationItem; // Created on-demand so that a view controller may customize its navigation appearance.
@property(nonatomic) BOOL hidesBottomBarWhenPushed; // If YES, then when this view controller is pushed into a controller hierarchy with a bottom bar (like a tab bar), the bottom bar will slide out. Default is NO.
@property(nullable, nonatomic,readonly,strong) UINavigationController *navigationController; // If this view controller has been pushed onto a navigation controller, return it.

@end

NS_ASSUME_NONNULL_END
