// BST implementation
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* root, int x)
{
    if(root==NULL){
        Node* cur=new Node(x);
        root=cur;
    }
    else if(root->data>=x){
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }
    return root;
}

void display(Node* root)
{
    if(root==NULL)
    {
        // cout<<"NULL"<<endl;
        return;
    }
    else
    {
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
    // cout<<"NULL"<<endl;
}

bool search(Node* root,int x)
{
    if(root==NULL) return false;
    else if(root->data==x) return true;
    else if(root->data>x)
    {
        return search(root->left,x);
    }
    else return search(root->right,x);
}

int main()
{
    Node* root=NULL;
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,4);
    root=insert(root,40);
    root=insert(root,-40);
    int number;
    cout<<"Search a number: ";
    cin>>number;
    if(search(root,number)==true) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
    display(root);
    return 0;
}