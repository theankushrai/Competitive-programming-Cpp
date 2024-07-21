// Given a binary tree, determine if it is 
// height-balanced
// .

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

// 1. using height logic and balanced tree or not check variable
// time complexit O(N)
// auxillary space O(n)


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

    int isbalanced(TreeNode* root, bool& result){
        if(!root)return 0;
        int lh=isbalanced(root->left,result);
        int rh=isbalanced(root->right,result);
        if(abs(lh-rh)>1) result=false;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        bool result=true;
        isbalanced(root,result);
        return result;
    }
};