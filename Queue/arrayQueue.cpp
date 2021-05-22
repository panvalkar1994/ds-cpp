// array based queue operations
#include<iostream>
using namespace std;


class Queue{
private:
    int A[10];
    int front;
    int rear;
public:
    Queue()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        if(rear==-1 && front==-1)
            return true;
        else 
            return false;
    }
    bool isFull()
    {
        //if rear is equal to last element index
        if(rear==9)
        {
            cout<<"The queue is full"<<endl;
            return true;
        }
        else
        {
            return false;
        }
        
    }
    bool Enqueue(int x)
    {
        if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
            A[rear]=x;
            rear++;
        }
        else
        {
            A[rear]=x;
            if(rear<9)
                rear++;
            else
            {
                rear=9;
            }
            
        }
        return true;
    }

    bool dequeue()
    {
        if(isEmpty())
        {
            return false;
        }
        else if(front<rear)
        {
            front++;
        }
        return true;
    }
    void display()
    {
        for(int i=front; i<rear;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    Queue arr;
    arr.Enqueue(5);
    arr.Enqueue(7);
    arr.Enqueue(10);
    arr.Enqueue(15);
    arr.display();
    arr.dequeue();
    arr.display();

    return 0;
}