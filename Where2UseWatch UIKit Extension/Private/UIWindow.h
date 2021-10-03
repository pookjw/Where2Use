//
//  UIWindow.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/1/21.
//

#import <Foundation/Foundation.h>

@class UIViewController;

@interface UIWindow : NSObject
@property(nullable, nonatomic,strong) UIViewController *rootViewController;
- (void)makeKeyAndVisible;
@end
