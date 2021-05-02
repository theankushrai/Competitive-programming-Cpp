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

int findMaxUtil(Node* root, int &res)
{
    if (root == NULL)
        return 0;
  
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);

    int max_single = max(max(l, r) + root->data, root->data);
    int max_top = max(max_single, l + r + root->data);
  
    res = max(res, max_top);
  
    return max_single;
}
  
// Returns maximum path sum in tree with given root
int findMaxSum(Node *root)
{  int ans=INT_MIN;
    findMaxUtil(root,ans);
    return ans;
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
    cout<<findMaxSum(node);
    return 0;
}  