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

int heightOftree(Node* root){
    if(root==nullptr) return 0;
    int lh=heightOftree(root->left);
    int rh=heightOftree(root->right);
    return max(lh,rh)+1;
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
    cout<<heightOftree(node);
    return 0;
}