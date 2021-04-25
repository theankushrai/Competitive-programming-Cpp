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

int levelordersum(Node* root,int k){
    if(root==nullptr) return -1;
    int sum=0,level=0;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp!=nullptr){
            if(level==k)sum+=temp->data;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        else if(!q.empty()){
            q.push(nullptr);
            level++;
            if(level>k)return sum;
        }
    }
    return sum;
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
    cout<<levelordersum(node,1);
    return 0;
}