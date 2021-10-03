//
//  UICollectionLayoutListConfiguration.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UICollectionLayoutListAppearance) {
    UICollectionLayoutListAppearancePlain,
    UICollectionLayoutListAppearanceGrouped,
    UICollectionLayoutListAppearanceInsetGrouped API_UNAVAILABLE(tvos),
    UICollectionLayoutListAppearanceSidebar API_UNAVAILABLE(tvos),
    UICollectionLayoutListAppearanceSidebarPlain API_UNAVAILABLE(tvos),
};

typedef NS_ENUM(NSInteger, UICollectionLayoutListHeaderMode) {
    /// No headers are shown
    UICollectionLayoutListHeaderModeNone,
    
    /// Uses supplementary views of kind UICollectionElementKindSectionHeader to show headers
    UICollectionLayoutListHeaderModeSupplementary,
    
    /// Styles the first item in a section as a header. This is especially useful when using hierarchical data sources to be able to expand and collapse the header.
    UICollectionLayoutListHeaderModeFirstItemInSection,
};

typedef NS_ENUM(NSInteger, UICollectionLayoutListFooterMode) {
    /// No footers are shown
    UICollectionLayoutListFooterModeNone,
    
    /// Uses supplementary views of kind UICollectionElementKindSectionFooter to show footers
    UICollectionLayoutListFooterModeSupplementary,
};

@class UIListSeparatorConfiguration;
@class UISwipeActionsConfiguration;

typedef UIListSeparatorConfiguration *_Nonnull (^UICollectionLayoutListItemSeparatorHandler)(NSIndexPath *_Nonnull indexPath, UIListSeparatorConfiguration *_Nonnull sectionSeparatorConfiguration);

typedef UISwipeActionsConfiguration *_Nullable (^UICollectionLayoutListSwipeActionsConfigurationProvider)(NSIndexPath *indexPath);

NS_SWIFT_UI_ACTOR
@interface UICollectionLayoutListConfiguration : NSObject <NSCopying>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithAppearance:(UICollectionLayoutListAppearance)appearance NS_DESIGNATED_INITIALIZER;


// appearance:

/// The overall appearance of the section.
@property (nonatomic, readonly) UICollectionLayoutListAppearance appearance;

/// Whether this section shows separators or not. For additional control, see separatorConfiguration.
/// Note that when this property is NO, the separatorConfiguration is ineffective.
@property (nonatomic) BOOL showsSeparators;

/// The preferred configuration for separators. Used as a baseline for a section in a list using this \c UICollectionLayoutListConfiguration
@property (nonatomic, copy) UIListSeparatorConfiguration *separatorConfiguration;

/// This handler is executed when the list section is configuring separator appearance for an item. The index path for the item being configured and
/// a resolved separator configuration are passed in to this block. The configuration returned from this block will be treated as the final
/// separator configuration for this item.
@property (nonatomic, copy, nullable) UICollectionLayoutListItemSeparatorHandler itemSeparatorHandler;

/// The background color of the section.
/// Defaults to nil, indicating the system background color for the specified appearance is used.
@property (nonatomic, nullable, strong) UIColor *backgroundColor;


// swipe actions:

/// Called when list is about to show leading swipe actions for a particular index path.
/// Return either a UISwipeActionsConfiguration object or nil if this index path does not show swipe actions.
@property (nonatomic, copy, nullable) UICollectionLayoutListSwipeActionsConfigurationProvider leadingSwipeActionsConfigurationProvider;

/// Called when list is about to show trailing swipe actions for a particular index path.
/// Return either a UISwipeActionsConfiguration object or nil if this index path does not show swipe actions.
@property (nonatomic, copy, nullable) UICollectionLayoutListSwipeActionsConfigurationProvider trailingSwipeActionsConfigurationProvider;


// headers & footers:

/// Defines whether the section has a header. Defaults to UICollectionLayoutListHeaderModeNone.
@property (nonatomic) UICollectionLayoutListHeaderMode headerMode;
/// Defines whether the section has a footer. Defaults to UICollectionLayoutListFooterModeNone.
@property (nonatomic) UICollectionLayoutListFooterMode footerMode;

/// Padding above each section header. The default value is `UICollectionViewLayoutAutomaticDimension`
@property (nonatomic) CGFloat headerTopPadding;

@end

NS_ASSUME_NONNULL_END
