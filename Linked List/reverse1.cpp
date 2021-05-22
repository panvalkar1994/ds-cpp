#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* append(Node *head, int data)
{
    Node *ptr = head;
    Node *cur = new Node(data);
    if(head==NULL)
    {
        head = cur;
        return head;
    }

    while (ptr!=NULL && ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = cur;
    
    return head;
}

Node* reverse(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *lead;
    if(head==NULL){
        return head;
    }
    while(cur!=NULL)
    {
        lead = cur->next;
        cur->next = prev;
        prev = cur;
        cur = lead;
    }
    return prev;
}

void printList(Node *head)
{
    Node *ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout <<"NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        head = append(head, arr[i]);
    }
    printList(head);
    head = reverse(head);
    printList(head);
    return 0;
}