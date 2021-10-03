//
//  Localizable.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/3/21.
//

import Foundation

enum Localizable: String {
    case MENU_TITLE
    case FETCH_WITH_OPTIONS
    case PREFERENCES
    
    var value: String {
        NSLocalizedString(rawValue, comment: "")
    }
}
