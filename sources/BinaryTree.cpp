//
// Created by amit on 18/05/2021.
//

#include "BinaryTree.hpp"
//
// Created by amit on 18/05/2021.
//


#include <iostream>
//
//namespace ariel {
//    template<typename T>
//    void BinaryTree<T>::PreOrderTraverse(Node<T>* curr_node){
//
//    }
//    template<typename T>
//    void BinaryTree<T>::PostOrderTraverse(Node<T>* curr_node){
//
//    }
//    template<typename T>
//    void BinaryTree<T>::InOrderTraverse(Node<T>* curr_node){
//
//    }
//
//    template<typename T>
//    BinaryTree<T>::BinaryTree():root(nullptr) {
//
//    };
//
//    template<typename T>
//    BinaryTree<T> &BinaryTree<T>::add_root(T val) {
//        return *this;
//    };
//
//    /**
//        * if parent val not in tree throw error
//        * if exist more then once make random assign to one of the options
//        * @param parent_val
//        * @param child_val
//        * @return
//        */
//    template<typename T>
//    BinaryTree<T> &BinaryTree<T>::add_left(T parent_val, T child_val) { return *this; };
//
//    /**
//       * if parent val not in tree throw error
//       * @param parent_val
//       * @param child_val
//       * @return
//       */
//    template<typename T>
//    BinaryTree<T> &BinaryTree<T>::add_right(T parent_val, T child_val) { return *this; };
//
//    /************************************* Operator Functions *************************************/
//    template<typename T>
//    std::ostream &operator<<(std::ostream &os, const BinaryTree<T>& binaryTree) {
//        os << "bla";
//        return os;
//    };
//
//    /************************************* Iterator Functions *************************************/
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::begin(){
//        return BinaryTree<T>::begin_inorder();
//    };
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::end(){
//        return BinaryTree<T>::end_inorder();
//    };
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::begin_preorder(){
//        return BTIterator<T>(BinaryTree<T>::PreOrderTraverse,root);
//    }
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::end_preorder(){
//        return BTIterator<T>(BinaryTree<T>::PreOrderTraverse);
//    }
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::begin_inorder(){
//        return BTIterator<T>(BinaryTree<T>::InOrderTraverse,root);
//    }
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::end_inorder(){
//        return BTIterator<T>(BinaryTree<T>::InOrderTraverse);
//    }
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::begin_postorder(){
//        return BTIterator<T>(BinaryTree<T>::PostOrderTraverse,root);
//    }
//    template<typename T>
//    BTIterator<T> BinaryTree<T>::end_postorder(){
//        return BTIterator<T>(BinaryTree<T>::PostOrderTraverse);
//    }
//
//    /************************************* For Testing Functions *************************************/
//    template<typename T>
//    bool BinaryTree<T>::has_value(T val) {
//        return false;
//    }
//    template<typename T>
//    Node<T> *BinaryTree<T>::get_preorder_val_array() {
//        return this->root;
//    }
//
//}