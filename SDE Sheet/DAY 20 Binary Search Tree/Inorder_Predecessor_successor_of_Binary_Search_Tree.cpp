/*
There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
 
*/

// 1.getting inorder and then checking predecessor and successor;
// time complexity n;
// space compelxity n;
// auxillary space n;

void inorder(Node* root, vector<Node*>&a){
        if(root==NULL)return;
        inorder(root->left,a);
        a.push_back(root);
        inorder(root->right,a);
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        vector<Node*> a;
        inorder(root,a);
        
        int i,n=a.size();
        Node* ans=NULL;
        
        for(i =0;i<n;i++){
     
            if(a[i]->data==x->data)break;
        }
        if(i<n-1)ans=new Node(a[i+1]->data);
        return ans;
    }

//2.using recursion
// time complexity n;
//space compleixy H;

void predecessor(Node* root,Node*&pre,int key){
    if(root==NULL)return;
    if(key<=root->key)predecessor(root->left,pre,key);
    else{
        pre=root;
        predecessor(root->right,pre,key);
    }
}

void successor(Node* root, Node*&suc,int key){
    if(root==NULL)return;
    if(key>=root->key)successor(root->right,suc,key);
    else{
        suc=root;
        successor(root->left,suc,key);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    predecessor(root,pre,key);
    successor(root,suc,key);
}

//3.while loop
//time complexity n;
//space complexity O(1);

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* curr=root;
    
    while(curr){
        if(key>=curr->key)curr=curr->right;
        else{
            suc=curr;
            curr=curr->left;
        }
    }
    curr=root;
    
    while(curr){
        if(key<=curr->key)curr=curr->left;
        else{
            pre=curr;
            curr=curr->right;
        }
    }
}