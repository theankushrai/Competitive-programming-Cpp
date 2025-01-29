# Given the root of a binary tree, determine if it is a valid binary search tree (BST).

# A valid BST is defined as follows:

# The left 
# subtree
#  of a node contains only nodes with keys less than the node's key.
# The right subtree of a node contains only nodes with keys greater than the node's key.
# Both the left and right subtrees must also be binary search trees.
 

# Example 1:


# Input: root = [2,1,3]
# Output: true
# Example 2:


# Input: root = [5,1,4,null,null,3,6]
# Output: false
# Explanation: The root node's value is 5 but its right child's value is 4.
 

# Constraints:

# The number of nodes in the tree is in the range [1, 104].
# -231 <= Node.val <= 231 - 1


# 1. using inorder and sorting technique
# time complexity n;
# space compleixty n;
# auxillary spac n;

# 2. using low and high pointer
# time complexity n 
# auxilllary space n 

# 3. using dfs
# time complexity n
# space complexity n

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def dfs(node,minel,maxel):
            if node is None:
                return True
            if node.val<=minel or node.val>=maxel:
                return False
            return dfs(node.left,minel,node.val) and dfs(node.right,node.val,maxel)

        return dfs(root,float(-inf),float(inf))