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

bool is_BST(Node* root, int min, int max){
    if(root==nullptr) return true;
    if(min&&root->data<=min) return false;
    if(max&&root->data>=max) return false;

    bool right=is_BST(root->right,root->data,max);
    bool left=is_BST(root->left,min,root->data);

    return left and right;
    // and is bitwise  while && is logical
}

int main()
{
    Node* node=new Node(4);
    node->left=new Node(2);
    node->right=new Node(7);
    node->left->left=new Node(1);
    node->left->right=new Node(3);
    node->right->left=new Node(6);
    node->right->right=new Node(8);  
    cout<<is_BST(node,INT_MIN,INT_MAX)<<endl;
    return 0;
}