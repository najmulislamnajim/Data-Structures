#include<bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node * next;
};

class LinkedList{
public:
    node * head;
    int sz;

    LinkedList(){
        head=NULL;
        sz=0;
    }

    node* CreateNewNode(int value){
        node *newnode=new node;
        newnode->data=value;
        //pointer ei jonno arrow diye access korte hocche.
        newnode->next=NULL;
        sz++;
        return newnode;
    }

    void InsertAtHead(int value){
        node *newnode=CreateNewNode(value);
        if(head==NULL){
            head=newnode; // = mane new node a point kore thakbe
            return;
        }
        newnode->next=head;
        head=newnode;
    }

    void Insert(int index,int value){
        if(index<0 || index>sz)return; //corner case
        node *a=head;
        if(index==0){
            InsertAtHead(value);
            return;
        }else{
            index--;
        }
        while(index--){
            a=a->next;
        }
        node *newnode=CreateNewNode(value);
        newnode->next=a->next;
        a->next=newnode;
    }

    void DeleteHead(){
        if (head==NULL)return; //corner case
        sz--; //size maintain
        node *a=head;
        head=a->next;
        delete a;
    }
    void Delete(int index){
        if (index<0 || index>=sz)return;
        if (index==0){
            DeleteHead();
            return;
        }
        sz--; //size maintain
        node *a=head;
        index--;
        while(index--){
            a=a->next;
        }
        node *temp=a->next;
        a->next=temp->next;
        delete temp;
    }

    void Travers(){
        node * travers=head;
        while(travers!=NULL){
            cout<<travers->data<< " ";
            travers=travers->next;
        }
        cout<<endl;
    }


    int SearchFirstOccurance(int value){
        node *a=head;
        int index=0;
        while(a!=NULL){
            if(a->data==value){
                return index;
            }
            a=a->next;
            index++;
        }
        return -1;
    }
    vector<int> SearchAllOccurance(int value){
        node *a=head;
        int index=0;
        vector<int>res;
        while(a!=NULL){
            if(a->data==value){
                res.push_back(index);
            }
            a=a->next;
            index++;
        }
        return res;
    }

    void PrintAllOccurance(int value){
        node *a=head;
        int index=0;
        cout<<"Printing all Occurance Index: ";
        while(a!=NULL){
            if(a->data==value){
                cout<<index << " ";
            }
            a=a->next;
            index++;
        }
        cout<<endl;
    }

    int ListSize(){
        return sz;
    }
    void PrintSize(){
        cout<<"List Size Is: "<<sz<<endl;
    }

};

int main(){
    LinkedList llist;
    llist.InsertAtHead(10);
    llist.InsertAtHead(15);
    llist.InsertAtHead(20);
    llist.InsertAtHead(25);
    llist.InsertAtHead(30);
    llist.InsertAtHead(25);
    llist.InsertAtHead(35);
    llist.InsertAtHead(20);
    llist.Travers();
    llist.PrintSize();
    cout<<"First Occurance of "<<5<<"is: "<<llist.SearchFirstOccurance(5)<<endl;
    cout<<"First Occurance of "<<10<<"is: "<<llist.SearchFirstOccurance(10)<<endl;
    vector<int>all;
    all=llist.SearchAllOccurance(25);
    cout<< "Printing all occurance : ";
    for (int it:all){
        cout<<it<< " ";
    }
    cout<<endl;
    llist.PrintAllOccurance(20);
    llist.Travers();
    llist.Insert(1,80);
    llist.Travers();
    llist.Insert(0,90);
    llist.Travers();

    llist.PrintSize();
    llist.DeleteHead();
    llist.Travers();
    llist.PrintSize();

    llist.Delete(1);
    llist.Travers();
    llist.PrintSize();
    llist.Delete(8);
    llist.Travers();
    llist.PrintSize();
    llist.Delete(7);
    llist.Travers();
    llist.PrintSize();

    llist.Insert(7,10);
    llist.Travers();
    llist.PrintSize();

    return 0;
}
