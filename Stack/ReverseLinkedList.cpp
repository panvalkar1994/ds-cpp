#include<iostream>
#include<stack>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Myll{
    public:
    Node* head;
    Node* tail;
    Myll(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val)
    {
        Node* cur= new Node(val);
        if(head==NULL)
        {
            head=cur;
            return;
        }
        
        Node* ptr=head;
        while (ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->next=cur;
        return;

    }
    void print()
    {
        Node* ptr=head;
        while (ptr)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }
};

void ReverseLL(Myll& ptr)
{
    stack<Node*> S;
    Node* p=ptr.head;
    if(!p) return;
    //pushing address of Nodes
    while (p)
    {
        S.push(p);
        p=p->next;
    }
    //reassembling ll
    p=S.top();
    ptr.head=p;
    S.pop();
    while (!S.empty())
    {
        p->next=S.top();
        S.pop();
        p=p->next;
    }
    //last elements direction to be set otherwise infinite loop will be generated.
    p->next=NULL;
    return;
}

int main()
{
    Myll list;
    for (int i = 0; i < 10; i++)
    {
        list.insert(i);
    }
    cout<<"printing list"<<endl;
    list.print();
    ReverseLL(list);
    list.print();
    return 0;
    
}