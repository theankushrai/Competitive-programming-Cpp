
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
void leftview(Node* root){
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n =q.size();
        for (int i = 0; i < n; i++)
        {
            Node* temp=q.front();
            q.pop();
            
            if(temp!=nullptr){
                if(i==0) cout<<temp->data<<" ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        
    }
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
    leftview(node);
    return 0;
}