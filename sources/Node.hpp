//
// Created by amit on 20/05/2021.
//
#pragma once
#include <iostream>
using namespace std;
namespace ariel{
    template<typename T>
    class Node{
    public:
        T value;
        Node *left;
        Node *right;
        Node *parent;
        explicit Node(T val):left(nullptr),right(nullptr),parent(nullptr){
            value = val;
        };
//            friend std::ostream& operator<<(std::ostream& os,const Node& node){return os;};
    };
}
