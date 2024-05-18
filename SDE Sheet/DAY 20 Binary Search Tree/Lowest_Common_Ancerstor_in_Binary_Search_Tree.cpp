/*

*/

// 1.using recursion
//timee complexity n;
//auxillary space height
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return root;
        int val=root->val;
        if(val<p->val&&val<q->val)return lowestCommonAncestor(root->right,p,q);
        if(val>p->val&&val>q->val)return lowestCommonAncestor(root->left,p,q);
        return root;//if either p or q is found or one is one the left and one is on the right
    }
//2.using while loop
//time complexity n;
//space complexity O(1);
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(curr){
            if(curr==NULL)return curr;
            int val=curr->val;
            if(p->val<val&&q->val<val)curr=curr->left;
            else if(p->val>val&&q->val>val)curr=curr->right;
            else return curr;
        }
        return curr;
    }