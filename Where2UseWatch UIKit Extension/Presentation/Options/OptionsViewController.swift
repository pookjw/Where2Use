//
//  OptionsViewController.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/4/21.
//

import UIKit

@MainActor
final class OptionsViewController: SPViewController {
    private var collectoinView: UICollectionView!
    
    @MainActor
    override func viewDidLoad() {
        super.viewDidLoad()
        setAttributes()
    }
    
    private func setAttributes() {
        view.backgroundColor = .systemBackground
    }
}
