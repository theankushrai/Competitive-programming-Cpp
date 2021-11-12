/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000*/

// 1.serialize and deseialize using stringstream
//time complexity n;
//space complexity n;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==nullptr)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();q.pop();
            if(temp==nullptr)ans+="#,";
            else {
                ans+=(to_string(temp->val)+",");
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())return nullptr;
        
        //using string stream
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        TreeNode* root= new TreeNode(stoi(str));
        
        //initializing queue;
        queue<TreeNode*> q ;
        q.push(root);
        
        while(!q.empty()){
        
            TreeNode* curr=q.front();q.pop();
            
            //left node;
            getline(s,str,',');
            if(str=="#") curr->left=nullptr;
            else{
                curr->left=new TreeNode(stoi(str));
                q.push(curr->left);
            }
            //right node
            getline(s,str,',');
            if(str=="#")curr->right=nullptr;
            else{
                curr->right=new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};
