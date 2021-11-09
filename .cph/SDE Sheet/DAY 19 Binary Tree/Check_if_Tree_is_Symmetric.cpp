/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

// 1.using recursion
// check for left of right subtree and right of left subtree and vice versa
//time complexity n;
//auxillary space n;

bool check(TreeNode* left,TreeNode* right){
        if(left==nullptr&&right==nullptr)return true;
        if(left==nullptr||right==nullptr||left->val!=right->val)return false;
        
        bool c1=check(left->right,right->left);
        bool c2=check(left->left,right->right);
        
        if(c1&&c2)return true;
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return check(root->left,root->right);
    }
