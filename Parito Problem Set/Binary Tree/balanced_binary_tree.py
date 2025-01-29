# Given a binary tree, determine if it is 
# height-balanced
# .

 

# Example 1:


# Input: root = [3,9,20,null,null,15,7]
# Output: true
# Example 2:


# Input: root = [1,2,2,3,3,null,null,4,4]
# Output: false
# Example 3:

# Input: root = []
# Output: true
 

# Constraints:

# The number of nodes in the tree is in the range [0, 5000].
# -104 <= Node.val <= 104

# 1. using height logic and balanced tree or not check variable
# time complexit O(N)
# auxillary space O(n)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        result=True
        def dfs(node):
            nonlocal result
            if node is None:
                return 0
            
            lh=dfs(node.left)
            rh=dfs(node.right)
            
            if abs(lh-rh)>1:
                nonlocal result
                result=False

            return 1+max(lh,rh)
            
        dfs(root)
        return result