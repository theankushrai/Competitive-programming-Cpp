#include<queue> 
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};


void sumreplacement(Node* root){
    if(root==nullptr) return ;

    sumreplacement(root->left);
    sumreplacement(root->right);

    if(root->left) root->data+=root->left->data;
    if(root->right)root->data+=root->right->data;
}

void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    Node* node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(3);
    node->left->left=new Node(4);
    node->left->right=new Node(5);
    node->right->left=new Node(6);
    node->right->right=new Node(7);
    preorder(node);
    cout<<endl;
    sumreplacement(node);
    preorder(node);
    return 0;
}