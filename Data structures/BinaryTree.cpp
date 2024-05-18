#include<algorithm>
#include<iostream>
#include<stack>
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
// void lEVELOrderTraversal(struct node* root){
//     if(root==nullptr) return;
//     queue<Node*> q;
//     q.push(root);
//     q.push(nullptr);

//     while(!q.empty()){
//         int n =q.size();
//         for (int i = 0; i < n; i++)
//         {
//             Node* temp=q.front();
//             q.pop();

//             if(temp!=nullptr){
//                 cout<<temp->data<<" ";
//                 if(temp->left)q.push(temp->left);
//                 if(temp->right)q.push(temp->right);
//             }
//             else if(q.empty()==false){
//                 q.push(nullptr);
//                 cout<<endl;
//             }
            
//         }
        
//     }
// }
void reverseQueue(queue<node*>& Queue)
{
    stack<node*> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}
void zigzagTraversal(node* root){
    if(root==nullptr) return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    bool leftoright=true;
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp){
            cout<<temp->data<<" ";

            if(leftoright){
                if(temp->left )q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            else{
                if(temp->right) q.push(temp->right);
                if(temp->left )q.push(temp->left);
            }
        }
        else if(!q.empty()){
            reverseQueue(q);         
            q.push(nullptr);  
            leftoright= leftoright? false:true;
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
    
    zigzagTraversal(root);

    return 0;
}