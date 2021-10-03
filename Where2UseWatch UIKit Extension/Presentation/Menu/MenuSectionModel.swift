//
//  MenuSectionModel.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/3/21.
//

import Foundation

final class MenuSectionModel: NSObject {
    enum SectionType: Int {
        case main
    }
    
    private(set) var sectionType: SectionType!
    
    convenience init(sectionType: SectionType) {
        self.init()
        self.sectionType = sectionType
    }
    
    override var hash: Int {
        sectionType.rawValue
    }
    
    override func isEqual(_ object: Any?) -> Bool {
        guard let object: MenuSectionModel = object as? MenuSectionModel else {
            return false
        }
        
        return sectionType == object.sectionType
    }
}
