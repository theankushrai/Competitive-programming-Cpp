// smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:


// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// 1. using inorder and giving kth value 
// tiem compleixty n
// space complexity n 
// auxillary space n 

// 2. using inorder and keeping count - instead of count we just subtract k 
// time complexity n ;
// auxillary spac n;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void findsmallest(TreeNode* root, int &k , int &ans){
        if(!root)return;
        findsmallest(root->left, k  , ans);
        k--;
        if(k==0)ans=root->val;
        findsmallest(root->right, k ,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        findsmallest(root,k,ans);
        return ans;
    }
};
