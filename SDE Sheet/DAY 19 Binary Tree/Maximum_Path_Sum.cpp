
/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000*/

//1.finding max path sum for all nodes
//time complexity n2;
//space complextiy n;

int pathsum(TreeNode* root){
        if(root==nullptr)return 0;
        int temp= (root->val+max(pathsum(root->left),pathsum(root->right)));
        temp=max(temp,0);
        return temp;
    }
    
    void mps(TreeNode* root,int & maxi){
        if(root==nullptr) return ;
        int left=pathsum(root->left);
        int right=pathsum(root->right);
        maxi=max(maxi,left+right+root->val);
        mps(root->left,maxi);
        mps(root->right,maxi);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        mps(root,maxi);
        return maxi;
    }

// 2.using height of BT logic
// time compelxity n;
// auxillary space n;

int mps(TreeNode* root, int& maxi){
        if(root==nullptr)return 0;
        
        int left=max(0,mps(root->left,maxi));//we dont consider the negative value as it doesnt have any effect on our answer
        int right=max(0,mps(root->right,maxi));
        maxi=max(maxi,left+right+root->val);
        
        return (root->val+max(left,right));
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        mps(root,maxi);
        return maxi;
    }