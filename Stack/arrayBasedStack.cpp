// Array based stack implementation
#include<iostream>
using namespace std;

class Stack{
int A[10];
int top=-1;
public:
    bool isEmpty(){
        if(top==-1)
            return true;
        else 
            return false;
    }
    int Top()
    {
        if(isEmpty())
        {
            cout<<"\n Stack is empty"<<endl;
            return -1;
        }
        return A[top];
    }
    void push(int x)
    {
        top++;
        A[top]=x;
    }
    void pop()
    {
        if(isEmpty()) return;
        top--;
    }

};

int main()
{
    Stack box;
    cout<<"Is box empty? "<<box.isEmpty()<<endl;
    box.push(3);
    box.push(6);
    box.push(9);
    cout<<"Top value in box: "<<box.Top()<<endl;
    box.pop();
    box.pop();
    cout<<"Top value is box: "<<box.Top()<<endl;
    cout<<"Is box empty? "<<box.isEmpty()<<endl;
    return 0;
}