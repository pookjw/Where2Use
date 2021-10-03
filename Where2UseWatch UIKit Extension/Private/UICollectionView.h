//
//  UICollectionView.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import "UIScrollView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UICollectionViewScrollPosition) {
    UICollectionViewScrollPositionNone                 = 0,
    
    // The vertical positions are mutually exclusive to each other, but are bitwise or-able with the horizontal scroll positions.
    // Combining positions from the same grouping (horizontal or vertical) will result in an NSInvalidArgumentException.
    UICollectionViewScrollPositionTop                  = 1 << 0,
    UICollectionViewScrollPositionCenteredVertically   = 1 << 1,
    UICollectionViewScrollPositionBottom               = 1 << 2,
    
    // Likewise, the horizontal positions are mutually exclusive to each other.
    UICollectionViewScrollPositionLeft                 = 1 << 3,
    UICollectionViewScrollPositionCenteredHorizontally = 1 << 4,
    UICollectionViewScrollPositionRight                = 1 << 5
};

@class UICollectionViewLayout;
@class UICollectionViewCellRegistration;
@class UICollectionViewCell;
@protocol UICollectionViewDelegate;

@interface UICollectionView : UIScrollView
@property (nonatomic, weak, nullable) id <UICollectionViewDelegate> delegate;
@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForSelectedItems;
- (instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout *)layout;
- (__kindof UICollectionViewCell *)dequeueConfiguredReusableCellWithRegistration:(UICollectionViewCellRegistration*)registration forIndexPath:(NSIndexPath*)indexPath item:(id)item;
- (void)selectItemAtIndexPath:(nullable NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;
- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
@end

@class UICollectionReusableView;
@class UICollectionViewTransitionLayout;
@class UICollectionViewFocusUpdateContext;
@class UIFocusAnimationCoordinator;
@class UIContextMenuConfiguration;
@class UITargetedPreview;
@class UIContextMenuInteractionCommitAnimating;
@class UIWindowSceneActivationConfiguration;
@protocol UIScrollViewDelegate;
@protocol UISpringLoadedInteractionContext;
@protocol UIContextMenuInteractionCommitAnimating;
@protocol UIContextMenuInteractionAnimating;

NS_SWIFT_UI_ACTOR
@protocol UICollectionViewDelegate <UIScrollViewDelegate>
@optional

// Methods for notification of selection/deselection and highlight/unhighlight events.
// The sequence of calls leading to selection from a user touch is:
//
// (when the touch begins)
// 1. -collectionView:shouldHighlightItemAtIndexPath:
// 2. -collectionView:didHighlightItemAtIndexPath:
//
// (when the touch lifts)
// 3. -collectionView:shouldSelectItemAtIndexPath: or -collectionView:shouldDeselectItemAtIndexPath:
// 4. -collectionView:didSelectItemAtIndexPath: or -collectionView:didDeselectItemAtIndexPath:
// 5. -collectionView:didUnhighlightItemAtIndexPath:
- (BOOL)collectionView:(UICollectionView *)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didUnhighlightItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath; // called when the user taps on an already-selected item in multi-select mode
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)collectionView:(UICollectionView *)collectionView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView willDisplaySupplementaryView:(UICollectionReusableView *)view forElementKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didEndDisplayingCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didEndDisplayingSupplementaryView:(UICollectionReusableView *)view forElementOfKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;

