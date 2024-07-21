// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

// 1. keeping a count and maxpointer
// time complexity - O(n)
// space complexity - O(1) auxillary space n 

class Solution {
public:

    void finddepth(int count, int & maxdepth,TreeNode* &root){
        if(!root)return;
        count++;
        maxdepth=max(count,maxdepth);
        finddepth(count,maxdepth,root->left);
        finddepth(count,maxdepth,root->right);

    }
    int maxDepth(TreeNode* root) {
        int maxdepth=0;
        finddepth(0,maxdepth,root);
        return maxdepth;
    }
};