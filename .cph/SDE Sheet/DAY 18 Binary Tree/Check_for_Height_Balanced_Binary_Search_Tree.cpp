/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104*/

// 1.brute force - finding height of all subtree and checking if they are balanced
// time complexity n2;
// auxillary space n;

int height(TreeNode* root){
        if(root==nullptr)return 0;
        return (1+max(height(root->left),height(root->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(rh-lh)>1)return false;
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(left&&right)return true;
        return false;
    }

// 2. refined height algorithm
//time complexity n;
//auxillary space n;

int balanced(TreeNode* root){
        if(root==nullptr)return 0;
        
        int lh=balanced(root->left);
        int rh=balanced(root->right);
        if(lh==-1||rh==-1)return -1;
        if(abs(rh-lh)>1)return -1;
        
        return (1+max(lh,rh));
    }
    bool isBalanced(TreeNode* root) {
        if(balanced(root)==-1)return false;
        return true;
    }