#include"Binary_tree.h"
#include<iostream>
using namespace std;


Binary_tree::Binary_tree(){
    root = 0;
}

Binary_tree::Binary_tree(Node *root_node){
    root = root_node;
    root_node->p = 0;
    root_node->left = 0;
    root_node->right = 0;
}

void Binary_tree::Inorder_tree_walk(Node *x){
    if(x != 0){
        Inorder_tree_walk(x->left);
        cout<<x->key<<" ";
        Inorder_tree_walk(x->right);
    }
}

void Binary_tree::Preorder_tree_walk(Node *x){
    
    if(x!=0){
        cout<<x->key<<" ";
        Preorder_tree_walk(x->left);
        Preorder_tree_walk(x->right);
    }
}

void Binary_tree::Postorder_tree_walk(Node *x){
    if(x!=0){
        Postorder_tree_walk(x->left);
        Postorder_tree_walk(x->right);
        cout<<x->key<<" ";
    }
}

Node* Binary_tree::Tree_search(Node *x, int k){
    if(x == 0 || k == x->key){
        return x;
    }
    if(k < x->key){
        return Tree_search(x->left,k);
    }else{
        return Tree_search(x->right, k);
    }
}

Node* Binary_tree::Iterative_search(Node *x, int k){
    while(x != 0 || k != x->key){
        if(k < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    return x;
}

Node* Binary_tree::Tree_minimum(Node *x){
    while(x->left != 0){
        x = x->left;
    }

    cout<<x->key<<endl;
    return x;
}

Node* Binary_tree::Tree_maximum(Node *x){
    while(x->right != 0){
        x = x->right;
    }
    return x;
}

Node* Binary_tree::Tree_successor(Node *x){
    if(x->right != 0){
        return Tree_minimum(x->right);
    }
    Node* y = x->p;
    Node *r = root->p;
    while(y != 0 && x == y->right){
        x = y;
        y = y->p;
    }
    return y;
}

Node* Binary_tree::Tree_predeccessor(Node *x){
    if(x->left != 0){
        return Tree_maximum(x->left);
    }
    Node* y = x->p;
    while(y != 0 && x == y->left){
        x = y;
        y = y->p;
    }
    return y;
}

void Binary_tree::Insert(Node *z){
    Node *y = 0;
    Node *x = root;
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

Node* Binary_tree::Delete(Node *z){
    Node *y, *x;
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

