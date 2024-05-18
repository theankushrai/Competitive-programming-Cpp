/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100*/

// 1.using deququ
//time complexity n;
//space complexity n;

vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    deque<Node*> dq;
    dq.push_back(root);
    bool reverse=false;
    while(!dq.empty()){
        int size=dq.size();
        
            if(reverse){
                for(int i =0;i<size;i++){
                    Node* temp=dq.back();dq.pop_back();
                    ans.push_back(temp->data);
                    if(temp->left)dq.push_front(temp->left);
                    if(temp->right)dq.push_front(temp->right);
                    reverse=false;    
                }
            }
            else{
                for(int i=0;i<size;i++){
                    Node* temp=dq.front();dq.pop_front();
                    ans.push_back(temp->data);
                    if(temp->right)dq.push_back(temp->right);
                    if(temp->left)dq.push_back(temp->left);
                    reverse=true;    
                }
                
            }
    }
    return ans;
}
