//
//  WhereToUseCtgryInfo.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public struct WhereToUseCtgryInfo: Decodable, Hashable {
    enum CodingKeys: String, CodingKey {
        case zmap_ctgry_nm
        case zmap_ctgry_code
    }
    
    let zmapCtgryNm: String
    let zmapCtgryCode: String
    
    public init(from decoder: Decoder) throws {
        let container: KeyedDecodingContainer<CodingKeys> = try decoder.container(keyedBy: CodingKeys.self)
        
        zmapCtgryNm = try container.decode(String.self, forKey: .zmap_ctgry_nm)
        zmapCtgryCode = try container.decode(String.self, forKey: .zmap_ctgry_code)
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(zmapCtgryCode)
    }
}
