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

void flatten(Node* root){
    if(root==nullptr||root->left==nullptr||root->right==nullptr) return;

    if(root->left!=nullptr){
        // step 1: Flatten left subree
        flatten(root->left);
        // step 2: store right ubtree in temp;
        Node* temp=root->right;
        // step 3: put root.left in place of root.right and put root.left =nullptr
        root->right=root->left;
        root->left=nullptr;
        // step 4: calculate tail of root.right
        Node* t = root->right;
        while(t->right!=nullptr){
            t=t->right;
        }
        //step 5: put temp(right subtree) in the right of root.right
        t->right=temp;
    }
    flatten(root->right);
}

void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    inorder(node);
    flatten(node);
    cout<<endl;
    inorder(node);
    return 0;
}  