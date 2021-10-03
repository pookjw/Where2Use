//
//  UIViewController+animatedForSelectedIndexPath.swift
//  Where2UseWatch UIKit Extension
//
//  Created by Jinwoo Kim on 10/4/21.
//

import UIKit

extension UIViewController {
    func animatedForSelectedIndexPath(collectionView: UICollectionView) {
        guard let indexPathsForSelectedItems: [IndexPath] = collectionView.indexPathsForSelectedItems else {
            return
        }
        
        for indexPath in indexPathsForSelectedItems {
            if let coordinator: UIViewControllerTransitionCoordinator = transitionCoordinator {
                coordinator.animate { _ in
                    collectionView.deselectItem(at: indexPath, animated: true)
                } completion: { context in
                    if context.isCancelled {
                        collectionView.selectItem(at: indexPath, animated: true, scrollPosition: .top)
                    }
                }

            } else {
                collectionView.deselectItem(at: indexPath, animated: true)
            }
        }
    }
}
