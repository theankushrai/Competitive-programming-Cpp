 
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

void inorder(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    inorder(root->left);
    
    inorder(root->right);
}

Node* BuildBST(int a[],int start, int end){
    if(start>end) return nullptr;
    
    int mid=(start+end)/2;
    Node* root=new Node(a[mid]);
    
    root->left=BuildBST(a,start,mid-1);
    root->right=BuildBST(a,mid+1,end);

    return root;

    
}

int main()
{
    int sortedArray[]={1,2,3,4,5,6,7,8,9};
    int s=0;
    int e=8;
    Node* root=BuildBST(sortedArray,s,e);
    inorder(root);

    return 0;
}