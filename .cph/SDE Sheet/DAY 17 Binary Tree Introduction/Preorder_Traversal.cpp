/*Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [1,2]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

// 1.using recursion
// time complexity n;
// auxillary space n;

void preorder(vector<int> & ans,TreeNode* root){
        if(root==nullptr)return;
        ans.push_back(root->val);
        preorder(ans,root->left);
        preorder(ans,root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(ans,root);
        return ans;
    }

//2. iterative approach using recursion
//time complexity n;
// space complexity n;- stack;

vector <int> preorder(Node* root)
{
  vector<int> ans;
  stack<Node*> st;
  st.push(root);
  
  while(!st.empty()){
      Node* temp=st.top();
      ans.push_back(temp->data);
      st.pop();
      if(temp->right)st.push(temp->right);
      if(temp->left)st.push(temp->left);
  }
  return ans;
}

//3. morris traversal using threaded binary trees
//time complexity amortized (n);
//space compplexity O(1);
vector<int> preorderTraversal(TreeNode* root) {
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
                     ans.push_back(curr->val);
                    curr=curr->left;
                }
                //if thread already exists
                else{
                    prev->right=nullptr;
                    //if i have came back from the left subtree push the node;
                   
                    curr=curr->right;
                }
            }
            
        }
        return ans;
    }
