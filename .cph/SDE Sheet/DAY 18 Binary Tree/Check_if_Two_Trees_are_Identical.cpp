
/*Given two binary trees, the task is to find if both of them are identical or not. 


Example 2:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3.
Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: No
Explanation: There are two trees both
having 3 nodes and 2 edges, but both
trees are not identical.

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).


Constraints:
1 <= Number of nodes <= 105
1 <=Data of a node <= 105*/

//using preorder traversal;
//time complexity n;
//auxillary space n;

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)return true;
        if(p==nullptr||q==nullptr)return false;
        if(p->val!=q->val)return false;
        
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        
        if(left&&right)return true;
        return false;
    }