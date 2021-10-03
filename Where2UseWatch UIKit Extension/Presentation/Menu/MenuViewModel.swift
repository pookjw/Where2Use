//
//  MenuViewModel.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/3/21.
//

import Foundation

actor MenuViewModel {
    typealias DataSource = UICollectionViewDiffableDataSource<MenuSectionModel, MenuItemModel>
    private typealias Snapshot = NSDiffableDataSourceSnapshot<MenuSectionModel, MenuItemModel>
    
    let dataSource: DataSource
    
    init(dataSource: DataSource) {
        self.dataSource = dataSource
    }
    
    func applyDataSource() async {
        let snapshot: Snapshot = dataSource.snapshot().copy() as! Snapshot
        
        let section: MenuSectionModel = .init(sectionType: .main)
        snapshot.appendSections(withIdentifiers: [section])
        
        let optionsItem: MenuItemModel = .init(itemType: .options)
        let preferencesItem: MenuItemModel = .init(itemType: .preferences)
        snapshot.appendItems(withIdentifiers: [optionsItem, preferencesItem], intoSectionWithIdentifier: section)
        
        DispatchQueue.main.sync { [unowned self] in
            self.dataSource.applySnapshot(snapshot, animatingDifferences: false)
        }
    }
}
