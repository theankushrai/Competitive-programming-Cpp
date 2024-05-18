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

Node* LCA(Node* root, int n1, int n2){
    if(root==nullptr||root->data==n1||root->data==n2)return root;
    Node* d1= LCA(root->left,n1,n2);
    Node* d2= LCA(root->right,n1,n2);
    if(d1&&d2) return root;
    return (d1!=nullptr)? d1:d2;
    return nullptr;
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
    cout<<LCA(node,4,6)->data<<endl;
    return 0;
}  