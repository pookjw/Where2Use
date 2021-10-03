//
//  WhreToUseUseCase.swift
//  Where2UseCore
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

public protocol WhreToUseUseCase {
    typealias Options = [WhereToUseSidoInfo : [WhereToUseSggInfo : [WhereToUseLdongInfo]]]
    
    /// 검색 옵션을 얻어 온다.
    func getOptions() async throws -> Options
    
    /// 검색 결과를 얻어 온다.
    func getMchtInfo(sideSgg: String, ldongCod: String, zmapCtgryCode: String, text: String?, page: Int) async throws -> (results: [WhereToUseMchtInfo], totalPage: Int, totalCount: Int)
}
