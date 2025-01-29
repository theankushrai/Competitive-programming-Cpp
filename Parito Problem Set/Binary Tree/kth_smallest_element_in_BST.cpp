// smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:


// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// 1. using inorder and giving kth value 
// tiem compleixty n
// space complexity n 
// auxillary space n 

// 2. using inorder and keeping count - instead of count we just subtract k 
// time complexity n ;
// auxillary spac n;


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        result= -1
        def dfs(root):
            nonlocal k,result
            if root is None:
                return
            dfs(root.left)
            k-=1
            if k==0:
                result=root.val
            dfs(root.right)
        dfs(root)
        return result
