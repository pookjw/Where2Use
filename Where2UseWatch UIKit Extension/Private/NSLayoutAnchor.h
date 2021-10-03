//
//  NSLayoutAnchor.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NSLayoutRelation) {
    NSLayoutRelationLessThanOrEqual = -1,
    NSLayoutRelationEqual = 0,
    NSLayoutRelationGreaterThanOrEqual = 1,
};

typedef NS_ENUM(NSInteger, NSLayoutAttribute) {
    NSLayoutAttributeLeft = 1,
    NSLayoutAttributeRight,
    NSLayoutAttributeTop,
    NSLayoutAttributeBottom,
    NSLayoutAttributeLeading,
    NSLayoutAttributeTrailing,
    NSLayoutAttributeWidth,
    NSLayoutAttributeHeight,
    NSLayoutAttributeCenterX,
    NSLayoutAttributeCenterY,
    NSLayoutAttributeLastBaseline,
#if TARGET_OS_IPHONE
    NSLayoutAttributeBaseline NS_SWIFT_UNAVAILABLE("Use 'lastBaseline' instead") = NSLayoutAttributeLastBaseline,
#else
    NSLayoutAttributeBaseline = NSLayoutAttributeLastBaseline,
#endif
    NSLayoutAttributeFirstBaseline API_AVAILABLE(macos(10.11), ios(8.0)),

#if TARGET_OS_IPHONE
    NSLayoutAttributeLeftMargin API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeRightMargin API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeTopMargin API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeBottomMargin API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeLeadingMargin API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeTrailingMargin API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeCenterXWithinMargins API_AVAILABLE(ios(8.0)),
    NSLayoutAttributeCenterYWithinMargins API_AVAILABLE(ios(8.0)),
#endif
    
    NSLayoutAttributeNotAnAttribute = 0
};

typedef NS_OPTIONS(NSUInteger, NSLayoutFormatOptions) {
    NSLayoutFormatAlignAllLeft = (1 << NSLayoutAttributeLeft),
    NSLayoutFormatAlignAllRight = (1 << NSLayoutAttributeRight),
    NSLayoutFormatAlignAllTop = (1 << NSLayoutAttributeTop),
    NSLayoutFormatAlignAllBottom = (1 << NSLayoutAttributeBottom),
    NSLayoutFormatAlignAllLeading = (1 << NSLayoutAttributeLeading),
    NSLayoutFormatAlignAllTrailing = (1 << NSLayoutAttributeTrailing),
    NSLayoutFormatAlignAllCenterX = (1 << NSLayoutAttributeCenterX),
    NSLayoutFormatAlignAllCenterY = (1 << NSLayoutAttributeCenterY),
    NSLayoutFormatAlignAllLastBaseline = (1 << NSLayoutAttributeLastBaseline),
    NSLayoutFormatAlignAllFirstBaseline API_AVAILABLE(macos(10.11), ios(8.0)) = (1 << NSLayoutAttributeFirstBaseline),
#if TARGET_OS_IPHONE
    NSLayoutFormatAlignAllBaseline NS_SWIFT_UNAVAILABLE("Use 'alignAllLastBaseline' instead") = NSLayoutFormatAlignAllLastBaseline,
#else
    NSLayoutFormatAlignAllBaseline = NSLayoutFormatAlignAllLastBaseline,
#endif
    
    NSLayoutFormatAlignmentMask = 0xFFFF,
    
    /* choose only one of these three
     */
    NSLayoutFormatDirectionLeadingToTrailing = 0 << 16, // default
    NSLayoutFormatDirectionLeftToRight = 1 << 16,
    NSLayoutFormatDirectionRightToLeft = 2 << 16,
    
    NSLayoutFormatDirectionMask = 0x3 << 16,

#if TARGET_OS_IPHONE
    /* choose only one spacing format
     */
    NSLayoutFormatSpacingEdgeToEdge API_AVAILABLE(ios(11.0),tvos(11.0)) = 0 << 19, // default
    
    /* Valid only for vertical layouts. Between views with text content the value
     will be used to determine the distance from the last baseline of the view above
     to the first baseline of the view below. For views without text content the top
     or bottom edge will be used in lieu of the baseline position.
     The default spacing "]-[" will be determined from the line heights of the fonts
     involved in views with text content, when present.
     */
    NSLayoutFormatSpacingBaselineToBaseline API_AVAILABLE(ios(11.0),tvos(11.0)) = 1 << 19,
    
    NSLayoutFormatSpacingMask API_AVAILABLE(ios(11.0),tvos(11.0)) = 0x1 << 19,
#endif
};

