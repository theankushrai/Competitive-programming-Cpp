/*Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
Example 3:

Input: root = [2,1,3], k = 4
Output: true
Example 4:

Input: root = [2,1,3], k = 1
Output: false
Example 5:

Input: root = [2,1,3], k = 3
Output: true
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105*/

// 1.Brute force -store inorder traversal and perform two sum
//time complexity 2n;
//space complexity n;
// auzillary space H.- if we dont use morris traversal;

//2.using bst iterator - we store values from first and last and use two sum property as in arrays.
//time complexity n;
//space complexity 2H;

class Solution {
public:
    
    class BSTIterator{
        bool reverse;
        stack<TreeNode*> st;
        
        public:
        
        void pushall(TreeNode* root){
            while(root){
                st.push(root);
                if(reverse) root=root->right;
                else root=root->left;
            }
        }
        
        BSTIterator(TreeNode* root, bool isreverse){
            reverse=isreverse;
            pushall(root);
        }
        
        int next(){
            TreeNode* temp=st.top();st.pop();
            if(reverse)pushall(temp->left);
            else pushall(temp->right);
            return temp->val;
        }
        
    };
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i =l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            if(i+j<k)i=l.next();
            else j = r.next();
        }
        return false;
    }
};