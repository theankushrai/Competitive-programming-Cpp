
/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

 TreeNode* build(vector<int>& postorder,int ps,int pe,unordered_map<int,int>& inorder,int is, int ie){
        
        if(ps>pe||is>ie)return nullptr;
        
        TreeNode* root=new TreeNode(postorder[pe]);
        int root_idx=inorder[root->val];
        int nums_right=ie-root_idx;
        
        root->left=build(postorder,ps,pe-nums_right-1,inorder,is,root_idx-1);
        root->right=build(postorder,pe-nums_right,pe-1,inorder,root_idx+1,ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& postorder) {
        unordered_map<int,int> inorder;
        for(int i =0;i<in.size();i++)inorder[in[i]]=i;
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }