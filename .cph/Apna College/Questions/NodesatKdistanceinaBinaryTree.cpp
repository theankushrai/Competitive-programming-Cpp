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

// case 1: finding nodes at subtree of the target node
void printsubtreenodes(Node* root,int k ){
    if(root==nullptr || k<0)return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}

//case 2: finding distance between target node and root node
int printnodesatk(Node* root,Node* target, int k ){
    if(root==nullptr) return -1;
    if(root==target){
        printsubtreenodes(root,k);
        return 0;
    }
    //finding if target exists at left subtree and at what distance
    int dl=printnodesatk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->right,k-dl-2);//distance dl+left to root(1)+rootto right(2)
        }
        return 1+dl;
    }
    //finding if target exists at left subtree and at what distance
    int dr=printnodesatk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->left,k-dr-2);//distance dl+left to root(1)+rootto right(2)
        }
        return 1+dr;
    }
    return -1;
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
   printnodesatk(node,node->left,2);
    return 0;
}  