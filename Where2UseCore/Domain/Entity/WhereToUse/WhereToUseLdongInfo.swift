//
//  WhereToUseLdongInfo.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public struct WhereToUseLdongInfo: Decodable, Hashable {
    enum CodingKeys: String, CodingKey {
        case bdong_nm
        case bdong_code
    }
    
    let bdongNm: String
    let bdongCode: String
    
    public init(from decoder: Decoder) throws {
        let container: KeyedDecodingContainer<CodingKeys> = try decoder.container(keyedBy: CodingKeys.self)
        
        bdongNm = try container.decode(String.self, forKey: .bdong_nm)
        bdongCode = try container.decode(String.self, forKey: .bdong_code)
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(bdongCode)
    }
}
