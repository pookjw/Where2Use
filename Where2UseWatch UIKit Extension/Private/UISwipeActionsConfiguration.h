//
//  UISwipeActionsConfiguration.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIContextualAction;

NS_SWIFT_UI_ACTOR
@interface UISwipeActionsConfiguration : NSObject

+ (instancetype)configurationWithActions:(NSArray<UIContextualAction *> *)actions;

@property (nonatomic, copy, readonly) NSArray<UIContextualAction *> *actions;
@property (nonatomic) BOOL performsFirstActionWithFullSwipe; // default YES, set to NO to prevent a full swipe from performing the first action

@end

NS_ASSUME_NONNULL_END
