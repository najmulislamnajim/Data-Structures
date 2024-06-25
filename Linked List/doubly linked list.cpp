#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node *next;
    node *prev;
};

class LinkedList{
public:
    node *head;
    node *tail;
    int size;

    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    node *createNewNode(int value){
        node *newnode=new node;
        newnode->value=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        size++;
    }

    void InserAtHead(int value){
        node *newnode=createNewNode(value);
        if (head==NULL){
            head=newnode;
        }
    }

};