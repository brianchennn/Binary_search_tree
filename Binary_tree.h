#ifndef BINARY_TREE
#define BINARY_TREE
#include<iostream>
using namespace std;


class Node{
public:
    Node(){
        p = 0;
        left = 0;
        right = 0;
    };
    int key;
    Node *p ;
    Node *left ;
    Node *right ;
};


class Binary_tree{
public:
    Binary_tree();
    Binary_tree(Node *root_node);
    void Inorder_tree_walk(Node *x);
    void Preorder_tree_walk(Node *x);
    void Postorder_tree_walk(Node *x);
    Node* Tree_search(Node *x, int k);
    Node* Iterative_search(Node *x, int k);
    Node* Tree_minimum(Node *x);
    Node* Tree_maximum(Node *x);
    Node* Tree_successor(Node *x);
    Node* Tree_predeccessor(Node *x);
    void Insert(Node *z);
    Node* Delete(Node *z);
    Node *root;

};

#endif