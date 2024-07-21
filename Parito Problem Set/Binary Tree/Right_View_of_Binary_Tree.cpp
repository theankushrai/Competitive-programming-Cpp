
/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
Accepted
547,298
Submissions
939,902*/

//0 level order traversal and rightmost value
//tiem complexity n
//sapce compleixty n ;


//1.recursive solution using modified preorder (NRL instead of NLR)
//time complexity n;
//space complexity height of tree;

void rightview(TreeNode* root, vector<int> & ans, int level){
        if(!root)return;
        if(level==ans.size()) ans.push_back(root->val);
        rightview(root->right,ans,level+1);
        rightview(root->left,ans,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightview(root,ans,0);
        return ans;
    }