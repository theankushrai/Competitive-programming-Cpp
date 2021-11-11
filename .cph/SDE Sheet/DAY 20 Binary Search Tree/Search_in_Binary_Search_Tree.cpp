/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107*/

// 1.using bst property
// time complexity logn if we do not consider skewed tree;
// space complexity height of tre;

 TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr||root->val==val)return root;
        if(val<root->val) return searchBST(root->left,val);
        return searchBST(root->right,val);
    }

//2.using while loop
//time complexity n;
//space complexity O(1);

TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        while(curr){
            if(curr->val==val)break;
            if(val<curr->val)curr=curr->left;
            else if(val>curr->val)curr=curr->right;
        }
        return curr;
    }