/*Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
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
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

// 1.using recursion
//time complexity n;
// auxillary space n;

 void postorder(vector<int> & ans, TreeNode* root){
        if(root==nullptr)return ;
        postorder(ans,root->left);
        postorder(ans,root->right);
        ans.push_back(root->val);
    }    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(ans,root);
        return ans;
    }

//2.iterative way using two stack
//time complexity n;
//space complexity 2n;

 vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root==nullptr)return ans;
        
        stack<TreeNode*> st1;
        stack<int> st2;
        
        st1.push(root);
            
        while(!st1.empty()){
            TreeNode* temp=st1.top();
            st2.push(temp->val);
            st1.pop();
            if(temp->left)st1.push(temp->left);
            if(temp->right)st1.push(temp->right);
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }

//3. iterative way using single stack
//time complexity 2n;
//spaace complexity n;

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)return ans;
        
        stack<TreeNode*> st;
        TreeNode* curr=root;
        TreeNode* temp;
        while(curr!=nullptr||!st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty()&&temp==st.top()->right){
                        temp=st.top();st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else curr=temp;
            }
        }
        return ans;
    }

