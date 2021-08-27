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

bool isIdentical(Node* root1, Node* root2){
    if(root1==nullptr&&root2==nullptr)return true;
    if(root1==nullptr||root2==nullptr)  return false;
    
    bool cond1= root1->data==root2->data;
    bool cond2=isIdentical(root1->left,root2->left);
    bool cond3=isIdentical(root1->right,root2->right);
    return cond1 and cond2 and cond3;
    // and is bitwise while && is logical;
}

int main()
{
    Node* node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(9);
    node->left->left=new Node(4);
    node->left->right=new Node(5);
    node->right->left=new Node(6);
    node->right->right=new Node(7);

    Node* node2=new Node(1);
    node2->left=new Node(2);
    node2->right=new Node(3);
    node2->left->left=new Node(4);
    node2->left->right=new Node(5);
    node2->right->left=new Node(6);
    node2->right->right=new Node(7);

    cout<<isIdentical(node,node2);

    return 0;
}