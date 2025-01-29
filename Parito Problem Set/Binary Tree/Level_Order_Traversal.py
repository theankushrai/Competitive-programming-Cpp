# /*Given a binary tree, find its level order traversal.
# Level order traversal of a tree is breadth-first traversal for the tree.


# Example 1:

# Input:
#     1
#   /   \ 
#  3     2
# Output:1 3 2
# Example 2:

# Input:
#         10
#      /      \
#     20       30
#   /   \
#  40   60
# Output:10 20 30 40 60 N N

# Your Task:
# You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


# Expected Time Complexity: O(N)
# Expected Auxiliary Space: O(N)


# Constraints:
# 1 ≤ Number of nodes ≤ 105
# 1 ≤ Data of a node ≤ 105*/


# //1.using breadth first search using queue
# //time complexity n;
# //space complexity n;
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result=[]
        if not root:
            return result
        q=deque()
        q.append(root)

        while q:
            size=len(q)
            level=[]
            for _ in range(size):
                el=q.popleft()
                level.append(el.val)
                if el.left:
                    q.append(el.left)                
                if el.right:
                    q.append(el.right)

            result.append(level)
        
        return result

#2 using dfs
#time complexity n
#space complexity n auxillaary space

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result=[]
        def dfs(node,count):
            if not node:
                return count
            nonlocal result
            if count<len(result):
                result[count].append(node.val)
            else:
                result.append([node.val])
            
            dfs(node.left,count+1)
            dfs(node.right,count+1)
        dfs(root,0)
        return result
            
