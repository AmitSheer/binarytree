//
// Created by amit on 18/05/2021.
//


#pragma once
#include <iostream>
#include <sstream>
#include <stack>
//#include "BTIterator.hpp"
//using namespace std;

namespace ariel {
    template<typename T>
    class Node{
    public:
        T value;
        Node *left= nullptr;
        Node *right= nullptr;
        Node *parent= nullptr;
        Node()= default;
        Node(const T &val) : value(val), parent(nullptr), left(nullptr), right(nullptr){
            this->value = val;
        };
        bool operator==(const Node &rhs) const {
            return rhs.value==this->value&&rhs.left==this->left&&rhs.right==this->right&&this->parent==rhs.parent;
        }

        bool operator!=(const Node &rhs) const {
            return rhs.value!=this->value&&rhs.left!=this->left&&rhs.right!=this->right&&this->parent!=rhs.parent;
        }
//            friend std::ostream& operator<<(std::ostream& os,const Node& node){return os;};
    };
    template<typename T>
    class BinaryTree {
    private:
        Node<T> * root;
        void copy_ctor(Node<T>* this_tree_node, const Node<T>* other_tree_node);
        void delete_tree(Node<T>* node);
    public:
        BinaryTree<T>();
        BinaryTree<T>(const BinaryTree& bt);
        BinaryTree<T>(BinaryTree&& bt) noexcept ;
        ~BinaryTree();
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
        BinaryTree<T> &add_right(T parent_val, T child_val) ;

        /************************************* Operator Functions *************************************/
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T>& binaryTree){
            os<<"bla";
            return os;
        };
        BinaryTree& operator=(BinaryTree<T>&& bt) noexcept {
            if (root){ delete root;}
            root  = bt.root;
            bt.root = nullptr;
            return *this;
        }
        BinaryTree &operator=(const BinaryTree<T> &bt) {
            //check if equals to it-self
            if (this == &bt) {
                return *this;
            }
            // remove old pointer and associated data
            if (root != nullptr) {
                delete root;
            }
            // check if root from other tree is not nullptr
            // so that it won't try to access invalid memory
            if(bt.root!= nullptr) {
                root = new Node<T>{bt.root->value};
                copy_ctor(root, bt.root);
            }
            return *this;
        }
        /************************************* Iterators *************************************/
        class Postorder_iterator {
        private:
            Node<T>  *m_pointer;
            std::stack<Node<T>*> node_stk;
        public:
            explicit Postorder_iterator( Node <T> *pNode = nullptr){
                if(pNode!= nullptr) {
                    std::stack<Node<T> *> temp;
                    temp.push(pNode);
                    while (!temp.empty()) {
                        Node <T>*node = temp.top();
                        temp.pop();
                        node_stk.push(node);
                        if (node->left) {
                            temp.push(node->left);
                        }
                        if (node->right) {
                            temp.push(node->right);
                        }
                    }
                    this->m_pointer = node_stk.top();
                }else{
                    this->m_pointer= nullptr;
                }
            }
            explicit Postorder_iterator( std::stack<Node<T>*> node_stk){
                this->node_stk = node_stk;
                this->m_pointer = node_stk.top();
            }
            T &operator*() const {
                return this->m_pointer->value;
            }
            T *operator->() const {
                return &(this->m_pointer->value);
            }
            Postorder_iterator &operator++(){
                if(!node_stk.empty()) {
                    this->node_stk.pop();
                }
                if(!node_stk.empty()) {
                    this->m_pointer=this->node_stk.top();
                }else{
                    this->m_pointer= nullptr;
                }
                return *this;
            }
            Postorder_iterator operator++(int) {
                const Postorder_iterator tmp{this->node_stk};
                ++*this;
                return tmp;
            }
            bool operator==(const Postorder_iterator &rhs) const {
                return rhs.m_pointer==this->m_pointer;
            }
            bool operator!=(const Postorder_iterator &rhs) const {
                return rhs.m_pointer!=this->m_pointer;
            }
            friend std::ostream &operator<<(std::ostream &os, const Postorder_iterator &node) { return os; }
        };
        class Preorder_iterator {
        private:
            Node<T>  *m_pointer;
            std::stack<Node<T>*> node_stk;
        public:
            explicit Preorder_iterator(Node<T>  *pNode = nullptr):m_pointer(pNode) {
                this->node_stk.push(pNode);
            };
            T &operator*() const {
                return this->m_pointer->value;
            }

            T *operator->() const {
                return &(this->m_pointer->value);
            }

            Preorder_iterator &operator++() {
                if (!node_stk.empty()) {
                    node_stk.pop();
                    if (m_pointer->right != nullptr) {
                        node_stk.push(m_pointer->right);
                    }
                    if (m_pointer->left != nullptr) {
                        node_stk.push(m_pointer->left);
                    }
                    if (node_stk.empty()) {
                        this->m_pointer = nullptr;
                    } else {
                        m_pointer = node_stk.top();
                    }
                }
                if (node_stk.empty()) {
                    this->m_pointer = nullptr;
                }
                return *this;
            }

            Preorder_iterator operator++(int) {
                const Preorder_iterator tmp = *this;
                ++*this;
                return tmp;
            }

            bool operator==(const Preorder_iterator &rhs) const {
                return rhs.m_pointer==this->m_pointer;
            }

            bool operator!=(const Preorder_iterator &rhs) const {
                return rhs.m_pointer!=this->m_pointer;
            }

