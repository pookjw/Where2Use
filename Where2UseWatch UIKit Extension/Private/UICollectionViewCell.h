//
//  UICollectionViewCell.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

#import "UICollectionReusableView.h"

NS_ASSUME_NONNULL_BEGIN

@class UICellAccessory;
@protocol UIContentConfiguration;

NS_SWIFT_UI_ACTOR
@interface UICollectionViewCell : UICollectionReusableView
@property (nonatomic, copy, nullable) id<UIContentConfiguration> contentConfiguration;
@property (nonatomic, copy) NSArray<UICellAccessory *> *accessories;
@end

NS_ASSUME_NONNULL_END
