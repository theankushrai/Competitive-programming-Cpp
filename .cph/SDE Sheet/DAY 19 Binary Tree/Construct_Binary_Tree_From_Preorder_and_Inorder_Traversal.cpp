/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.*/

// 1. using recursion
// time complexity n;
//space complexity n;
//auxillary space n;

TreeNode* build(vector<int>& preorder,int ps,int pe,unordered_map<int,int> & inorder,int is,int ie){
        if(ps>pe||is>ie)return nullptr;
        
        TreeNode* root=new TreeNode(preorder[ps]);
        int inroot=inorder[root->val];
        int elements_left=inroot-is;
        
        //for left subtree;
        root->left=build(preorder,ps+1,pe,inorder,is,inroot-1);
        //for right subtree
        root->right=build(preorder,ps+elements_left+1,pe,inorder,inroot+1,ie);
    
        return root;    
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inor) {
        unordered_map<int,int> inorder;
        for(int i =0;i<inor.size();i++)inorder[inor[i]]=i;
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
    