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

struct info {
    int size;
    int max;
    int min;
    int ans;
    bool isBST;

};



 info largestBST(Node* root){
    if(root==nullptr) return {0,INT_MIN,INT_MAX,0,true};
    if(root->left==nullptr&&root->right==nullptr) return {1,root->data,root->data,1,true};

    info leftinfo=largestBST(root->left);
    info rightinfo=largestBST(root->right);

    info curr;

    curr.size=1+leftinfo.size+rightinfo.size;

    if(leftinfo.isBST&&rightinfo.isBST&&leftinfo.max<root->data&&rightinfo.min>root->data){
        curr.min=min(leftinfo.min,min(rightinfo.min,root->data));
        curr.max=max(leftinfo.max,max(rightinfo.max,root->data));
        curr.ans=curr.size;
        curr.isBST=true;

        return curr;
    }
    curr.ans=max(leftinfo.ans,rightinfo.ans);
    curr.isBST=false;

    return curr;  
}


int main()
{
    Node* root=new Node(60);
    root->left = new Node(65);
    root->right =new  Node(70);
    root->left->left = new Node(50);
    cout<<largestBST(root).ans<<endl;
    return 0;
}