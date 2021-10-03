//
//  main.m
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/1/21.
//

#import <Foundation/Foundation.h>

int UIApplicationMain(int argc, char * _Nullable * _Nonnull argv, NSString * _Nullable principalClassName, NSString * _Nonnull delegateClassName);

int __attribute__((constructor)) injected_main(int argc, char * argv[]) {
    return UIApplicationMain(argc, argv, nil, @"AppDelegate");
}
