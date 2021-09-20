//
//  SceneDelegate.m
//  Where2Use
//
//  Created by Jinwoo Kim on 9/21/21.
//

#import "SceneDelegate.h"

@interface SceneDelegate ()
@end

@implementation SceneDelegate

- (void)dealloc {
    [_window release];
    [super dealloc];
}


- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    UIWindowScene *windowScene = (UIWindowScene *)scene;
    
    if (![windowScene isKindOfClass:[UIWindowScene class]]) return;
    
    UIWindow *window = [[UIWindow alloc] initWithWindowScene:windowScene];
    self.window = window;
    
    //
    
    UIViewController *viewController = [UIViewController new];
    viewController.view.backgroundColor = UIColor.systemMintColor;
    
    window.rootViewController = viewController;
    [viewController release];
    
    [window makeKeyAndVisible];
    [window release];
}

@end
