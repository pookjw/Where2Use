//
//  UICollectionViewItemRegistration.h
//  Where2Use
//
//  Created by Jinwoo Kim on 10/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UINib, UICollectionViewCell, UICollectionReusableView;

typedef void(^UICollectionViewCellRegistrationConfigurationHandler)(__kindof UICollectionViewCell * _Nonnull cell, NSIndexPath * _Nonnull indexPath, id _Nonnull item);

// Cell Registration

NS_SWIFT_UI_ACTOR
@interface UICollectionViewCellRegistration : NSObject
+ (instancetype)registrationWithCellClass:(Class)cellClass configurationHandler:(UICollectionViewCellRegistrationConfigurationHandler)configurationHandler;
+ (instancetype)registrationWithCellNib:(UINib*)cellNib configurationHandler:(UICollectionViewCellRegistrationConfigurationHandler)configurationHandler;

@property(nonatomic,readonly,nullable) Class cellClass;
@property(nonatomic,readonly,nullable) UINib *cellNib;
@property(nonatomic,readonly) UICollectionViewCellRegistrationConfigurationHandler configurationHandler;

@end

// Supplementary Registration

typedef void(^UICollectionViewSupplementaryRegistrationConfigurationHandler)(__kindof UICollectionReusableView * _Nonnull supplementaryView, NSString * _Nonnull elementKind, NSIndexPath * _Nonnull indexPath);

NS_SWIFT_UI_ACTOR
@interface UICollectionViewSupplementaryRegistration : NSObject

+ (instancetype)registrationWithSupplementaryClass:(Class)supplementaryClass elementKind:(NSString*)elementKind  configurationHandler:(UICollectionViewSupplementaryRegistrationConfigurationHandler)configurationHandler;
+ (instancetype)registrationWithSupplementaryNib:(UINib*)supplementaryNib elementKind:(NSString*)elementKind configurationHandler:(UICollectionViewSupplementaryRegistrationConfigurationHandler)configurationHandler;

@property(nonatomic,readonly,nullable) Class supplementaryClass;
@property(nonatomic,readonly,nullable) UINib *supplementaryNib;
@property(nonatomic,readonly) NSString *elementKind;
@property(nonatomic,readonly) UICollectionViewSupplementaryRegistrationConfigurationHandler configurationHandler;

@end

NS_ASSUME_NONNULL_END
