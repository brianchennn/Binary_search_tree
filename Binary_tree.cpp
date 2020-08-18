#include"Binary_tree.h"
#include<iostream>
using namespace std;
template<typename T>
Binary_tree<T>::Binary_tree(){
    root = 0;
}
template<typename T>
Binary_tree<T>::Binary_tree(Node<T> *root_node){
    root = *root_node;
    root_node->p = 0;
    root_node->left = 0;
    root_node->right = 0;
}
template<typename T>
void Binary_tree<T>::Inorder_tree_walk(Node<T> *x){
    if(x != 0){
        Inorder_tree_walk(x->left);
        cout<<x->key<<" ";
        Inorder_tree_walk(x->right);
    }
    
}
template<typename T>
void Binary_tree<T>::Preorder_tree_walk(Node<T> *x){
    cout<<x->key<<" ";
    if(x!=0){
        Preorder_tree_walk(x->left);
        Preorder_tree_walk(x->right);
    }
}
template<typename T>
void Binary_tree<T>::Postorder_tree_walk(Node<T> *x){
    if(x!=0){
        Postorder_tree_walk(x->left);
        Postorder_tree_walk(x->right);
        cout<<x->key<<" ";
    }
}
template<typename T>
Node<T>* Binary_tree<T>::Tree_search(Node<T> *x, T k){
    if(x != 0 || k == x->key){
        return x;
    }
    if(k < x->key){
        return Tree_search(x->left[x],k);
    }else{
        return Tree_search(x->right, k);
    }
}
template<typename T>
Node<T>* Binary_tree<T>::Iterative_search(Node<T> *x, T k){
    while(x != 0 || k != x->key){
        if(k < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    return x;
}
template<typename T>
Node<T>* Binary_tree<T>::Tree_minimum(Node<T> *x){
    while(x->left != 0){
        x = x->left;
    }
    return 0;
}
template<typename T>
Node<T>* Binary_tree<T>::Tree_maximum(Node<T> *x){
    while(x->left != 0){
        x = x->right;
    }
    return 0;
}
template<typename T>
Node<T>* Binary_tree<T>::Tree_successor(Node<T> *x){
    if(x->right != 0){
        return Tree_successor(x->right);
    }
    Node<T>* y = x->p;
    while(y != 0 && x == y->right){
        x = y;
        y = y->p;
    }
    return y;
}
template<typename T>
Node<T>* Binary_tree<T>::Tree_predeccessor(Node<T> *x){
    if(x->left != 0){
        return Tree_Predeccessor(x->left);
    }
    Node<T>* y = x->p;
    while(y != 0 && x == y->left){
        x = y;
        y = y->p;
    }
    return y;
}
template<typename T>
void Binary_tree<T>::Insert(Node<T> *z){
    Node<T> *y = 0;
    Node<T> *x = root;
    while (x != 0){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->p = y ;
    if(y == 0){
        root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
}
template<typename T>
Node<T>* Binary_tree<T>::Delete(Node<T> *z){
    Node<T> *y, *x;
    if(z->left == 0 || z->right == 0){
        y = z;
    }else{
        y = Tree_successor(z);
    }
    if(y->left != 0){
        x = y->left;
    }else{
        x = y->right;
    }
    if(x != 0){
        x->p = y->p;
    }
    if(y->p == 0){
        root = x;
    }else if(y == y->p->left){
        y->p->left = x;
    }else{
        y->p->right = x;
    }
    if(y != z){
        z->key = y->key;
        z->p = y->p;
        z->left = y->left;
        z-> right = y->right;
    }
    return y;
}

