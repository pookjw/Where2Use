//
//  WhereToUseRepoImpl.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

actor WhereToUseRepoImpl: WhereToUseRepo {
    private let api: WhereToUseAPI
    private let decoder: JSONDecoder = .init()
    
    init(api: WhereToUseAPI = WhereToUseAPIImpl()) {
        self.api = api
    }
    
    func getSidoInfo() async throws -> [WhereToUseSidoInfo] {
        let data: Data = try await api.requestData(type: .getSidoInfo, body: nil)
        let results: [WhereToUseSidoInfo] = try decoder.decode([WhereToUseSidoInfo].self, from: data)
        
        return results
    }
    
    func getSggInfo(sidoCod: String) async throws -> [WhereToUseSggInfo] {
        let body: [String: Any] = ["sido_cod": sidoCod]
        let data: Data = try await api.requestData(type: .getSggInfo, body: body)
        let results: [WhereToUseSggInfo] = try decoder.decode([WhereToUseSggInfo].self, from: data)
        
        return results
    }
    
    func getLdongInfo(sidoSgg: String) async throws -> [WhereToUseLdongInfo] {
        let body: [String: Any] = ["sido_sgg": sidoSgg]
        let data: Data = try await api.requestData(type: .getLdongInfo, body: body)
        let results: [WhereToUseLdongInfo] = try decoder.decode([WhereToUseLdongInfo].self, from: data)
        
        return results
    }
    
    func getCtgryInfo() async throws -> [WhereToUseCtgryInfo] {
        let data: Data = try await api.requestData(type: .getCtgryInfo, body: nil)
        let results: [WhereToUseCtgryInfo] = try decoder.decode([WhereToUseCtgryInfo].self, from: data)
        
        return results
    }
    
    func getMchtZipNo(sidoSgg: String, ldongCod: String, zmapCtgryCode: String, mchtNm: String) async throws -> [String] {
        let body: [String: Any] = ["sido_sgg": sidoSgg,
                                   "ldongCod": ldongCod,
                                   "zmap_ctgry_code": zmapCtgryCode,
                                   "mcht_nm": mchtNm]
        let data: Data = try await api.requestData(type: .getMchtZipNo, body: body)
        let results: [Dictionary<String, String>] = try decoder.decode([Dictionary<String, String>].self, from: data)
        let final: [String] = results
            .compactMap { $0.values.first }
        
        return final
    }
    
    func getMchtCnt(zipNo: [String], zmapCtgryCode: String, mchtNm: String) async throws -> Int {
        let body: [String: Any] = ["zip_no": String(describing: zipNo),
                                   "zmap_ctgry_code": zmapCtgryCode,
                                   "mcht_nm": mchtNm]
        let data: Data = try await api.requestData(type: .getMchtCnt, body: body)
        let result: Int = try decoder.decode(Int.self, from: data)
        
        return result
    }
    
    func getMchtInfo(zipNo: [String], zmapCtgryCode: String, mchtNm: String, pageNo: String, pageSet: String) async throws -> [WhereToUseMchtInfo] {
        let body: [String: Any] = ["zip_no": String(describing: zipNo),
                                   "zmap_ctgry_code": zmapCtgryCode,
                                   "mcht_nm": mchtNm,
                                   "pageNo": pageNo,
                                   "pageSet": pageSet]
        let data: Data = try await api.requestData(type: .getMchtInfo, body: body)
        let results: [WhereToUseMchtInfo] = try decoder.decode([WhereToUseMchtInfo].self, from: data)
        
        return results
    }
}
