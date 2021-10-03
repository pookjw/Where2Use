//
//  WhereToUseSggInfo.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public struct WhereToUseSggInfo: Decodable, Hashable {
    enum CodingKeys: String, CodingKey {
        case sgg_nm
        case sgg_code
    }
    
    let sggNm: String
    let sggCode: String
    
    public init(from decoder: Decoder) throws {
        let container: KeyedDecodingContainer<CodingKeys> = try decoder.container(keyedBy: CodingKeys.self)
        
        sggNm = try container.decode(String.self, forKey: .sgg_nm)
        sggCode = try container.decode(String.self, forKey: .sgg_code)
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(sggCode)
    }
}