typedef float UILayoutPriority NS_TYPED_EXTENSIBLE_ENUM;
static const UILayoutPriority UILayoutPriorityRequired API_AVAILABLE(ios(6.0)) = 1000; // A required constraint.  Do not exceed this.
static const UILayoutPriority UILayoutPriorityDefaultHigh API_AVAILABLE(ios(6.0)) = 750; // This is the priority level with which a button resists compressing its content.
static const UILayoutPriority UILayoutPriorityDragThatCanResizeScene API_AVAILABLE(macCatalyst(13.0)) = 510; // This is the appropriate priority level for a drag that may end up resizing the window's scene.
static const UILayoutPriority UILayoutPrioritySceneSizeStayPut API_AVAILABLE(macCatalyst(13.0)) = 500; // This is the priority level at which the window's scene prefers to stay the same size.  It's generally not appropriate to make a constraint at exactly this priority. You want to be higher or lower.
static const UILayoutPriority UILayoutPriorityDragThatCannotResizeScene API_AVAILABLE(macCatalyst(13.0)) = 490; // This is the priority level at which a split view divider, say, is dragged.  It won't resize the window's scene.
static const UILayoutPriority UILayoutPriorityDefaultLow API_AVAILABLE(ios(6.0)) = 250; // This is the priority level at which a button hugs its contents horizontally.
static const UILayoutPriority UILayoutPriorityFittingSizeLevel API_AVAILABLE(ios(6.0)) = 50; // When you send -[UIView systemLayoutSizeFittingSize:], the size fitting most closely to the target size (the argument) is computed.  UILayoutPriorityFittingSizeLevel is the priority level with which the view wants to conform to the target size in that computation.  It's quite low.  It is generally not appropriate to make a constraint at exactly this priority.  You want to be higher or lower.

@class NSLayoutAnchor;

NS_SWIFT_UI_ACTOR
@interface NSLayoutConstraint : NSObject

/* Create an array of constraints using an ASCII-art-like visual format string.  The values of the `metrics` dictionary should be NSNumber (or some other type that responds to -doubleValue and returns a double).
 */
+ (NSArray<NSLayoutConstraint *> *)constraintsWithVisualFormat:(NSString *)format options:(NSLayoutFormatOptions)opts metrics:(nullable NSDictionary<NSString *, id> *)metrics views:(NSDictionary<NSString *, id> *)views API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0));

/* Create constraints explicitly.  Constraints are of the form "view1.attr1 = view2.attr2 * multiplier + constant"
 If your equation does not have a second view and attribute, use nil and NSLayoutAttributeNotAnAttribute.
 Use of this method is not recommended. Constraints should be created using anchor objects on views and layout guides.
 */
+ (instancetype)constraintWithItem:(id)view1 attribute:(NSLayoutAttribute)attr1 relatedBy:(NSLayoutRelation)relation toItem:(nullable id)view2 attribute:(NSLayoutAttribute)attr2 multiplier:(CGFloat)multiplier constant:(CGFloat)c API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0));

/* If a constraint's priority level is less than required, then it is optional.  Higher priority constraints are met before lower priority constraints.
 Constraint satisfaction is not all or nothing.  If a constraint 'a == b' is optional, that means we will attempt to minimize 'abs(a-b)'.
 This property may only be modified as part of initial set up or when optional.  After a constraint has been added to a view, an exception will be thrown if the priority is changed from/to NSLayoutPriorityRequired.
 */
#if TARGET_OS_IPHONE
@property UILayoutPriority priority;
#else
@property NSLayoutPriority priority;
#endif

/* When a view is archived, it archives some but not all constraints in its -constraints array.  The value of shouldBeArchived informs the view if a particular constraint should be archived by the view.
 If a constraint is created at runtime in response to the state of the object, it isn't appropriate to archive the constraint - rather you archive the state that gives rise to the constraint.  Since the majority of constraints that should be archived are created in Interface Builder (which is smart enough to set this prop to YES), the default value for this property is NO.
 */
