//
//  WhereToUseRepo.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

protocol WhereToUseRepo {
    /// 시도 정보를 얻어 온다. (강원도, 경기도, 서울특별시...)
    func getSidoInfo() async throws -> [WhereToUseSidoInfo]
    
    /// 시/구/군 정보를 얻어 온다. (강릉시, 고성군, 강북구, 강남구...)
    func getSggInfo(sidoCod: String) async throws -> [WhereToUseSggInfo]
    
    /// 읍/면/동 정보를 얻어 온다. (강동면, 강문동...)
    func getLdongInfo(sidoSgg: String) async throws -> [WhereToUseLdongInfo]
    
    /// 카테고리 정보를 얻어 온다. (전체, 편의점/마트, 음식점/주점...)
    func getCtgryInfo() async throws -> [WhereToUseCtgryInfo]
    
    /// 우편번호 정보를 얻어 온다.
    func getMchtZipNo(sidoSgg: String, ldongCod: String, zmapCtgryCode: String, mchtNm: String) async throws -> [String]
    
    /// 최종 검색 결과의 개수를 얻어 온다.
    func getMchtCnt(zipNo: [String], zmapCtgryCode: String, mchtNm: String) async throws -> Int
    
    /// 최종 검색 결과를 얻어 온다.
    func getMchtInfo(zipNo: [String], zmapCtgryCode: String, mchtNm: String, pageNo: String, pageSet: String) async throws -> [WhereToUseMchtInfo]
}
