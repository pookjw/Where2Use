//
//  CrownService.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/1/21.
//

import Foundation
import WatchKit
import Combine

fileprivate final class _ReceiverInterfaceController: WKInterfaceController {}

final class CrownService: NSObject {
    static let shared: CrownService = .init()
    
    let didRotate: PassthroughSubject<Double, Never> = .init()
    let didBecomeIdle: PassthroughSubject<Void, Never> = .init()
    
    var isIdle: Bool {
        return interfaceController.crownSequencer.isIdle
    }
    
    private var interfaceController: _ReceiverInterfaceController!
    
    private override init() {
        super.init()
        
//        interfaceController = .init()
//        interfaceController.crownSequencer.delegate = self
//        interfaceController.crownSequencer.focus()
    }
    
    deinit {
        interfaceController.crownSequencer.resignFocus()
    }
}

extension CrownService: WKCrownDelegate {
    func crownDidRotate(_ crownSequencer: WKCrownSequencer?, rotationalDelta: Double) {
        didRotate.send(rotationalDelta)
    }
    
    func crownDidBecomeIdle(_ crownSequencer: WKCrownSequencer?) {
        didBecomeIdle.send()
    }
}
