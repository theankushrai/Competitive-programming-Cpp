/*Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)


Constraints:
1 <= N <= 1000
1 <= K <= N
*/


//1.store any traerasal and sort  find the kth largest and traverse reverse inorder;
//time complexity nlogn;
//space complexity n;
//auxillary space H;

//2.store inorder traversal and find the kth largest and traverse reverse inorder;
//time complexity 2n;
//space complexity n;
//auxillary space H;

//3.put a counter in inorder traversal and traverse reverse inorder
//time complexity n;
//auxillary spac eH;
   void inorder(Node* root, int k,int& count,int& ans){
        if(root==NULL)return;
        inorder(root->right,k,count,ans);
        count++;
        if(count==k)ans=root->data;
        inorder(root->left,k,count,ans);
    }
    
    int kthLargest(Node *root, int k)
    {
        int count=0;
        int ans=-1;
        inorder(root,k,count,ans);
        return ans;
        
    }

//4. use BST iterator to find given element
// space complexity H;
//time complexity O(1)average;

//4. put a counter in morris traversal and traverse right node left
//time complexity k;
//space O(1);

int kthLargest(Node *root, int k)
    {
        int count=0;
        Node* curr=root;
        while(curr){
            if(curr->right==NULL){
                count++;
                if(count==k)return curr->data;
                curr=curr->left;
            }
            else{
                Node* prev=curr->right;
                while(prev->left&&prev->left!=curr)prev=prev->left;
                if(prev->left==NULL){
                    prev->left=curr;
                    curr=curr->right;
                }
                else{
                    prev->left=NULL;
                    count++;
                    if(count==k)return curr->data;
                    curr=curr->left;
                }
            }
        }
    }