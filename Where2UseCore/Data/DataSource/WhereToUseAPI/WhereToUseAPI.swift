//
//  WhereToUseAPI.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

enum WhereToUseAPIPostType: String {
    /// 강원도, 경기도...
    case getSidoInfo
    
    /// 강릉시, 고성군...
    case getSggInfo
    
    /// 강동면, 강문동, 견소동...
    case getLdongInfo
    
    /// 전체, 편의점/마트, 음식점/주점...
    case getCtgryInfo
    
    /// 우편번호들
    case getMchtZipNo
    
    /// 최종 검색 결과 개수
    case getMchtCnt
    
    /// 최종 검색 결과
    case getMchtInfo
}

enum WhereToUseAPIPostError: Error, LocalizedError {
    case invalidURL
    case response
}

protocol WhereToUseAPI {
    func requestData(type: WhereToUseAPIPostType, body: [String: Any]?) async throws -> Data
}
