//
// Created by amit on 18/05/2021.
//

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <string>
#include <unistd.h>
#include <algorithm>
#include <array>
#include "sources/BinaryTree.hpp"
#include "sources/BTIterator.hpp"
#include "sources/Node.hpp"
using namespace std;
using namespace ariel;
using namespace doctest;

constexpr int MAX_RAND_VALUE= 9;
constexpr int FOR_TRAVERS_FUNCTION= 3;
constexpr std::array<int,15> preorder =  {0,1,3,7,8,4,9,10,2,5,11,12,6,13,14};
constexpr std::array<int,15> postorder = {7,8,3,9,10,4,1,11,12,5,13,14,6,2,0};
constexpr std::array<int,15> inorder =   {7,3,8,1,9,10,4,0,11,5,12,2,13,6,14};
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
    int num_of_nodes = 2 ^(n - 1);
    for (int i = 0; i < num_of_nodes; ++i) {
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
    string random_string = gen_random(sizeof(random_val));
    char random_char = random_string.at(0);
    BinaryTree<int> bt_int;
    BinaryTree<std::string> bt_string;
    BinaryTree<char> bt_char;
    bt_char.add_root(random_char);
    bt_int.add_root(random_val);
    bt_string.add_root(random_string);
    CHECK(bt_char.has_value(random_string.at(0)));
    CHECK(bt_int.has_value(random_val));
    CHECK(bt_string.has_value(random_string));
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

TEST_CASE("inorder"){
    int random_val = rand()%MAX_RAND_VALUE;
    int increase_val = 2^(random_val+1)-1;
    BinaryTree<int> bt = binaryTreeGenerator(random_val);
    auto inorder_b = bt.begin_inorder();
    (*inorder_b) = increase_val+4;
    CHECK((*inorder_b)==increase_val+4);
    CHECK_NOTHROW(++inorder_b);
    CHECK((*inorder_b)==(2^(random_val)));
    inorder_b = bt.begin_inorder();
    auto second_in_travers = inorder_b++;
    CHECK_FALSE((*inorder_b)==(*second_in_travers));
    CHECK_FALSE(inorder_b==second_in_travers);
    second_in_travers = inorder_b;
    CHECK(inorder_b==second_in_travers);
    CHECK_FALSE(inorder_b!=second_in_travers);
}
TEST_CASE("postorder"){
    int random_val = rand()%MAX_RAND_VALUE;
    int increase_val = 2^(random_val+1)-1;
    BinaryTree<int> bt = binaryTreeGenerator(random_val);
    auto postorder_b = bt.begin_postorder();
    (*postorder_b) = increase_val+4;
            CHECK((*postorder_b)==(increase_val+4));
            CHECK_NOTHROW(++postorder_b);
            CHECK((*postorder_b)==(2^(random_val)));
    postorder_b = bt.begin_postorder();
    auto second_in_travers = postorder_b++;
            CHECK_FALSE((*postorder_b)==(*second_in_travers));
            CHECK_FALSE(postorder_b==second_in_travers);
    second_in_travers = postorder_b;
            CHECK(postorder_b==second_in_travers);
            CHECK_FALSE(postorder_b!=second_in_travers);
}
TEST_CASE("preorder"){
    int random_val = rand()%MAX_RAND_VALUE;
    int increase_val = 2^(random_val+1)-1;
    BinaryTree<int> bt = binaryTreeGenerator(random_val);
    auto preorder_b = bt.begin_preorder();
    (*preorder_b) = increase_val+4;
            CHECK((*preorder_b)==increase_val+4);
            CHECK_NOTHROW(++preorder_b);
            CHECK((*preorder_b)==1);
    preorder_b = bt.begin_preorder();
    auto second_in_travers = preorder_b++;
            CHECK_FALSE((*preorder_b)==(*second_in_travers));
            CHECK_FALSE(preorder_b==second_in_travers);
    second_in_travers = preorder_b;
            CHECK(preorder_b==second_in_travers);
            CHECK_FALSE(preorder_b!=second_in_travers);
}

TEST_CASE("Traverse Pre-Order"){
    BinaryTree<int> bt = binaryTreeGenerator(FOR_TRAVERS_FUNCTION);
    int num_of_nodes = 2^(FOR_TRAVERS_FUNCTION+1)-1;
    auto preorder_b = bt.begin_preorder();
    auto preorder_e = bt.end_preorder();
    auto inorder_b = bt.begin_inorder();
    auto inorder_e = bt.end_inorder();
    auto postorder_b = bt.begin_postorder();
    auto postorder_e = bt.end_postorder();
    for (std::size_t i = 0; i < num_of_nodes&&preorder_b!=preorder_e&&inorder_b!=inorder_e&&postorder_b!=postorder_e; ++i,++postorder_b,++inorder_b,++preorder_b) {
        CHECK((*preorder_b)==preorder.at(i));
        CHECK((*inorder_b)==inorder.at(i));
        CHECK((*postorder_b)==postorder.at(i));
    }
    if(postorder_b!=postorder_e){
        FAIL_CHECK("didn't get to the end of postorder");
    }
    if(preorder_b!=preorder_e){
        FAIL_CHECK("didn't get to the end of preorder");
    }
    if(inorder_b!=inorder_e){
        FAIL_CHECK("didn't get to the end of inorder");
    }
}