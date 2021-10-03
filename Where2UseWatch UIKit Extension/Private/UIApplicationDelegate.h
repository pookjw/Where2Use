//
//  UIApplicationDelegate.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/1/21.
//

#import <Foundation/Foundation.h>

@class UIWindow;

NS_ASSUME_NONNULL_BEGIN

@protocol UIApplicationDelegate <NSObject>
@property (nullable, nonatomic, strong) UIWindow *window;
- (BOOL)application:(id)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
@end

NS_ASSUME_NONNULL_END
