// Linkedlist implementation of Queue
//operations: 
/*
1.Enqueue
2. Dequeue
3. Peek
4. IsEmpty
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Queue{
public:
    Node* front;
    Node* tail;

    Queue(){
        front=NULL;
        tail=NULL;
    }

    bool isEmpty(){
        if(front==NULL) return true;
        return false;
    }

    void Enqueue(int x)
    {
        Node* tmp= new Node(x);
        if(isEmpty())
        {
            front=tmp;
            tail=tmp;
            return;
        }
        tail->next=tmp;
        tail=tail->next;
        return;
    }

    bool Dequeue(){
        Node* tmp=front;
        if(isEmpty())
        {
            cout<<"Queue is already empty. Dequeue operation not possible."<<endl;
            return false;
        }
        front=front->next;
        delete tmp;
        return true;
    }

    void Peek(){
        if(isEmpty())
        {
            cout<<"Empty Queue. Nothing to show"<<endl;
            return;
        }
        cout<<tail->data<<endl;
    }

    void Display()
    {
        Node* ptr=front;
        while (ptr)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        cout<<"Null"<<endl;
        return;
    }
    
};

int main()
{
    Queue q;
    q.Dequeue();
    q.Enqueue(5);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Display();
    q.Dequeue();
    q.Display();
    q.Peek();

    return 0;
}