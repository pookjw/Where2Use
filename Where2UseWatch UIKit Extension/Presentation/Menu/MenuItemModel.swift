//
//  MenuItemModel.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/3/21.
//

import UIKit

final class MenuItemModel: NSObject {
    enum ItemType: Int {
        case options
        case preferences
    }
    
    private(set) var itemType: ItemType!
    
    var text: String {
        switch itemType {
        case .options:
            return Localizable.FETCH_WITH_OPTIONS.value
        case .preferences:
            return Localizable.PREFERENCES.value
        default:
            return ""
        }
    }
    
    var image: UIImage? {
        switch itemType {
        case .options:
            return UIImage(systemName: "magnifyingglass")
        case .preferences:
            return UIImage(systemName: "gear")
        default:
            return nil
        }
    }
    
    convenience init(itemType: ItemType) {
        self.init()
        self.itemType = itemType
    }
    
    override var hash: Int { itemType.rawValue }
}
