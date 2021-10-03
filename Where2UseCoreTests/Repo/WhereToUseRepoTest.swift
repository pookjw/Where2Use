//
//  WhereToUseRepoTest.swift
//  Where2UseCoreTests
//
//  Created by Jinwoo Kim on 10/4/21.
//

@testable import Where2UseCore
import XCTest

final class WhereToUseRepoTest: XCTestCase {
    private var repo: WhereToUseRepo!
    
    override func setUp() {
        super.setUp()
        repo = WhereToUseRepoImpl()
    }
    
    override func tearDown() {
        super.tearDown()
        repo = nil
    }
    
    func testGetSidoInfo() {
        let expectation: XCTestExpectation = .init()
        
        Task {
            do {
                let results: [WhereToUseSidoInfo] = try await repo.getSidoInfo()
                
                let test: Bool = results.contains(where: { info in
                    return info.sidoNm == "서울특별시"
                })
                print(results)
                
                XCTAssertTrue(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }
        
        wait(for: [expectation], timeout: 3)
    }
    
    func testGetSggInfo() {
        let expectation: XCTestExpectation = .init()
        
        Task {
            do {
                let results: [WhereToUseSggInfo] = try await repo.getSggInfo(sidoCod: "11")
                
                let test: Bool = results.contains(where: { info in
                    return info.sggNm == "성북구"
                })
                print(results)
                
                XCTAssertTrue(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }
        
        wait(for: [expectation], timeout: 3)
    }
    
    func testGetLdongInfo() {
        let expectation: XCTestExpectation = .init()
        
        Task {
            do {
                let results: [WhereToUseLdongInfo] = try await repo.getLdongInfo(sidoSgg: "11290")
                
                let test: Bool = results.contains(where: { info in
                    return info.bdongNm == "정릉동"
                })
                print(results)
                
                XCTAssertTrue(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }
        
        wait(for: [expectation], timeout: 3)
    }
    
    func testGetCtgryInfo() {
        let expectation: XCTestExpectation = .init()
        
        Task {
            do {
                let results: [WhereToUseCtgryInfo] = try await repo.getCtgryInfo()
                
                let test: Bool = results.contains(where: { info in
                    return info.zmapCtgryNm == "전체"
                })
                print(results)
                
                XCTAssertTrue(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }
        
        wait(for: [expectation], timeout: 3)
    }
    
    func testGetMchtZipNo() {
        let expectation: XCTestExpectation = .init()

        Task {
            do {
                let results: [String] = try await repo.getMchtZipNo(sidoSgg: "11305", ldongCod: "101", zmapCtgryCode: "01", mchtNm: "")

                let test: Bool = results.isEmpty
                print(results)

                XCTAssertFalse(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }

        wait(for: [expectation], timeout: 3)
    }
    
    func testGetMchtCnt() {
        let expectation: XCTestExpectation = .init()

        Task {
            do {
                let results: Int = try await repo.getMchtCnt(zipNo: ["01104", "01107", "01108", "01109", "01110", "01118", "01119", "01120", "01121", "01122", "01123", "01124", "01125", "01126", "01127", "01128", "01129", "01131", "01132", "01133", "01141", "01142", "01152", "01153", "01154", "01155", "01156", "01157", "01158", "01159", "01160", "01161", "01162", "01163", "01164", "01165", "01166", "01167", "01168", "01169", "01170", "01171", "01172", "01173", "01174", "01175", "01176", "01177", "01178", "01179", "01180", "01181", "01182", "01183", "01184", "01185", "01186", "01187", "01188", "01189", "01190", "01191", "01192", "01193", "01194", "01195", "01196", "01197", "01198", "01199", "01200", "01201", "01202", "01203", "01204", "01205", "01206", "01207", "01208", "01209", "01210", "01211", "01212", "01213", "01214", "01215", "01216", "01217", "01218", "01219", "01220", "01221", "01222", "01232", "01233", "01234", "01236", "01237"], zmapCtgryCode: "01", mchtNm: "")

                let test: Bool = results > 0
                print(results)

                XCTAssertTrue(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }

        wait(for: [expectation], timeout: 3)
    }
    
    func testGetMchtInfo() {
        let expectation: XCTestExpectation = .init()

        Task {
            do {
                let results: [WhereToUseMchtInfo] = try await repo.getMchtInfo(zipNo: ["01104", "01107", "01108", "01109", "01110", "01118", "01119", "01120", "01121", "01122", "01123", "01124", "01125", "01126", "01127", "01128", "01129", "01131", "01132", "01133", "01141", "01142", "01152", "01153", "01154", "01155", "01156", "01157", "01158", "01159", "01160", "01161", "01162", "01163", "01164", "01165", "01166", "01167", "01168", "01169", "01170", "01171", "01172", "01173", "01174", "01175", "01176", "01177", "01178", "01179", "01180", "01181", "01182", "01183", "01184", "01185", "01186", "01187", "01188", "01189", "01190", "01191", "01192", "01193", "01194", "01195", "01196", "01197", "01198", "01199", "01200", "01201", "01202", "01203", "01204", "01205", "01206", "01207", "01208", "01209", "01210", "01211", "01212", "01213", "01214", "01215", "01216", "01217", "01218", "01219", "01220", "01221", "01222", "01232", "01233", "01234", "01236", "01237"], zmapCtgryCode: "01", mchtNm: "", pageNo: "1", pageSet: "10")

                let test: Bool = results.isEmpty
                print(results)

                XCTAssertFalse(test)
                expectation.fulfill()
            } catch {
                XCTFail(error.localizedDescription)
            }
        }

        wait(for: [expectation], timeout: 3)
    }
}
