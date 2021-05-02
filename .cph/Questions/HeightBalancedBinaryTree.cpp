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

int heightoftree(Node* node){
    if(node==nullptr) return 0;
    return heightoftree(node->left)+heightoftree(node->right)+1;
}

bool isHeightBalanced(Node* root){
    if(root==nullptr) return true;

    if((isHeightBalanced(root->right)==false)||(isHeightBalanced(root->left)==false)) return false;

    int lh=heightoftree(root->left);
    int rh=heightoftree(root->right);

    if(abs(lh-rh)<=1) return true;
    else return false;
}

//reducing the time complexity of the function by calculating height within the function

bool isbalanced(Node* root,int* height){
    int lh=0,rh=0;
    if(root==nullptr){
        *height=0;
        return true; 
    }
    
    if((isbalanced(root->right,&rh)==false)||(isbalanced(root->left,&rh)==false)) return false;

    
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)return true;
    return false;

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
    int height=0;
    cout<<isbalanced(node,&height)<<endl;
    cout<<isHeightBalanced(node);
    return 0;
}