//
//  WhreToUseUseCaseTest.swift
//  Where2UseCoreTests
//
//  Created by Jinwoo Kim on 10/4/21.
//

@testable import Where2UseCore
import XCTest

final class WhreToUseUseCaseTest: XCTestCase {
    private var useCase: WhreToUseUseCase!
    
    override func setUp() {
        super.setUp()
        useCase = WhreToUseUseCaseImpl()
    }
    
    override func tearDown() {
        super.tearDown()
        useCase = nil
    }
    
    func testGetOptions() {
        let expectation: XCTestExpectation = .init()
        
        Task {
            do {
                let options: WhreToUseUseCase.Options = try await useCase.getOptions()
                
                let test: Bool = options.isEmpty
                print(options)
                
                XCTAssertFalse(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }
        
        wait(for: [expectation], timeout: 30)
    }
    
    func testGetMchtInfo() {
        let expectation: XCTestExpectation = .init()
        
        Task {
            do {
                let (results, totalPage, totalCount) = try await useCase.getMchtInfo(sideSgg: "11305", ldongCod: "101", zmapCtgryCode: "01", text: nil, page: 1)
                
                let test: Bool = results.isEmpty
                print(results)
                print(totalPage, totalCount)
                
                XCTAssertFalse(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }
        
        wait(for: [expectation], timeout: 3)
    }
}
