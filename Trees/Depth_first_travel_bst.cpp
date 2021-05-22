// Implementation of Depth first traversal of a binary tree
// Preoder traversal <root/data><left><right>
// Inorder traversal <left><root/data><right>
// Postorder traversal <left><right><root/data>


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

// preorder traversal using recursion
void Preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
    // cout<<endl;
}

// Inoder traversal using recursion
void Inorder(Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}

// postorder traversal using recursion
void Postorder(Node* root){
    if(root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
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
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    return 0;
}