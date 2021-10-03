//
//  MenuViewController.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/1/21.
//

import UIKit

@MainActor
final class MenuViewController: SPViewController {
    private var collectionView: UICollectionView!
    private var viewModel: MenuViewModel!
    
    @MainActor
    override func viewDidLoad() {
        super.viewDidLoad()
        setAttributes()
        configureCollectionView()
        configureViewModel()
    }
    
    @MainActor
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        animatedForSelectedIndexPath(collectionView: collectionView)
        configureNavigation()
    }
    
    private func setAttributes() {
        view.backgroundColor = .systemBackground
    }
    
    private func configureCollectionView() {
        let listConfiguration: UICollectionLayoutListConfiguration = .init(appearance: .insetGrouped)
        let layout: UICollectionViewCompositionalLayout = .init(listConfiguration: listConfiguration)
        let collectionView: UICollectionView = .init(frame: .zero, collectionViewLayout: layout)
        self.collectionView = collectionView
        
        view.addSubview(collectionView)
        collectionView.backgroundColor = .clear
        collectionView.translatesAutoresizingMaskIntoConstraints = false
        collectionView.delegate = self
        
        NSLayoutConstraint.activate([
            collectionView.topAnchor.constraintEqual(to: view.topAnchor),
            collectionView.leadingAnchor.constraintEqual(to: view.leadingAnchor),
            collectionView.trailingAnchor.constraintEqual(to: view.trailingAnchor),
            collectionView.bottomAnchor.constraintEqual(to: view.bottomAnchor)
        ])
    }
    
    private func configureViewModel() {
        let viewModel: MenuViewModel = .init(dataSource: makeDataSource())
        self.viewModel = viewModel
        
        Task.detached(priority: .userInitiated) {
            await viewModel.applyDataSource()
        }
    }
    
    private func makeDataSource() -> MenuViewModel.DataSource {
        let cellRegistration: UICollectionViewCellRegistration = makeCellRegistration()
        
        let dataSource: MenuViewModel.DataSource = .init(collectionView: collectionView) { collectionView, IndexPath, item in
            let cell: UICollectionViewCell = collectionView.dequeueConfiguredReusableCell(with: cellRegistration, for: IndexPath, item: item)
            
            return cell
        }
        
        return dataSource
    }
    
    private func makeCellRegistration() -> UICollectionViewCellRegistration {
        let cellRegistration: UICollectionViewCellRegistration = .init(cellClass: UICollectionViewListCell.self) { cell, IndexPath, item in
            let item: MenuItemModel = item as! MenuItemModel
            
            let configuration: UIListContentConfiguration = UIListContentConfiguration.cell()
            
            configuration.image = item.image
            configuration.text = item.text
            cell.contentConfiguration = configuration
            cell.accessories = [UICellAccessoryDisclosureIndicator()]
        }
        
        return cellRegistration
    }
    
    private func configureNavigation() {
        navigationController?.navigationBar.isTranslucent = false
        title = Localizable.MENU_TITLE.value
    }
    
    private func pushToOptionsViewController() {
        let viewController: OptionsViewController = .init(interfaceDescription: nil, bundle: nil, stringsFileName: nil)
        navigationController?.push(viewController, animated: true)
    }
}

extension MenuViewController: UICollectionViewDelegate {
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        guard let item: MenuItemModel = viewModel.dataSource.itemIdentifier(for: indexPath) else {
            return
        }
        
        switch item.itemType {
        case .options:
            pushToOptionsViewController()
        case .preferences:
            break
        default:
            break
        }
    }
}
