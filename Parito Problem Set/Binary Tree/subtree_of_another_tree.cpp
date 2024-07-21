// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

// Example 1:


// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true
// Example 2:


// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false
 

// Constraints:

// The number of nodes in the root tree is in the range [1, 2000].
// The number of nodes in the subRoot tree is in the range [1, 1000].
// -104 <= root.val <= 104
// -104 <= subRoot.val <= 104

// 1. using issanem algorithm
// time complexit O(N)
// auxillary space O(N)


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
    bool issame(TreeNode* root, TreeNode* subroot){//is tree same algo
        if(!root&&!subroot)return true;
        if(!root||!subroot)return false;
        if(root->val!=subroot->val)return false;
        return issame(root->left,subroot->left)&&issame(root->right,subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!subroot) return true;//if subroot is not present then its true
        if(!root)return false;//if root is not present return false u didnt find subtree
        if(root->val==subroot->val){ //if value of given node and subroot is same 
            if(issame(root,subroot))return true;//then check if the subtree is same, if yes return true
        }
        return isSubtree(root->left,subroot)||isSubtree(root->right,subroot); //if not check other nodes in tree
    }
};