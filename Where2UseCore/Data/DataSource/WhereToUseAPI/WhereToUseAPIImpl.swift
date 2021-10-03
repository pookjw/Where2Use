//
//  WhereToUseAPIImpl.swift
//  Where2Use
//
//  Created by Jinwoo Kim on 10/4/21.
//

import Foundation

actor WhereToUseAPIImpl: WhereToUseAPI {
    func requestData(type: WhereToUseAPIPostType, body: [String: Any]?) async throws -> Data {
        var components: URLComponents = .init()
        components.scheme = "https"
        components.host = "xn--3e0bnl907agre90ivg11qswg.kr"
//        components.host = "국민지원금사용처.kr"
        components.path = "/whereToUse/\(type.rawValue).do"
        
        guard let url: URL = components.url else {
            throw WhereToUseAPIPostError.invalidURL
        }
        
        var request: URLRequest = .init(url: url)
        request.httpMethod = "POST"
        request.addValue("application/json", forHTTPHeaderField: "Content-Type")
        request.addValue("application/json", forHTTPHeaderField: "Accept")
        
        if let body: [String: Any] = body {
            let jsonData: Data = try JSONSerialization.data(withJSONObject: body, options: [])
            request.httpBody = jsonData
        }
        
        let (data, response): (Data, URLResponse) = try await URLSession.shared.data(for: request, delegate: nil)
        
        guard let httpResponse: HTTPURLResponse = response as? HTTPURLResponse,
              httpResponse.statusCode ~= 200 else {
                  throw WhereToUseAPIPostError.response
              }
        
        return data
    }
}
