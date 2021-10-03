//
//  WhereToUseSidoInfo.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public struct WhereToUseSidoInfo: Decodable, Hashable {
    enum CodingKeys: String, CodingKey {
        case sido_nm
        case sido_cod
    }
    
    let sidoNm: String
    let sidoCod: String
    
    public init(from decoder: Decoder) throws {
        let container: KeyedDecodingContainer<CodingKeys> = try decoder.container(keyedBy: CodingKeys.self)
        
        sidoNm = try container.decode(String.self, forKey: .sido_nm)
        sidoCod = try container.decode(String.self, forKey: .sido_cod)
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(sidoCod)
    }
}
