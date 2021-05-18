//
// Created by amit on 18/05/2021.
//

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <string>
#include <unistd.h>
#include <algorithm>
#include "sources/BinaryTree.hpp"
using namespace std;
using namespace ariel;
using namespace doctest;

constexpr int MAX_RAND_VALUE= 5;
/*
 * credit to https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
 */
std::string gen_random( size_t length )
{
    auto randchar = []() -> char
    {
        const string charset =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (charset.size() - 1);
        return charset.at((unsigned int)rand() % max_index );
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

BinaryTree<int> binaryTreeGenerator(int n){
    BinaryTree<int> bt;
    bt.add_root(0);
    int depth = 2^(n-1);
    for (int i = 0; i < depth; ++i) {
        bt.add_left(2*i,2*i+1);
        bt.add_right(2*i,2*i+2);
    }
    return bt;
}
/**
*   BinaryTree:
*       ADD_ROOT:
*           add new root
*           overwrite existing root
*       ADD_RIGHT/ADD_LEFT:
*           add new value
*           try add new value parent not in tree
*           add with no root
*           overwrite existing value
*/

TEST_CASE("BinaryTree add new root"){
    int random_val = rand()%MAX_RAND_VALUE;
    char random_char = gen_random(random_val).at(0);
    string random_string = gen_random(random_val);
    BinaryTree<int> bt_int;
    BinaryTree<std::string> bt_string;
    BinaryTree<char> bt_char;
    bt_char.add_root(random_char);
    bt_int.add_root(random_val);
    bt_string.add_root(random_string);
    CHECK((*bt_char.begin_preorder())==random_char);
    CHECK((*bt_int.begin_preorder())==random_val);
    CHECK((*bt_string.begin_preorder())==random_string);
}

TEST_CASE("BinaryTree add_right, add_left, root") {
    int random_val = rand() % MAX_RAND_VALUE;
    /**
     * check normal adding
     */
    BinaryTree<int> bt = binaryTreeGenerator(random_val);
    int height = 2^(random_val+1)-1;
    for (int node: bt) {
        CHECK_MESSAGE(node<height,"number isn't in range");
    }
    /**
     * check overwriting values
     */
     int random_root = rand()%height;
     int random_parent= rand()%height;
     int random_left = height+random_val;
     int random_right = height+random_val+MAX_RAND_VALUE;
     bt.add_root(random_root);
     bt.add_right(random_parent,random_right);
     bt.add_left(random_parent,random_left);
     CHECK(bt.has_value(random_root));
     CHECK(bt.has_value(random_right));
     CHECK(bt.has_value(random_left));

     /**
      * add with no root
      */
      BinaryTree<int> invalid_tree;
      CHECK_THROWS(invalid_tree.add_right(random_left,random_right));
      CHECK_THROWS(invalid_tree.add_left(random_left,random_left));
      /**
       * throws exception when value isn't present at tree
       */
    int nonexisting_val = rand()+height+random_val+MAX_RAND_VALUE;
    CHECK_THROWS(invalid_tree.add_right(nonexisting_val,random_right));
    CHECK_THROWS(invalid_tree.add_right(nonexisting_val,random_right));
}
/**
*   inorder/preorder/postorder:
 *   *:
 *      get value
 *      change value
 *  &:
 *      try change
 *  ++():
 *      get next in iterator
 *  ++(int):
 *      get same, but iterator current is on next value
 *  ==:
 *      pointer is same
 *      pointer is different
 *  !=:
 *      pointer is same
 *      pointer is different
 *  <<:
 *      no need to test
*/