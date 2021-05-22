// BST  finding min and max in the tree using loop and recursion
#include<iostream>
#include<climits>
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
// find min using loop
int findMin(Node* root)
{
    if(root==NULL)
    {
        cout<<"This tree is empty"<<endl;
        return INT_MAX;
    }
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

//finding max using loop
int findMax(Node* root)
{
    if(root==NULL)
    {
        cout<<"This tree is empty"<<endl;
        return INT_MIN;
    }
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}

//finding min using recursion
int minNum(Node* root)
{
    if(root==NULL){
        cout<<"Error: tree is empty"<<endl;
        cout<<INT_MAX;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return minNum(root->left);
}



int main()
{
    Node* root=NULL;
    // root=insert(root,5);
    // root=insert(root,15);
    // root=insert(root,4);
    // root=insert(root,40);
    // root=insert(root,-40);
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
    cout<<minNum(root)<<endl;
    display(root);
    return 0;
}