            friend std::ostream &operator<<(std::ostream &os, const Preorder_iterator &node) { return os; }
        };
        class Inorder_iterator {
        private:
            Node<T>  *m_pointer;
            std::stack<Node<T>*> node_stk;
        public:
            explicit Inorder_iterator(Node<T>  *pNode = nullptr){
                Node<T> *curr = pNode;
                while(curr!= nullptr){
                    this->node_stk.push(curr);
                    curr = curr->left;
                }
                if(this->node_stk.empty()){
                    this->m_pointer= nullptr;
                }else{
                    this->m_pointer = node_stk.top();
                }
            };
            T &operator*() const {
                return this->m_pointer->value;
            }

            T *operator->() const {
                return &(this->m_pointer->value);
            }

            Inorder_iterator &operator++() {
                if(!this->node_stk.empty()) {
                    Node <T>*temp = this->node_stk.top();
                    this->node_stk.pop();
                    if (temp->right != nullptr) {
                        this->node_stk.push(temp->right);
                        temp = temp->right->left;
                        while (temp != nullptr) {
                            this->node_stk.push(temp);
                            temp = temp->left;
                        }
                    }
                    if(this->node_stk.empty()){
                        this->m_pointer = nullptr;
                    }else{
                        this->m_pointer = this->node_stk.top();
                    }
                }else{
                    this->m_pointer = nullptr;
                }
                return *this;
            }

            Inorder_iterator operator++(int) {
                const Inorder_iterator tmp = *this;
                ++*this;
                return tmp;
            }

            bool operator==(const Inorder_iterator &rhs) const {
                return rhs.m_pointer==this->m_pointer;
            }

            bool operator!=(const Inorder_iterator &rhs) const {
                return rhs.m_pointer!=this->m_pointer;
            }

            friend std::ostream &operator<<(std::ostream &os, const Inorder_iterator &node) { return os; }
        };


        Inorder_iterator begin(){
            return begin_inorder();
        };
        Inorder_iterator end(){
            return end_inorder();
        };
        Preorder_iterator begin_preorder(){
            return Preorder_iterator(root);
        }
        Preorder_iterator end_preorder(){
            return  Preorder_iterator();
        }
        Inorder_iterator begin_inorder(){
            return Inorder_iterator(root);
        }
        Inorder_iterator end_inorder(){
            return Inorder_iterator();
        }
        Postorder_iterator begin_postorder(){
            return Postorder_iterator(root);
        }
        Postorder_iterator end_postorder(){
            return Postorder_iterator();
        }
        /************************************* For Testing Functions *************************************/
        Node<T> * find_node_by_val(Node<T> * node,T val){
            if(node == nullptr){
                return nullptr;
            }
            if(val==node->value){
                return node;
            }
            Node<T>* left= nullptr;
            Node<T>* right= nullptr;
            if(node->left!= nullptr){
                left = find_node_by_val(node->left,val);
            }
            if(node->right!= nullptr){
                right = find_node_by_val(node->right,val);
            }
            if(left!= nullptr){
                return left;
            }
            return right;
        };
        Node<T> * find_node_by_val(T val){
            if(val==root->value){
                return root;
            }
            return find_node_by_val(root,val);
        };
    };

    /****************************************************************** public functions  ************************************************************************/

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T parent_val, T child_val) {
        Node<T>* pNode = find_node_by_val(this->root,parent_val);
        if(pNode==nullptr){
            std::stringstream str;
            str<<"Cannot add new right child. No Parent with this value exists";
            throw std::invalid_argument(str.str());
        }
        if(pNode->left== nullptr) {
            pNode->left = new Node<T>(child_val);
            pNode->left->parent = pNode;
        } else{
            pNode->left->value=child_val;
        }
        return *this;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T parent_val, T child_val) {
        Node<T>* pNode = find_node_by_val(this->root,parent_val);
        if(pNode==nullptr){
            std::stringstream str;
            str<<"Cannot add new right child. No Parent with this value exists.";
            throw std::invalid_argument(str.str());
        }
        if(pNode->right== nullptr) {
            pNode->right = new Node<T>(child_val);
            pNode->right->parent = pNode;
        }else{
            pNode->right->value=child_val;
        }
        return *this;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T val) {
        if(root != nullptr){
            this->root->value = val;
        }else{
            this->root= new Node<T>(val);
        }
        return *this;
    }
    /****************************************************************** private functions  ************************************************************************/

    template<typename T>
    void BinaryTree<T>::delete_tree(Node<T> *node) {
        if(node != nullptr){
            delete_tree(node->right);
            delete_tree(node->left);
            delete node;
        }
    }

    template<typename T>
    void BinaryTree<T>::copy_ctor(Node<T>* this_tree_node, const Node<T>* other_tree_node) {
        if(other_tree_node->left != nullptr){
            this_tree_node->left = new Node<T>(other_tree_node->left->value);
            copy_ctor(this_tree_node->left, other_tree_node->left);
        }
        if(other_tree_node->right != nullptr){
            this_tree_node->right = new Node<T>(other_tree_node->right->value);
            copy_ctor(this_tree_node->right, other_tree_node->right);
        }
    }

    /****************************************************************** ctors  ************************************************************************/
    template<typename T>
    BinaryTree<T>::BinaryTree():root(nullptr) {
    }

    template<typename T>
    BinaryTree<T>::BinaryTree(const BinaryTree& bt) {
        if(bt.root!= nullptr){
            this->root = new Node<T>(bt.root->value);
            copy_ctor(root,bt.root);
        }
    }

    template<typename T>
    BinaryTree<T>::~BinaryTree(){
        delete_tree(this->root);
    }

    template<typename T>
    BinaryTree<T>::BinaryTree(BinaryTree &&bt)  noexcept {
        this->root = bt.root;
        bt.root = nullptr;
    }

}

