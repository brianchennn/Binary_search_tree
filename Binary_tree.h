#ifndef BINARY_TREE
#define BINARY_TREE
#include<iostream>
using namespace std;

template<typename T>
struct Node{
    T key;
    Node *p;
    Node *left;
    Node *right;
};

template<typename T>
class Binary_tree{
public:
    Binary_tree();
    Binary_tree(Node<T> *root_node);
    void Inorder_tree_walk(Node<T> *x);
    void Preorder_tree_walk(Node<T> *x);
    void Postorder_tree_walk(Node<T> *x);
    Node<T>* Tree_search(Node<T> *x, T k);
    Node<T>* Iterative_search(Node<T> *x, T k);
    Node<T>* Tree_minimum(Node<T> *x);
    Node<T>* Tree_maximum(Node<T> *x);
    Node<T>* Tree_successor(Node<T> *x);
    Node<T>* Tree_predeccessor(Node<T> *x);
    void Insert(Node<T> *z);
    Node<T>* Delete(Node<T> *z);
    Node<T> *root;

};

#endif