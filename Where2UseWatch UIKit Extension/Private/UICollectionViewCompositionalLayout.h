//
//  UICollectionViewCompositionalLayout.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>
#import "UICollectionViewLayout.h"

NS_ASSUME_NONNULL_BEGIN

@class NSCollectionLayoutSection;
@class UICollectionViewCompositionalLayoutConfiguration;

typedef NSCollectionLayoutSection * _Nullable (^UICollectionViewCompositionalLayoutSectionProvider)(NSInteger section, id);

NS_SWIFT_UI_ACTOR
@interface UICollectionViewCompositionalLayout : UICollectionViewLayout
- (instancetype)initWithSection:(NSCollectionLayoutSection*)section;
- (instancetype)initWithSection:(NSCollectionLayoutSection*)section configuration:(UICollectionViewCompositionalLayoutConfiguration*)configuration;

- (instancetype)initWithSectionProvider:(UICollectionViewCompositionalLayoutSectionProvider)sectionProvider;
- (instancetype)initWithSectionProvider:(UICollectionViewCompositionalLayoutSectionProvider)sectionProvider configuration:(UICollectionViewCompositionalLayoutConfiguration*)configuration;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

// Setting this property will invalidate the layout immediately to affect any changes
//    Note: any changes made to properties directly will have no effect.
@property(nonatomic,copy) UICollectionViewCompositionalLayoutConfiguration *configuration;
@end

@interface UICollectionViewCompositionalLayout (UICollectionLayoutListSection)

/// Creates a compositional layout containing only list sections of the specified configuration.
+ (instancetype)layoutWithListConfiguration:(UICollectionLayoutListConfiguration *)configuration;

@end

NS_ASSUME_NONNULL_END
