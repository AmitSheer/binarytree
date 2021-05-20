//
// Created by amit on 20/05/2021.
//
#pragma once
#include "Node.hpp"
#include <iostream>
using namespace std;
namespace ariel {
    template<typename T>
    class BTIterator {
    private:
        Node <T> *m_pointer;
        void (*Traverse)(Node <T> *);
    public:
        explicit BTIterator(void (*traverse)(Node <T> *), Node <T> *pNode = nullptr):Traverse(traverse),m_pointer(pNode) {};
        BTIterator<T> begin();
        BTIterator<T> end();
        T &operator*() const ;
        T *operator->() const ;
        BTIterator<T> &operator++() ;
        const BTIterator<T> operator++(int);
        bool operator==(const BTIterator<T> &rhs) const;
        bool operator!=(const BTIterator<T> &rhs) const;
        friend std::ostream &operator<<(std::ostream &os, const BTIterator<T> &node) { return os; }
    };

    template<typename T>
    const BTIterator<T> BTIterator<T>::operator++(int)  {
        const BTIterator tmp = *this;
        Traverse(this->m_pointer);
        return tmp;
    }

    template<typename T>
    bool BTIterator<T>::operator==(const BTIterator<T> &rhs) const {
        return false;
    }

    template<typename T>
    bool BTIterator<T>::operator!=(const BTIterator<T> &rhs) const {
        return false;
    }

    template<typename T>
    BTIterator<T> &BTIterator<T>::operator++() {
        ++this->m_pointer;
        return *this;
    }

    template<typename T>
    T* BTIterator<T>::operator->() const {
        return &(this->m_pointer->value);
    }

    template<typename T>
    T &BTIterator<T>::operator*() const {
        return this->m_pointer->value;
    }

    template<typename T>
    BTIterator<T> BTIterator<T>::begin() {
        this->Traverse(this->m_pointer);
        return *this;
    }

    template<typename T>
    BTIterator<T> BTIterator<T>::end() {
        return BTIterator<T>(this->Traverse, nullptr);
    }
}