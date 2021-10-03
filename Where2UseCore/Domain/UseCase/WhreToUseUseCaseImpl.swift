//
//  WhreToUseUseCaseImpl.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public actor WhreToUseUseCaseImpl: WhreToUseUseCase {
    private let repo: WhereToUseRepo
    
    public convenience init() {
        self.init(repo: WhereToUseRepoImpl())
    }
    
    init(repo: WhereToUseRepo = WhereToUseRepoImpl()) {
        self.repo = repo
    }
    
    public func getOptions() async throws -> Options {
        var result: Options = [:]
        
        let sidoInfos: [WhereToUseSidoInfo] = try await repo.getSidoInfo()
        
        for sidoInfo in sidoInfos {
            result[sidoInfo] = [:]
            
            let sggInfos: [WhereToUseSggInfo] = try await repo.getSggInfo(sidoCod: sidoInfo.sidoCod)
            
            for sggInfo in sggInfos {
                let ldongInfos: [WhereToUseLdongInfo] = try await repo.getLdongInfo(sidoSgg: sggInfo.sggCode)
                
                
                result[sidoInfo]?[sggInfo] = ldongInfos
            }
        }
        
        return result
    }
    
    public func getMchtInfo(sideSgg: String, ldongCod: String, zmapCtgryCode: String, text: String?, page: Int) async throws -> (results: [WhereToUseMchtInfo], totalPage: Int, totalCount: Int) {
        
        let zipNo: [String] = try await repo.getMchtZipNo(sidoSgg: sideSgg, ldongCod: ldongCod, zmapCtgryCode: zmapCtgryCode, mchtNm: text ?? "")
        
        let countPerPage: Int = 10
        
        let totalCount: Int = try await repo.getMchtCnt(zipNo: zipNo, zmapCtgryCode: zmapCtgryCode, mchtNm: text ?? "")
        
        let totalPage: Int
        
        if (totalCount % 10) == 0 {
            totalPage = (totalCount / countPerPage)
        } else {
            totalPage = (totalCount / countPerPage) + 1
        }
        
        let results: [WhereToUseMchtInfo] = try await repo.getMchtInfo(zipNo: zipNo, zmapCtgryCode: zmapCtgryCode, mchtNm: text ?? "", pageNo: String(page), pageSet: String(countPerPage))
        
        return (results, totalPage, totalCount)
    }
}
