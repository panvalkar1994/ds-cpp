// Delete Node from BST
//Case 1:  Deleting leaf Node
//Case 2: Deleting Node with single Child
//Case 3: Deleting Node with two Children

// BST implementation
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

Node* findMin(Node* root)
{
    if(root==NULL)
    {
        cout<<"This tree is empty"<<endl;
        return root;
    }
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}


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

// Delete Node from BST and return pointer to new BST
Node* DeleteNode(Node* root, int val){
    // TODO
    if(root==NULL) return root;
    else if(val<root->data) root->left=DeleteNode(root->left,val);
    else if(val>root->data) root->right=DeleteNode(root->right,val);
    else{
    // We found the Node with the value
    // case 1: Leaf Node
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        // case 2(a): Single child Node... here only right child
        else if(root->left==NULL)
        {
            Node* tmp=root;
            root=root->right;
            delete tmp;
        }
        // case 2(b): Single child Node... here only left child
        else if(root->right==NULL)
        {
            Node* tmp=root;
            root=root->left;
            delete tmp;
        }
        // case 3: Both child are there
        else
        {
            // TODO
            Node* tmp=findMin(root->right);
            root->data=tmp->data;
            root->right=DeleteNode(root->right,tmp->data);
        }
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

    display(root);
    cout<<endl;
    root=DeleteNode(root,2);
    display(root);
    return 0;
}
