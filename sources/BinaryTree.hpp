//
// Created by amit on 18/05/2021.
//


#pragma once
#include <iostream>
#include <sstream>
#include "BTIterator.hpp"
namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        Node<T>* root;
        Node<T>* find_node_by_val(T val);
        static void PreOrderTraverse( Node<T>* curr_node){

        }
        static void PostOrderTraverse(Node<T>* curr_node){

        }
        static void InOrderTraverse(Node<T>* curr_node){

        }
    public:

        BinaryTree<T>();


        BinaryTree<T> &add_root(T val);

        /**
            * if parent val not in tree throw error
            * if exist more then once make random assign to one of the options
            * @param parent_val
            * @param child_val
            * @return
            */

        BinaryTree<T> &add_left(T parent_val, T child_val);

        /**
           * if parent val not in tree throw error
           * @param parent_val
           * @param child_val
           * @return
           */
        BinaryTree &add_right(T parent_val, T child_val) ;

        /************************************* Operator Functions *************************************/
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T>& binaryTree){
            os<<"bla";
            return os;
        };
        /************************************* Iterator Functions *************************************/
        //TODO: PUT ALL ITERATORS IN SEPARATE HPP&CPP FILES

        /*
        class postorder{
        private:
            Node<T> *m_pointer;

        public:
            explicit postorder(Node<T>* pNode= nullptr):m_pointer(pNode){};
            T& operator*() const{
                return m_pointer->value;
            };
            T* operator->() const{
                return &(m_pointer->value);
            };
            postorder& operator++(){

                m_pointer = m_pointer->right;
                return *this;
            };
            const postorder operator++(int){
                const postorder tmp=*this;
                m_pointer = m_pointer->right;
                return tmp;
            }
            bool operator==(const postorder& rhs) const{return false;};
            bool operator!=(const postorder& rhs) const{return false;};
            friend std::ostream& operator<<(std::ostream& os,const postorder& node){return os;};
        };
        class inorder{
        private:
            Node<T> *m_pointer;
        public:
            explicit inorder(Node<T>* pNode= nullptr):m_pointer(pNode){};
            T& operator*() const{
                return m_pointer->value;
            };
            T* operator->() const{
                return &(m_pointer->value);
            };
            inorder& operator++(){
                m_pointer = m_pointer->right;
                return *this;
            };
            const inorder operator++(int){
                const inorder tmp=*this;
                m_pointer = m_pointer->right;
                return tmp;
            }
            bool operator==(const inorder& rhs) const{return false;};
            bool operator!=(const inorder& rhs) const{return false;};
            friend std::ostream& operator<<(std::ostream& os,const inorder& node){return os;};
        };
        class preorder{
        private:
            Node<T> *m_pointer;
        public:
            explicit preorder(Node<T>* pNode= nullptr):m_pointer(pNode){};
            T& operator*() const{
                return m_pointer->value;
            };
            T* operator->() const{
                return &(m_pointer->value);
            };
            preorder& operator++(){
                m_pointer = m_pointer->right;
                return *this;
            };
            const preorder operator++(int){
                const preorder tmp=*this;
                m_pointer = m_pointer->right;
                return tmp;
            }
            bool operator==(const preorder& rhs) const{return false;};
            bool operator!=(const preorder& rhs) const{return false;};
            friend std::ostream& operator<<(std::ostream& os,const preorder& node){return os;};
        };
        */
        BTIterator<T> begin(){
            return begin_inorder();
        };
        BTIterator<T> end(){
            return end_inorder();
        };
        BTIterator<T> begin_preorder(){
            BTIterator<T>  bti = BTIterator<T>(PreOrderTraverse,root);
            return bti.begin();
        }
        BTIterator<T> end_preorder(){
            BTIterator<T>  bti = BTIterator<T>(PreOrderTraverse,root);
            return bti.end();
        }
        BTIterator<T> begin_inorder(){

            BTIterator<T>  bti = BTIterator<T>(InOrderTraverse,root);
            return bti.begin();
        }
        BTIterator<T> end_inorder(){
            BTIterator<T>  bti = BTIterator<T>(InOrderTraverse,root);
            return bti.end();
        }
        BTIterator<T> begin_postorder(){
            BTIterator<T>  bti = BTIterator<T>(PostOrderTraverse,root);
            return bti.begin();
        }
        BTIterator<T> end_postorder(){
            BTIterator<T>  bti = BTIterator<T>(PostOrderTraverse,root);
            return bti.end();
        }
        /************************************* For Testing Functions *************************************/
        bool has_value(T val);
    };

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T val) {
        this->root = new Node<T>{val};
        return *this;
    }

    template<typename T>
    BinaryTree<T>::BinaryTree() {

    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T parent_val, T child_val) {
        Node<T>* found = find_node_by_val(parent_val);

        return *this;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T parent_val, T child_val) {
        Node<T>* pNode = find_node_by_val(parent_val);
        if(pNode==nullptr){
            stringstream str;
            str<<"Cannot add new right child. No Parent with this value exists, the parent value is: "<<parent_val;
            throw invalid_argument(str.str());
        }
        pNode->right = new Node<T>(child_val);
        pNode->right->parent = pNode;
        return *this;
    }

    template<typename T>
    Node<T>* BinaryTree<T>::find_node_by_val(T val) {
        if(this->root->value==val){
            return this->root;
        }
        if(root->left!= nullptr){
            Node<T>* curr = this->root->left;
//            while (curr->parent!= nullptr){
//
//            }
        }
        return this->root;
    }

    /**************************************************************************FOR TESTING PURPOSES**************************************************************************/
    template<typename T>
    bool BinaryTree<T>::has_value(T val) {
        return false;
//        return find_node_by_val(val).value==val;
    }


}

