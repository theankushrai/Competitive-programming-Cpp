/*Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.*/

// 1.brute force - insert all the nodes one by one;
// time complexity n2;

 void insert(TreeNode* &root,int val){
        
        if(root==nullptr){
             root=new TreeNode(val);
            return;
        }
        TreeNode* curr=root;
        while(true){
            if(val<curr->val){
                if(curr->left)curr=curr->left;
                else {
                    curr->left= new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->right) curr=curr->right;
                else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }
        }
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(auto it:preorder){
            insert(root,it);
        }
        return root;
    }

//2.getting inorder and then creating from preorder and inorder;
//time complexity n;
//auxillary space n;
//space complexity n; for storing inorder

 TreeNode* construct(vector<int> & preorder,int ps, int pe,unordered_map<int,int> &inorder,int is, int ie){
        if(ps>pe||is>ie)return nullptr;
        
        TreeNode* root=new TreeNode(preorder[ps]);
        int root_idx=inorder[root->val];
        int nums_left=root_idx-is;
        
        root->left=construct(preorder,ps+1,ps+nums_left,inorder,is,root_idx-1);
        root->right=construct(preorder,ps+nums_left+1,pe,inorder,root_idx+1,ie);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> in(preorder.begin(),preorder.end());
        sort(in.begin(),in.end());
        
        unordered_map<int,int> inorder;
        int n =preorder.size();
        for(int i =0;i<n;i++)inorder[in[i]]=i;
        
        return construct(preorder,0,n-1,inorder,0,n-1);
        
    }

//3.using validate BST upper and lower bound;
//time complexity n;
//auxillary space H;

TreeNode* build(vector<int> preorder,int & i,int ub){
        if(i==preorder.size()||preorder[i]>ub)return nullptr;
        
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        int ub=INT_MAX;//upper bound;
        return build(preorder,i,ub);
    }

