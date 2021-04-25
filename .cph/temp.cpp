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


int main()
{
    struct node* root=new node(1);   
    root->left->data=2;
    root->right->data=3;
    root->left->left->data=4;
    root->left->right->data=5;
    root->right->left->data=6;
    root->right->right->data=7;
    return 0;
}