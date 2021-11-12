/*Given a binary tree and a key(node) value, find the floor and ceil value for that particular key value.

Floor Value Node: Node with the greatest data lesser than or equal to the key value. 
Ceil Value Node: Node with the smallest data larger than or equal to the key value.

For example, Let’s consider the Binary Tree below – 



          8
        /   \    
      4      12
    /  \    /  \
   2    6  10   14

Key: 11  Floor: 10  Ceil: 12
Key: 1   Floor: -1  Ceil: 2
Key: 6   Floor: 6   Ceil: 6
Key: 15  Floor: 14  Ceil: -1*/


#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = key;
    return temp;
}

Node* insert(Node* root, int key)
{
    if (!root)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int ceil(Node* root, int key)
{
    int ans=-1;
    while(root){
        if(key==root->data)return key;
        if(key>root->data)root=root->right;
        else{
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}
 

int main()
{
       /* Let us create following BST
              7
            /    \
           5      10
         /  \    /  \
        3    6   8   12 */
    Node* root = NULL;
    root = insert(root, 7);
    insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);
    insert(root, 12);
    cout << ceil(root, 4) << endl;
    return 0;
 return 0;
}
