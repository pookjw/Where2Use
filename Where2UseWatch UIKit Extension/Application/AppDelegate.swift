//
//  AppDelegate.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/1/21.
//

import Foundation
import UIKit

@objc(AppDelegate)
final class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?
    
    func application(_ application: Any, didFinishLaunchingWithOptions launchOptions: [AnyHashable : Any] = [:]) -> Bool {
        let window: UIWindow = .init()
        self.window = window
        
        let viewController: MenuViewController = .init(interfaceDescription: nil, bundle: nil, stringsFileName: nil)
        let navigationController: UINavigationController = .init(rootViewController: viewController)
        window.rootViewController = navigationController
        window.makeKeyAndVisible()
        
        return true
    }
}
