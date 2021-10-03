//
//  UINavigationBar.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIView;

@interface UINavigationBar : UIView <NSCopying>
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent;
@property (nonatomic, readwrite, assign) BOOL prefersLargeTitles;
@end

NS_ASSUME_NONNULL_END
