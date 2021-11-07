/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100*/

//1.using level order traversal
//time complexity n;
//space complexity n;

 int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        int height=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            height++;
            for(int i =0;i<size;i++){
                TreeNode* temp=q.front();q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return height;
    }
    
// 2.using recursion
//time complexity n;
//auxillary space n;

int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        return (1+max(maxDepth(root->left),maxDepth(root->right)));
    }