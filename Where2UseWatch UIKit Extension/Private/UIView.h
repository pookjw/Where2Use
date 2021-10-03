//
//  UIView.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/1/21.
//

#import <Foundation/Foundation.h>

@class UIResponder;
@class UIColor;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIViewAnimationCurve) {
    UIViewAnimationCurveEaseInOut,         // slow at beginning and end
    UIViewAnimationCurveEaseIn,            // slow at beginning
    UIViewAnimationCurveEaseOut,           // slow at end
    UIViewAnimationCurveLinear,
};

@class UILayoutGuide;

@interface UIView : UIResponder
@property(nullable, nonatomic,copy) UIColor *backgroundColor;
@property(nonatomic) BOOL translatesAutoresizingMaskIntoConstraints;
@property(nonatomic,readonly,strong) UILayoutGuide *safeAreaLayoutGuide;
- (void)addSubview:(UIView *)view;
@end

@class NSLayoutXAxisAnchor;
@class NSLayoutYAxisAnchor;
@class NSLayoutDimension;

@interface UIView (UIViewLayoutConstraintCreation)
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
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *firstBaselineAnchor;
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *lastBaselineAnchor;
@end

NS_ASSUME_NONNULL_END
