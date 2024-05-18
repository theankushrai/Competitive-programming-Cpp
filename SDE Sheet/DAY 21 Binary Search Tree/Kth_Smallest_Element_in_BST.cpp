/*Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?*/

//1.store any traerasal and sort  find the kth smallest;
//time complexity nlogn;
//space complexity n;
//auxillary space H;

//2.store inorder traversal and find the kth smallest;
//time complexity 2n;
//space complexity n;
//auxillary space H;

//3.put a counter in inorder traversal
//time complexity n;
//auxillary spac eH;

void inorder(TreeNode* root, int k , int &count,int & ans){
        if(root==nullptr)return ;
        inorder(root->left,k,count,ans);
        count++;
        if(count==k)ans=root->val;
        inorder(root->right,k,count,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int count=0;
        inorder(root,k,count,ans);
        return ans;
    }

//4.using bST iterator to find the given element
//time complexity O(1) avg;
//space complexity H;

//5. put a counter in morris traversal
//time complexity k;
//space O(1);

int KthSmallestElement(Node *root, int k) {
         Node* curr=root;
        int count=0;
        int ans=-1;
        while(curr!=NULL&&count<k){
        
            if(curr->left==NULL){
                count++;
                if(count==k)ans=curr->data;
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right&&prev->right!=curr)prev=prev->right;
                
                if(prev->right==NULL){
                     prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    count++;
                    if(count==k)ans=curr->data;
                    curr=curr->right;
                }
            }
        }
            
        return ans;
    }