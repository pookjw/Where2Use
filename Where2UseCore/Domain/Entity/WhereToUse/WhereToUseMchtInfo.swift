//
//  WhereToUseMchtInfo.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public struct WhereToUseMchtInfo: Decodable, Hashable {
    enum CodingKeys: String, CodingKey {
        case call_no
        case zmap_ctgry_nm
        case mcht_addr
        case mcht_nm
        case call_no2
    }
    
    let callNo: [String]
    let zmapCtgryNm: String
    let mchtAddr: String
    let mchtNm: String
    
    public init(from decoder: Decoder) throws {
        let container: KeyedDecodingContainer<CodingKeys> = try decoder.container(keyedBy: CodingKeys.self)
        
        //
        
        var _callNo: Set<String> = []
        
        if let callNo: String = try? container.decode(String.self, forKey: .call_no) {
            _callNo.insert(callNo)
        }
        
        if let callNo2: String = try? container.decode(String.self, forKey: .call_no2) {
            let numbers: [String] = callNo2.components(separatedBy: ", ")
            numbers.forEach { number in
                _callNo.insert(number)
            }
        }
        
        callNo = Array(_callNo)
        
        //
        
        zmapCtgryNm = try container.decode(String.self, forKey: .zmap_ctgry_nm)
        mchtAddr = try container.decode(String.self, forKey: .mcht_addr)
        mchtNm = try container.decode(String.self, forKey: .mcht_nm)
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(mchtAddr)
    }
}
