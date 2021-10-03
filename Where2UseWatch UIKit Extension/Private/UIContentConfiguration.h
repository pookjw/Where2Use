//
//  UIContentConfiguration.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UIConfigurationState;
@class UIView;
@class UITraitCollection;
@protocol UIContentView;

API_AVAILABLE(ios(14.0), tvos(14.0), watchos(7.0)) NS_SWIFT_UI_ACTOR
@protocol UIContentConfiguration <NSObject, NSCopying>

/// Initializes and returns a new instance of the content view using this configuration.
- (__kindof UIView<UIContentView> *)makeContentView;

/// Returns a copy of the configuration updated for the specified state, by applying the configuration's default values for that state to any properties that have not been customized.
- (instancetype)updatedConfigurationForState:(id<UIConfigurationState>)state;

@end


API_AVAILABLE(ios(14.0), tvos(14.0), watchos(7.0)) NS_SWIFT_UI_ACTOR
@protocol UIContentView <NSObject>

/// Returns the current configuration of the view. Setting this property applies the new configuration to the view.
@property (nonatomic, copy) id<UIContentConfiguration> configuration;

@end

NS_ASSUME_NONNULL_END
