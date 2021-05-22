// Linked list based stack
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

class Stack{
public:
    Node* top;
    Stack()
    {
        top=NULL;
    }
    void push(int x){
        Node* ptr= new Node(x);
        if (top==NULL)
        {
            top=ptr;
            return;
        }
        ptr->next=top;
        top=ptr;
    }
    void pop(){
        Node* ptr=top;
        if(top==NULL)
        {
            return;
        }
        top=top->next;
        delete ptr;
        return;
    }
    void print()
    {
        Node* ptr=top;
        while(ptr)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    bool isEmpty()
    {
        if(top==NULL)
            return true;
        else 
            false;
    }
};

int main()
{
    Stack box;
    box.push(10);
    box.print();
    box.push(20);
    box.print();
    box.push(30);
    box.print();
    box.pop();
    box.print();
    box.pop();
    box.print();
    box.pop();
    box.print();
    return 0;
}