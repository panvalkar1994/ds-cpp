// Check if given binary tree is a BST
// BST: It is special binary tree in which left subtree is lesser than equal to Node and right subtree is greater than Node

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


// Inoder traversal using recursion
void Inorder(Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}

bool IsBST(Node* root){
    // 
}


// Driver code
int main()
{
    Node* root=NULL;
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,2);
    root=insert(root,0);
    root=insert(root,40);
    root=insert(root,10);
    root=insert(root,3);
    return 0;
}
