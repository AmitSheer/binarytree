//
// Created by amit on 18/05/2021.
//


#pragma once
#include <iostream>

namespace ariel {
    template<typename T>
    struct Node{
        T value;
        Node *left;
        Node *right;
        Node *parent;
        explicit Node(T* val):left(nullptr),right(nullptr),parent(nullptr),value(val){};
//            friend std::ostream& operator<<(std::ostream& os,const Node& node){return os;};
    };

    template<typename T>
    class BinaryTree {
    private:
        Node<T>* root;
    public:
        BinaryTree(){};
        BinaryTree& add_root(T val){return *this;};
        /**
         * if parent val not in tree throw error
         * if exist more then once make random assign to one of the options
         * @param parent_val
         * @param child_val
         * @return
         */
        BinaryTree& add_left(T parent_val,T child_val){return *this;};
        /**
        * if parent val not in tree throw error
        * @param parent_val
        * @param child_val
        * @return
        */
        BinaryTree& add_right(T parent_val,T child_val){return *this;};
        /************************************* Operator Functions *************************************/
        friend std::ostream& operator<<(std::ostream& os,const BinaryTree<T>& binaryTree){return os;};
        /************************************* Iterator Functions *************************************/
        //TODO: PUT ALL ITERATORS IN SEPARATE HPP&CPP FILES
        class postorder{
        private:
            Node<T> *m_pointer;
            /*traverse*/
        public:
            explicit postorder(Node<T>* pNode= nullptr/*, function*/):m_pointer(pNode){};
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
        inorder begin(){
            return begin_inorder();
        };
        inorder end(){
            return end_inorder();
        };
        preorder begin_preorder(){
            return preorder(root);
        }
        preorder end_preorder(){
            return preorder();
        }
        inorder begin_inorder(){
            return inorder(root);
        }
        inorder end_inorder(){
            return inorder();
        }
        postorder begin_postorder(){
            return postorder(root);
        }
        postorder end_postorder(){
            return postorder();
        }
        /************************************* For Testing Functions *************************************/
        bool has_value(T val){
            return false;
        }
        Node<T>* get_preorder_val_array(){
            return this->root;
        }
    };
}

