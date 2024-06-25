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

    void InsertAtTail(int value){
        Insert(sz,value);
    }

    void InsertAfterValue(int value,int data){
        node *a=head;
        while(a!=NULL){
            if(a->data==value){
                break;
            }
            a=a->next;
        }
        if(a!=NULL){
            node *newnode=CreateNewNode(data);
            newnode->next=a->next;
            a->next=newnode;
        }
        
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

    void DeleteAtTail(){
        Delete(sz-1);
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

    void Reverse(){
        node *a=head;
        node *temp2;
        while(a!=NULL){
            node *temp=a->next;
            if(a==head){
                a->next=NULL;
            }else{
                a->next=temp2;
            }
            temp2=a;
            a=temp;
        }
        head=temp2;
    }

    void Sorting(){
        node *a=head;
        vector<int>arr;
        while(a!=NULL){
            arr.push_back(a->data);
            a=a->next;
        }
        sort(arr.begin(),arr.end());
        int ind=0;
        a=head;
        while(a!=NULL){
            a->data=arr[ind]; 
            ind++;
            a=a->next;
        }

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

    llist.InsertAtTail(5);
    llist.Travers();
    llist.PrintSize();

    llist.DeleteAtTail();
    llist.Travers();
    llist.PrintSize();

    llist.InsertAfterValue(10,5);
    llist.Travers();
    llist.PrintSize();

    llist.InsertAfterValue(2,1);
    llist.Travers();
    llist.PrintSize();

    llist.Reverse();
    llist.Travers();
    llist.InsertAtTail(40);
    llist.Travers();

    llist.Sorting();
    llist.Travers();

    return 0;
}

/*
1. Insert At Heat
2. Insert At any Position
3. Insert At Tail
4. Delete Head
5. Delete At any Position
6. Delete At Tail
7. Search First Occurance
8. Search All Occurance
9. Print All Occurance
10. List Size
11. Print Size
12. Travers
13. Insert after value
14. Reverse
15. Sorting 

*/
