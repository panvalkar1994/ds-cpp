// Level order traversal of Binary Search Tree also known as breadth first search

#include<iostream>
#include<queue>
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

void LevelOrderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node* cur=Q.front();
        cout<<cur->data<<" ";
        if(cur->left!=NULL) Q.push(cur->left);
        if(cur->right!=NULL) Q.push(cur->right);
        Q.pop();
    }
    cout<<endl;
}

int main()
{
    Node* root=NULL;
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,0);
    root=insert(root,3);
    root=insert(root,40);
    root=insert(root,-40);
    root=insert(root,10);
    LevelOrderTraversal(root);
    return 0;
}