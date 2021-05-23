//
// Created by amit on 18/05/2021.
//

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <string>
#include <unistd.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <queue>
#include "sources/BinaryTree.hpp"
using namespace std;
using namespace ariel;
using namespace doctest;
constexpr int MAX_RAND_VALUE= 3;
constexpr int FOR_TRAVERS_FUNCTION= 4;

/*
 * implementation ta from https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
 */
queue<int> createStackForInOrder(BinaryTree<int>* bt){
    Node<int>* node = bt->find_node_by_val(0);
    queue<int> value_order;
    stack<Node<int>*> s;
    while (node != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (node !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(node);
            node = node->left;
        }

        /* Current must be NULL at this point */
        node = s.top();
        value_order.push(node->value);
        s.pop();

                /* we have visited the node and its
                   left subtree.  Now, it's right
                   subtree's turn */
        node = node->right;
    }
    return value_order;
}
/*
 * implementation ta from https://www.geeksforgeeks.org/iterative-preorder-traversal/
 */
queue<int> createStackForPreOrder(BinaryTree<int>* bt){
    Node<int>* node = bt->find_node_by_val(0);
    queue<int> value_order;
    stack<Node<int>*> s;
    s.push(node);
    while (s.empty() == false) {
        // Pop the top item from stack and print it
        node = s.top();
        value_order.push(node->value);
        s.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
    return value_order;
}
/*
 * implementation ta from https://www.geeksforgeeks.org/iterative-postorder-traversal/
 */
stack<int> createStackForPostOrder(BinaryTree<int>* bt){
    Node<int>* node = bt->find_node_by_val(0);
    stack<int> value_order;
    stack<Node<int>*> s1;

    // push root to first stack
    s1.push(node);

    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        value_order.push(node->value);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    return value_order;
}
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
    int num_of_nodes = pow(2,(n + 1))-1;
    for (int i = 0; i < num_of_nodes; ++i) {
        bt.add_left(i,2*i+1);
        bt.add_right(i,2*i+2);
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

TEST_CASE("BinaryTree editing leaf's") {
    int random_val = rand() % MAX_RAND_VALUE;
    /**
     * check normal adding
     */
    BinaryTree<int> bt = binaryTreeGenerator(random_val);
    int num_of_nodes = pow(2, (random_val + 1)) * 2 + 2;
    auto b = bt.begin();
    for (auto i = bt.begin(); i!=bt.end();++i) {
        CHECK_MESSAGE((*i) < num_of_nodes, "number isn't in range");
    }
    /**
     * check overwriting values
     */
     int random_root = rand() % num_of_nodes;
     int random_parent= rand() % num_of_nodes;
     int random_left = num_of_nodes + random_val;
     int random_right = num_of_nodes + random_val + MAX_RAND_VALUE;
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
    int nonexisting_val = rand() + num_of_nodes + random_val + MAX_RAND_VALUE;
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
    // check changing value
    Node<int>* parent = bt.find_node_by_val(*inorder_b)->parent;
    (*inorder_b) = increase_val+4;
    CHECK((*inorder_b)==parent->left->value);

    // check moving correctly to next value
    CHECK_NOTHROW(++inorder_b);
    CHECK((*inorder_b)==parent->value);
    //reset begin
    inorder_b = bt.begin_inorder();
    auto second_in_travers = inorder_b++;
    //check == and != operators
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
    Node<int>* right = bt.find_node_by_val(*postorder_b)->parent->right;
    (*postorder_b) = increase_val+4;
    CHECK((*postorder_b)==right->parent->left->value);

    // check moving correctly to next value
    CHECK_NOTHROW(++postorder_b);
    CHECK((*postorder_b)==right->value);

    //reset begin
    postorder_b = bt.begin_postorder();
    auto second_in_travers = postorder_b++;
    //check == and != operators
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
    Node<int>* left = bt.find_node_by_val(*preorder_b)->left;

    (*preorder_b) = increase_val+4;
    CHECK((*preorder_b)==left->parent->value);

    // check moving correctly to next value

    CHECK_NOTHROW(++preorder_b);
    CHECK((*preorder_b)==left->value);

    //reset begin
    preorder_b = bt.begin_preorder();
    auto second_in_travers = preorder_b++;
    //check == and != operators
    CHECK_FALSE((*preorder_b)==(*second_in_travers));
    CHECK_FALSE(preorder_b==second_in_travers);
    second_in_travers = preorder_b;
    CHECK(preorder_b==second_in_travers);
    CHECK_FALSE(preorder_b!=second_in_travers);
}

TEST_CASE("Traverse is correct"){
    BinaryTree<int> bt = binaryTreeGenerator(FOR_TRAVERS_FUNCTION);
    int num_of_nodes = pow(2,(FOR_TRAVERS_FUNCTION+2))-1;
    queue<int> preorder_print = createStackForPreOrder(&bt);
    stack<int> postorder_print = createStackForPostOrder(&bt);
    queue<int> inorder_print = createStackForInOrder(&bt);
    auto preorder_b = bt.begin_preorder();
    auto preorder_e = bt.end_preorder();
    auto inorder_b = bt.begin_inorder();
    auto inorder_e = bt.end_inorder();
    auto postorder_b = bt.begin_postorder();
    auto postorder_e = bt.end_postorder();
    for (; preorder_b!=preorder_e&&inorder_b!=inorder_e&&postorder_b!=postorder_e; ++preorder_b,++inorder_b,++postorder_b,inorder_print.pop(),preorder_print.pop(),postorder_print.pop()) {
        CHECK((*preorder_b)==preorder_print.front());
        CHECK((*inorder_b)==inorder_print.front());
        CHECK((*postorder_b)==postorder_print.top());
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