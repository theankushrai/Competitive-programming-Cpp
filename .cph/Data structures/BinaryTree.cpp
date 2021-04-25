#include<iostream>
#include<queue>
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

void preorder(struct node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void midorder(struct node* root){
    if(root==nullptr){
        return;
    }
    midorder(root->left);
    cout<<root->data<<" ";
    midorder(root->right);
}
void postorder(struct node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(struct node* root){
    if(root==nullptr) return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
        while(!q.empty()){
            node* n = q.front();
            q.pop();
            if(n!=nullptr){
                cout<<n->data<<" ";    
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            else if(!q.empty()){
                q.push(nullptr);
                cout<<endl;
            }
        }
}
int main()
{
    struct node* root=new node(1);   
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    preorder(root);
    cout<<endl;
    midorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    return 0;
}