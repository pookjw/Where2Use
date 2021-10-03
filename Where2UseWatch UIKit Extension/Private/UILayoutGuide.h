//
//  UILayoutGuide.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NSLayoutXAxisAnchor;
@class NSLayoutYAxisAnchor;
@class NSLayoutDimension;

NS_SWIFT_UI_ACTOR
@interface UILayoutGuide : NSObject <NSCoding>

/* The frame of the UILayoutGuide in its owningView's coordinate system.
 Valid by the time the owningView receives -layoutSubviews.
 */
@property(nonatomic,readonly) CGRect layoutFrame;

/* The guide must be added to a view with -[UIView addLayoutGuide:] before being used in a constraint.
 Do not use this property directly to change the owningView of a layout guide. Instead, use
 -[UIView addLayoutGuide:] and -[UIView removeLayoutGuide:], which will use this property to
 change the owningView.
 */
@property(nonatomic,weak,nullable) UIView *owningView;

/* For ease of debugging.
 'UI' prefix is reserved for UIKit-created layout guides.
 */
@property(nonatomic,copy) NSString *identifier;


/* Constraint creation conveniences. See NSLayoutAnchor.h for details.
 */
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *leadingAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *trailingAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *leftAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *rightAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *topAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *bottomAnchor;
@property(nonatomic,readonly,strong) NSLayoutDimension *widthAnchor;
@property(nonatomic,readonly,strong) NSLayoutDimension *heightAnchor;
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *centerXAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *centerYAnchor;

@end

NS_ASSUME_NONNULL_END
