# /*Given the root of a binary tree, return the length of the diameter of the tree.

# The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

# The length of a path between two nodes is represented by the number of edges between them.

 

# Example 1:


# Input: root = [1,2,3,4,5]
# Output: 3
# Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
# Example 2:

# Input: root = [1,2]
# Output: 1
 

# Constraints:

# The number of nodes in the tree is in the range [1, 104].
# -100 <= Node.val <= 100*/

# // 1.brute force- find diamter=leftheight+rightheight for every tree;
# // time complexity n2;
# //auxillary space n;

# int height(TreeNode* root){
#         if(root==nullptr)return 0;
#         return (1+max(height(root->left),height(root->right)));
#     }
    
#     void diameter(TreeNode* root,int &maxd){
#         if(root==nullptr)return;
#         maxd=max(maxd,height(root->left)+height(root->right));
#         diameter(root->left,maxd);
#         diameter(root->right,maxd);
#     }
    
#     int diameterOfBinaryTree(TreeNode* root) {
#         if(root==nullptr)return 0;
#         int maxd=0;
#         diameter(root,&maxd);
#         return maxd;
#     }

# //1.using height logic;
# //time complexity n;
# //auxxillary space n;
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxd=0
        def check_diameter(node):
            nonlocal maxd
            if not node:
                return 0
            lh=check_diameter(node.left)
            rh=check_diameter(node.right) 
            maxd=max(maxd,lh+rh)
            return 1+max(lh,rh) 
        
        check_diameter(root)
        return maxd