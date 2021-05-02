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

Node* insertinBST(Node* root, int val){
    if(root==nullptr){
        return new Node(val);
    }
    if(val<root->data) root->left=insertinBST(root->left,val);
    else{
        root->right=insertinBST(root->right,val);
    }
    return root;
}

Node* searchinBST(Node* root, int key){
    if(root==nullptr||root->data==key) return root;
    if(key>root->data)return searchinBST(root->right,key);
    if(key<root->data)return searchinBST(root->left,key);
    return nullptr;
}

Node* inordersuccessor(Node* root){
    Node * curr=root;
    while(curr&&curr->left!=nullptr){
        curr=curr->left;
    }
    return curr;
}

Node* deleteinBST(Node* root, int key){
    if(root==nullptr) return nullptr;
    else if(key>root->data) root->right=deleteinBST(root->right,key);
    else if(key<root->data) root->left=deleteinBST(root->left,key);
    else{
        if(root->left==nullptr){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==nullptr){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inordersuccessor(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
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
    Node* root=nullptr;
    root=insertinBST(root,5);
    insertinBST(root,6);
    insertinBST(root,1);
    insertinBST(root,3);
    insertinBST(root,4);
    insertinBST(root,2);
    insertinBST(root,7);
    inorder(root);
    cout<<endl;
    deleteinBST(root,6);
    inorder(root);
    
    
    return 0;
}