// These methods provide support for copy/paste actions on cells.
// All three should be implemented if any are.
- (BOOL)collectionView:(UICollectionView *)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath API_DEPRECATED_WITH_REPLACEMENT("collectionView:contextMenuConfigurationForItemAtIndexPath:", ios(6.0, 13.0));
- (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender API_DEPRECATED_WITH_REPLACEMENT("collectionView:contextMenuConfigurationForItemAtIndexPath:", ios(6.0, 13.0));
- (void)collectionView:(UICollectionView *)collectionView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender API_DEPRECATED_WITH_REPLACEMENT("collectionView:contextMenuConfigurationForItemAtIndexPath:", ios(6.0, 13.0));

// support for custom transition layout
- (nonnull UICollectionViewTransitionLayout *)collectionView:(UICollectionView *)collectionView transitionLayoutForOldLayout:(UICollectionViewLayout *)fromLayout newLayout:(UICollectionViewLayout *)toLayout;

// Focus
- (BOOL)collectionView:(UICollectionView *)collectionView canFocusItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView shouldUpdateFocusInContext:(UICollectionViewFocusUpdateContext *)context;
- (void)collectionView:(UICollectionView *)collectionView didUpdateFocusInContext:(UICollectionViewFocusUpdateContext *)context withAnimationCoordinator:(UIFocusAnimationCoordinator *)coordinator;
- (nullable NSIndexPath *)indexPathForPreferredFocusedViewInCollectionView:(UICollectionView *)collectionView;

/// Determines if the item at the specified index path should also become selected when focus moves to it.
/// If the collection view's global selectionFollowsFocus is enabled, this method will allow you to override that behavior on a per-index path basis. This method is not called if selectionFollowsFocus is disabled.
- (BOOL)collectionView:(UICollectionView *)collectionView selectionFollowsFocusForItemAtIndexPath:(NSIndexPath *)indexPath;

- (NSIndexPath *)collectionView:(UICollectionView *)collectionView targetIndexPathForMoveOfItemFromOriginalIndexPath:(NSIndexPath *)originalIndexPath atCurrentIndexPath:(NSIndexPath *)currentIndexPath toProposedIndexPath:(NSIndexPath *)proposedIndexPath;
- (NSIndexPath *)collectionView:(UICollectionView *)collectionView targetIndexPathForMoveFromItemAtIndexPath:(NSIndexPath *)currentIndexPath toProposedIndexPath:(NSIndexPath *)proposedIndexPath API_DEPRECATED_WITH_REPLACEMENT("collectionView:targetIndexPathForMoveOfItemFromOriginalIndexPath:atCurrentIndexPath:toProposedIndexPath:", ios(9.0, 15.0));

- (CGPoint)collectionView:(UICollectionView *)collectionView targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset; // customize the content offset to be applied during transition or update animations

// Editing
/* Asks the delegate to verify that the given item is editable.
 *
 * @param collectionView The collection view object requesting this information.
 * @param indexPath An index path locating an item in `collectionView`.
 *
 * @return `YES` if the item is editable; otherwise, `NO`. Defaults to `YES`.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView canEditItemAtIndexPath:(NSIndexPath *)indexPath;

// Spring Loading

/* Allows opting-out of spring loading for an particular item.
 *
 * If you want the interaction effect on a different subview of the spring loaded cell, modify the context.targetView property.
 * The default is the cell.
 *
 * If this method is not implemented, the default is YES.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSpringLoadItemAtIndexPath:(NSIndexPath *)indexPath withContext:(id<UISpringLoadedInteractionContext>)context;

// Multiple Selection

/* Allows a two-finger pan gesture to automatically enable allowsMultipleSelection and start selecting multiple cells.
 *
 * After a multi-select gesture is recognized, this method will be called before allowsMultipleSelection is automatically
 * set to YES to allow the user to select multiple contiguous items using a two-finger pan gesture across the constrained
 * scroll direction.
 *
 * If the collection view has no constrained scroll direction (i.e., the collection view scrolls both horizontally and vertically),
 * then this method will not be called and the multi-select gesture will be disabled.
 *
 * If this method is not implemented, the default is NO.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView shouldBeginMultipleSelectionInteractionAtIndexPath:(NSIndexPath *)indexPath;

/* Called right after allowsMultipleSelection is set to YES if -collectionView:shouldBeginMultipleSelectionInteractionAtIndexPath:
 * returned YES.
 *
 * In your app, this would be a good opportunity to update the state of your UI to reflect the fact that the user is now selecting
 * multiple items at once; such as updating buttons to say "Done" instead of "Select"/"Edit", for instance.
 */
- (void)collectionView:(UICollectionView *)collectionView didBeginMultipleSelectionInteractionAtIndexPath:(NSIndexPath *)indexPath;

/* Called when the multi-select interaction ends.
 *
 * At this point, the collection view will remain in multi-select mode, but this delegate method is called to indicate that the
 * multiple selection gesture or hardware keyboard interaction has ended.
 */
- (void)collectionViewDidEndMultipleSelectionInteraction:(UICollectionView *)collectionView;


/*!
 * @abstract Called when the interaction begins.
 *
 * @param collectionView  This UICollectionView.
 * @param indexPath       IndexPath of the item for which a configuration is being requested.
 * @param point           Location in the collection view's coordinate space
 *
 * @return A UIContextMenuConfiguration describing the menu to be presented. Return nil to prevent the interaction from beginning.
 *         Returning an empty configuration causes the interaction to begin then fail with a cancellation effect. You might use this
 *         to indicate to users that it's possible for a menu to be presented from this element, but that there are no actions to
 *         present at this particular time.
 */
- (nullable UIContextMenuConfiguration *)collectionView:(UICollectionView *)collectionView contextMenuConfigurationForItemAtIndexPath:(NSIndexPath *)indexPath point:(CGPoint)point;

/*!
 * @abstract Called when the interaction begins. Return a UITargetedPreview describing the desired highlight preview.
 *
 * @param collectionView  This UICollectionView.
 * @param configuration   The configuration of the menu about to be displayed by this interaction.
 */
- (nullable UITargetedPreview *)collectionView:(UICollectionView *)collectionView previewForHighlightingContextMenuWithConfiguration:(UIContextMenuConfiguration *)configuration;

/*!
 * @abstract Called when the interaction is about to dismiss. Return a UITargetedPreview describing the desired dismissal target.
 * The interaction will animate the presented menu to the target. Use this to customize the dismissal animation.
 *
 * @param collectionView  This UICollectionView.
 * @param configuration   The configuration of the menu displayed by this interaction.
 */
- (nullable UITargetedPreview *)collectionView:(UICollectionView *)collectionView previewForDismissingContextMenuWithConfiguration:(UIContextMenuConfiguration *)configuration;

/*!
 * @abstract Called when the interaction is about to "commit" in response to the user tapping the preview.
 *
 * @param collectionView  This UICollectionView.
 * @param configuration   Configuration of the currently displayed menu.
 * @param animator        Commit animator. Add animations to this object to run them alongside the commit transition.
 */
- (void)collectionView:(UICollectionView *)collectionView willPerformPreviewActionForMenuWithConfiguration:(UIContextMenuConfiguration *)configuration animator:(id<UIContextMenuInteractionCommitAnimating>)animator;

/*!
 * @abstract Called when the collection view is about to display a menu.
 *
 * @param collectionView  This UICollectionView.
 * @param configuration   The configuration of the menu about to be displayed.
 * @param animator        Appearance animator. Add animations to run them alongside the appearance transition.
 */
- (void)collectionView:(UICollectionView *)collectionView willDisplayContextMenuWithConfiguration:(UIContextMenuConfiguration *)configuration animator:(nullable id<UIContextMenuInteractionAnimating>)animator;

/*!
 * @abstract Called when the collection view's context menu interaction is about to end.
 *
 * @param collectionView  This UICollectionView.
 * @param configuration   Ending configuration.
 * @param animator        Disappearance animator. Add animations to run them alongside the disappearance transition.
 */
- (void)collectionView:(UICollectionView *)collectionView willEndContextMenuInteractionWithConfiguration:(UIContextMenuConfiguration *)configuration animator:(nullable id<UIContextMenuInteractionAnimating>)animator;

/*!
 * @abstract Return a valid @c UIWindowSceneActivationConfiguration to allow for the cell to be expanded into a new scene. Return nil to prevent the interaction from starting.
 *
 * @param collectionView The collection view
 * @param indexPath The index path of the cell being interacted with
 * @param point The centroid of the interaction in the collection view's coordinate space.
 */
- (nullable UIWindowSceneActivationConfiguration *)collectionView:(UICollectionView *)collectionView sceneActivationConfigurationForItemAtIndexPath:(NSIndexPath *)indexPath point:(CGPoint)point;

@end

@class UICollectionViewCell;
@class UICollectionReusableView;

NS_SWIFT_UI_ACTOR
@protocol UICollectionViewDataSource <NSObject>
@required

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

// The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView;

// The view that is returned must be retrieved from a call to -dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:
- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

- (BOOL)collectionView:(UICollectionView *)collectionView canMoveItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView moveItemAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath*)destinationIndexPath;

/// Returns a list of index titles to display in the index view (e.g. ["A", "B", "C" ... "Z", "#"])
- (nullable NSArray<NSString *> *)indexTitlesForCollectionView:(UICollectionView *)collectionView;

/// Returns the index path that corresponds to the given title / index. (e.g. "B",1)
/// Return an index path with a single index to indicate an entire section, instead of a specific item.
- (NSIndexPath *)collectionView:(UICollectionView *)collectionView indexPathForIndexTitle:(NSString *)title atIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
