//
//  SPViewController.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/1/21.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WatchKit.h>

@class UIViewController;

NS_ASSUME_NONNULL_BEGIN

@interface SPViewController : UIViewController
@property(readonly, nonatomic) NSObject *crownSequencer; // SPCrownSequencer
- (id)initWithInterfaceDescription:(id _Nullable)arg1 bundle:(id _Nullable)arg2 stringsFileName:(id _Nullable)arg3 isNotification:(_Bool)arg4;
- (id)initWithInterfaceDescription:(id _Nullable)arg1 bundle:(id _Nullable)arg2 stringsFileName:(id _Nullable)arg3;
- (_Bool)containsNowPlayingView;
@end

NS_ASSUME_NONNULL_END
