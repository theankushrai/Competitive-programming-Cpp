
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

Node* LCA(Node* root,int n1, int n2){
    
    if(root==nullptr) return nullptr;
    if(root->data==n1||root->data==n2)return root;

    //find whether n1 adn n2 are in left or right subtree
    Node* left= LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);

    if(left==nullptr&&right==nullptr)return nullptr;
    if(left==nullptr) return LCA(root->right,n1,n2);
    if(right==nullptr) return LCA(root->left,n1,n2);
    return root;//when both are not null that means n1 is in left subtree and n2 is in right subtree and thus lca will be root node
}

int finddistance(Node* root, int endnode, int distance){
    if(root==nullptr) return -1;
    if(root->data==endnode) return distance;

    int left=finddistance(root->left,endnode,distance+1);
    if(left!=-1) return left;

    return finddistance(root->right,endnode,distance+1);

    
}

int distancebetweennodes(Node* root,int n1, int n2){

    Node* lca=LCA(root,n1,n2);

    //finding distanc of n1 and n2 from lca
    int d1=finddistance(lca,n1,0);
    int d2=finddistance(lca,n2,0);

    return d1+d2;
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
    cout<<distancebetweennodes(node,4,5);
    return 0;
}