@property BOOL shouldBeArchived;

/* accessors
 firstItem.firstAttribute {==,<=,>=} secondItem.secondAttribute * multiplier + constant
 Access to these properties is not recommended. Use the `firstAnchor` and `secondAnchor` properties instead.
 */
@property (nullable, readonly, assign) id firstItem;
@property (nullable, readonly, assign) id secondItem;
@property (readonly) NSLayoutAttribute firstAttribute;
@property (readonly) NSLayoutAttribute secondAttribute;

/* accessors
 firstAnchor{==,<=,>=} secondAnchor * multiplier + constant
 */
@property (readonly, copy) NSLayoutAnchor *firstAnchor API_AVAILABLE(macos(10.12), ios(10.0));
@property (readonly, copy, nullable) NSLayoutAnchor *secondAnchor API_AVAILABLE(macos(10.12), ios(10.0));
@property (readonly) NSLayoutRelation relation;
@property (readonly) CGFloat multiplier;

/* Unlike the other properties, the constant may be modified after constraint creation.  Setting the constant on an existing constraint performs much better than removing the constraint and adding a new one that's just like the old but for having a new constant.
 */
@property CGFloat constant;

/* The receiver may be activated or deactivated by manipulating this property.  Only active constraints affect the calculated layout.  Attempting to activate a constraint whose items have no common ancestor will cause an exception to be thrown.  Defaults to NO for newly created constraints. */
@property (getter=isActive) BOOL active API_AVAILABLE(macos(10.10), ios(8.0));

/* Convenience method that activates each constraint in the contained array, in the same manner as setting active=YES. This is often more efficient than activating each constraint individually. */
+ (void)activateConstraints:(NSArray<NSLayoutConstraint *> *)constraints API_AVAILABLE(macos(10.10), ios(8.0));

/* Convenience method that deactivates each constraint in the contained array, in the same manner as setting active=NO. This is often more efficient than deactivating each constraint individually. */
+ (void)deactivateConstraints:(NSArray<NSLayoutConstraint *> *)constraints API_AVAILABLE(macos(10.10), ios(8.0));

@end

NS_SWIFT_UI_ACTOR
@interface NSLayoutAnchor<AnchorType> : NSObject <NSCopying, NSCoding>
// These methods return an inactive constraint of the form thisAnchor = otherAnchor.
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor __attribute__((warn_unused_result));

// These methods return an inactive constraint of the form thisAnchor = otherAnchor + constant.
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c __attribute__((warn_unused_result));

// These properties are for debugging only:
@property (readonly, copy) NSString *name;
@property (readonly, nullable, weak) id item;
@property (readonly) BOOL hasAmbiguousLayout;
@property (readonly) NSArray<NSLayoutConstraint *> *constraintsAffectingLayout;
@end

@class NSLayoutXAxisAnchor, NSLayoutYAxisAnchor, NSLayoutDimension;

NS_SWIFT_UI_ACTOR
@interface NSLayoutXAxisAnchor : NSLayoutAnchor<NSLayoutXAxisAnchor *>

// A composite anchor for creating constraints relating horizontal distances between locations.
- (NSLayoutDimension *)anchorWithOffsetToAnchor:(NSLayoutXAxisAnchor *)otherAnchor;

@end

NS_SWIFT_UI_ACTOR
@interface NSLayoutYAxisAnchor : NSLayoutAnchor<NSLayoutYAxisAnchor *>

// A composite anchor for creating constraints relating vertical distances between locations.
- (NSLayoutDimension *)anchorWithOffsetToAnchor:(NSLayoutYAxisAnchor *)otherAnchor;

@end

// This layout anchor subclass is used for sizes (width & height).
NS_SWIFT_UI_ACTOR
@interface NSLayoutDimension : NSLayoutAnchor<NSLayoutDimension *>

// These methods return an inactive constraint of the form thisVariable = constant.
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToConstant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToConstant:(CGFloat)c __attribute__((warn_unused_result));

// These methods return an inactive constraint of the form thisAnchor = otherAnchor * multiplier.
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m __attribute__((warn_unused_result));

// These methods return an inactive constraint of the form thisAnchor = otherAnchor * multiplier + constant.
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c __attribute__((warn_unused_result));

@end

NS_ASSUME_NONNULL_END
