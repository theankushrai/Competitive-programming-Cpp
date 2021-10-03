#include<vector> 
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

vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(nullptr);
        return trees;
    }
    for (int i = start; i <=end; i++)
    {
        vector<Node*> leftsubtree=constructTrees(start,i-1);
        vector<Node*> rightsubtree=constructTrees(i+1,end);
        
        for (int j = 0; j < leftsubtree.size(); j++)
        {    Node* left=leftsubtree[j];
            for (int k = 0; k < rightsubtree.size(); k++)
            {   
                Node* right=rightsubtree[k];
                Node* node= new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
            
        }
        
    }
    return trees;
}

void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<Node*> totaltrees=constructTrees(1,3);
    for (int i = 0; i < totaltrees.size(); i++)
    {
        // cout<<i+1<<endl;
        cout<<endl;
        preorder(totaltrees[i]);
    }
    
    return 0;
}