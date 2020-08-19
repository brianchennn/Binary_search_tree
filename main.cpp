#include"Binary_tree.h"
#include<iostream>
using namespace std;
int main()
{
    
    Node *n1 = new Node;
    n1 ->key = 5;
    Node *n2 = new Node;
    n2 ->key = 3;
    Node *n3 = new Node;
    n3 ->key = 11;
    Node *n4 = new Node;
    n4 ->key = 7;
    Node *n5 = new Node;
    n5 ->key = 10;
    Node *n6 = new Node;
    n6 ->key = 1;
    Node *n7 = new Node;
    n7 ->key = 19;
    Node *n8 = new Node;
    n8 ->key = 88;
    Node *n9 = new Node;
    n9 ->key = 75;
    Node *n10 = new Node;
    n10 ->key = 64;

    Binary_tree BTree;
    
    BTree.Insert(n1);
    BTree.Insert(n2);
    BTree.Inorder_tree_walk(BTree.root);
    BTree.Insert(n3);
    BTree.Insert(n4);
    BTree.Insert(n5);
    BTree.Insert(n6);
    BTree.Insert(n7);
    BTree.Insert(n8);
    BTree.Insert(n9);
    BTree.Insert(n10);
    
    BTree.Inorder_tree_walk(BTree.root);
    cout<<endl;
    BTree.Preorder_tree_walk(BTree.root);
    cout<<endl;
    BTree.Postorder_tree_walk(BTree.root);
    cout<<endl;
    Node * searched_node1 =  BTree.Tree_search(BTree.root,19);
    Node * searched_node2 =  BTree.Tree_search(BTree.root,88);
    Node * searched_node3 =  BTree.Tree_search(BTree.root,7);
    cout<<"now root is " << BTree.root->key << endl;
    cout << "search 19 : " << BTree.Tree_search(BTree.root,19)->key << endl;
    
    Node * min_node = BTree.Tree_minimum(BTree.root);
    cout << "minimum : " << min_node->key << endl;
    Node * max_node = BTree.Tree_maximum(BTree.root);
    cout << "maximam : " << max_node->key << endl;
    cout << "19's succssor : " << BTree.Tree_successor(searched_node1)->key << endl;
    Node * predecessor_node = BTree.Tree_predeccessor(searched_node2) ;
    cout << "88's predecessor :" << predecessor_node -> key << endl;
    cout << "Delete 88's predecessor \n" ; 
    BTree.Delete(predecessor_node);
    predecessor_node = BTree.Tree_predeccessor(searched_node2);
    cout << "88's new predecessor :" << predecessor_node -> key << endl;
    BTree.Tree_predeccessor(searched_node1);
    BTree.Inorder_tree_walk(BTree.root);
    cout << "\nDelete root\n";
    
    BTree.Delete(BTree.root);
    BTree.Inorder_tree_walk(BTree.root);
    cout<<"\nnow root is " << BTree.root->key << endl;
    cout<<"Index search 1 : "<<BTree.Index_search(1)->key<<endl;
    cout<<"Index search 2 : "<<BTree.Index_search(2)->key<<endl;
    cout<<"Index search 3 : "<<BTree.Index_search(3)->key<<endl;
    BTree.Inorder_tree_walk(BTree.root);

    //cout<<"Index search 2 : "<<BTree.Index_search(7)->key<<endl;
    //cout<<"Index search 3 : "<<BTree.Index_search(3)->key<<endl;
   
}