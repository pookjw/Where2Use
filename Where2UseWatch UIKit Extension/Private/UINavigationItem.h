//
//  UINavigationItem.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UINavigationItemLargeTitleDisplayMode) {
    /// Automatically use the large out-of-line title based on the state of the previous item in the navigation bar. An item with largeTitleDisplayMode=Automatic will show or hide the large title based on the request of the previous navigation item. If the first item pushed is set to Automatic, then it will show the large title if the navigation bar has prefersLargeTitles=YES.
    UINavigationItemLargeTitleDisplayModeAutomatic,
    /// Always use a larger title when this item is topmost.
    UINavigationItemLargeTitleDisplayModeAlways,
    /// Never use a larger title when this item is topmost.
    UINavigationItemLargeTitleDisplayModeNever,
} NS_SWIFT_NAME(UINavigationItem.LargeTitleDisplayMode);

@class UIBarButtonItem;

NS_SWIFT_UI_ACTOR
@interface UINavigationItem : NSObject <NSCoding>
@property (nonatomic, readwrite, copy, nullable) NSArray<UIBarButtonItem *> *leftBarButtonItems;
@property (nonatomic, readwrite, copy, nullable) NSArray<UIBarButtonItem *> *rightBarButtonItems;
@property (nonatomic, readwrite, assign) UINavigationItemLargeTitleDisplayMode largeTitleDisplayMode;
@end

NS_ASSUME_NONNULL_END
