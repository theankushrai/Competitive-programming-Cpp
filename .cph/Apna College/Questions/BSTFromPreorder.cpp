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

Node* BuildTreefromPreorder(int preorder[],int* preorderidx, int key, int min, int max, int n){
   
   if(*preorderidx>=n) return nullptr;
   
    Node* root=nullptr;

    if(key>min&&key<max){
        root=new Node(key);
        *preorderidx=*preorderidx+1;

        if(*preorderidx<n){
            root->left=BuildTreefromPreorder(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }

        if(*preorderidx<n){
            root->right=BuildTreefromPreorder(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    return root;
}

//inorder of bst gives sorted sequence
void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int preorder[]={5,1,0,3,2,4,6,7};
    int n =8;
    int preorderidx=0;
    Node* root=BuildTreefromPreorder(preorder, &preorderidx,preorder[0],INT_MIN,INT_MAX,n);
    inorder(root);
    
    
    return 0;
}