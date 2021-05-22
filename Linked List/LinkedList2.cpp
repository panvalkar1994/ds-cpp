//Linked List with  first in last out mechanism(LIFO)
#include<iostream>

using namespace std;

//Node structure
class Node {
public:
    int data;
    Node* next;
};

//Pointer to Head
Node* head;

//Insertion operation on Node
void insert_node(int value);

//Printing linked list
void print_list();

int main()
{
    //Pointer to Node which will be used as head
    head = NULL;
    //Input size
    int n, value;
    cout << "Size of linked list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a Number: ";
        cin >> value;
        insert_node(value);

    }
    print_list();
    return 0;
}

void insert_node(int value)
{
    Node* newnode;
    newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}


void print_list()
{
    Node* tmp;
    tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}