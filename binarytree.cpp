#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int id;
    node *left;
    node *right;
    node *parent;
};

class BinaryTree{
public:
    node *root;
    BinaryTree(){
        root=NULL;
    }

    node *CreateNewNode(int id){
        node *newnode=new node;
        newnode->id=id;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent=NULL;
        return newnode;
    }

    void Traverse(){

    }

    void BFS(){
        queue<node*>tree;
        tree.push(root);
        while(!tree.empty()){
            node* a=tree.front();
            tree.pop();
            int p=-1,l=-1,r=-1;
            if(a->left!=NULL){
                l=a->left->id;
                tree.push(a->left);
            }

            if (a->right!=NULL){
                r=a->right->id;
                tree.push(a->right);
            }
            if(a->parent!=NULL){
                p=a->parent->id;
                tree.push(a->parent);
            }
            cout<<a->id<<" "<<p<<" "<<l<<" "<<r<<endl;
        }
    
    }



};