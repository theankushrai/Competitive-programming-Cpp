
# /*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

# Example 1:


# Input: root = [1,2,3,null,5,null,4]
# Output: [1,3,4]
# Example 2:

# Input: root = [1,null,3]
# Output: [1,3]
# Example 3:

# Input: root = []
# Output: []
 

# Constraints:

# The number of nodes in the tree is in the range [0, 100].
# -100 <= Node.val <= 100
# Accepted
# 547,298
# Submissions
# 939,902*/

# 0 level order traversal and rightmost value
# tiem complexity n
# sapce compleixty n ;

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result=[]
        if not root:
            return result

        q=deque()
        q.append(root)
        count=0
        while q:
            size=len(q)
            for _ in range(size):
                el=q.popleft()
                if len(result)==count+1:
                    result[count]=el.val
                else:
                    result.append(el.val)
                
                if el.left:
                    q.append(el.left)
                if el.right:
                    q.append(el.right)
            
            count+=1
        return result

# 1.recursive solution using modified preorder (NRL instead of NLR)
# time complexity n;
# space complexity height of tree;

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result=[]
        def dfs(node,level):
            if not node:
                return
            nonlocal result
            if level==len(result):
                result.append(node.val)
            dfs(node.right,level+1)
            dfs(node.left,level+1)
            
        dfs(root,0)
        return result