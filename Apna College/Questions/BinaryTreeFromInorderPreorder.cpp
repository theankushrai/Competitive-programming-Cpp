 
#include<iostream>
using namespace std;
 

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

//static - is used to allocate memory for the variable; it is only declared once and the value 
// gets forwarded every time you call the function

int search(int inorder[],int start,int end, int curr){
    for (int i = start; i <=end ; i++)
    {
        if(inorder[i]==curr) return i;
    }
    return -1;
    
}

node* buildtree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return nullptr;
    }
    int curr=preorder[idx];
    idx++;
    node* n=new node(curr);

    int pos=search(inorder,start,end,curr);

    if(start==end) return n;

    n->left=buildtree(preorder,inorder,start,pos-1);
    n->right=buildtree(preorder,inorder,pos+1,end);
    return n;
}

void inorderprint(node* root){
    if(root==nullptr) return;
    inorderprint(root->left);
    cout<<root->data<<endl;
    inorderprint(root->right);
}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    struct node* root=buildtree(preorder,inorder,0,4);
    inorderprint(root);

    return 0;
}