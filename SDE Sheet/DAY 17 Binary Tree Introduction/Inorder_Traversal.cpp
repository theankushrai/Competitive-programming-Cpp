/*Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

//1. using recursion
//time complexity n;
//auxilaary space n;

void inorder(TreeNode* root,vector<int> &ans){
        if(root==nullptr)return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }

//2. iterative approach
//time complexity n;
//space complexity n;

vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* temp=root;
        while(temp!=nullptr||!st.empty()){
            
            while(temp!=nullptr){
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            temp=temp->right;
        }
        return ans;
    }

//3. morris traversal using threaded binary tree
//time complexity - amortized(n);
//space complexity O(1);


vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        
        while(curr!=nullptr){
        
            if(curr->left==nullptr){//if left doesn't exist
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{//if left exists
                TreeNode* prev=curr->left;
                while(prev->right&&prev->right!=curr)prev=prev->right;
                
                //if prev right is null - if we reaach last node of left subtree
                if(prev->right==nullptr){
                     prev->right=curr;
                    curr=curr->left;
                }
                //if thread already exists
                else{
                    prev->right=nullptr;
                    //if i have came back from the left subtree push the node;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            
        }
        return ans;
    }