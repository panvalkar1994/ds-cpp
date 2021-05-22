#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        data=0;
        next=NULL;
        prev=NULL;
    }
    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};

class MyDll{
public:
    Node* head;
    Node* tail;
    MyDll(){
        head=NULL;
        tail=NULL;
    }
    void InsertAtHead(int x){
        Node* cur=new Node(x);
        if(head==NULL)
        {
            head=cur;
            tail=cur;
            return;
        }
        cur->next=head;
        head->prev=cur;
        head=cur;
    }
    void InsertAtTail(int x){
        Node* cur=new Node(x);
        if(head==NULL)
        {
            return InsertAtHead(x);
        }
        tail->next=cur;
        cur->prev=tail;
        tail=cur;
    }
    int Length(){
        int l=0;
        Node* ptr=head;
        while (ptr)
        {
            l++;
            ptr=ptr->next;
        }
        return l;
    }
    
    void InsertAtIndex(int index,int x)
    {
        int size=Length();
        if(size<index)
        {
            return;
        }
        if(index==0)
        {
            return InsertAtHead(x);
        }
        if(index==size)
        {
            return InsertAtTail(x);
        }
        int cnt=0;
        Node* ptr=head;
        Node* cur=new Node(x);
        while(ptr)
        {
            if(cnt==index)
            {
                cur->next=ptr;
                cur->prev=ptr->prev;
                ptr->prev->next=cur;
                return;
            }
            cnt++;
            ptr=ptr->next;
        }
        
    }
    void Print()
    {
        Node* ptr=head;
        // if(ptr==NULL)
        // {
        //     cout<<"Empty list"<<endl;
        //     return;
        // }
        while(ptr)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    MyDll list;
    list.InsertAtHead(10);
    list.InsertAtHead(30);
    list.Print();
    list.InsertAtTail(15);
    list.InsertAtIndex(2,255);
    list.Print();
    return 0;
}