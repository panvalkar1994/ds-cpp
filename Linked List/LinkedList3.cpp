//Linked List: Here node will be added to end , i.e. FIFO
#include<iostream>
using namespace std;
//Define a Node object
class Node{
public:
    int data;
    Node* next;
};


//Global head 
Node* head;

//Insert function
void insert(int data);

//Print list function
void printList();

int main()
{
    head=NULL;//head points to null
    int value;
    int t;
    cout<<"Enter Number of inputs: "<<'\n';
    cin>>t;
    while (t--)
    {
        cout<<"Enter a number: "<<"\n";
        cin>>value;
        //TODO: Insert function to add number at end of list
        insert(value);
    }
    //TODO: Print function to display all elements of list
    printList();
    return 0;   
}

void insert(int data)
{
    Node* ptr;
    Node* newnode;

    //Strating with original head value
    ptr=head;

    newnode=new Node();
    newnode->data=data;
    newnode->next=NULL;

    
    if(head==NULL)//inserting first element
    {
        head=ptr=newnode;
    }
    else
    {
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
    

}

void printList()
{
    Node *ptr;
    ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
}