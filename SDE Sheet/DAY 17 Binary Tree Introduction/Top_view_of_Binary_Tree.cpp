/*Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105*/

// 1.using bfs level order traversal
//time complexity n;
//space complexity 2n;

vector<int> topView(Node *root)
    {
        queue<pair<int,Node*>> q;
        map<int,int> m;
        q.push({0,root});
        
        while(!q.empty()){
            int size=q.size();
            for(int i =0;i<size;i++){
                pair<int,Node*> p=q.front();q.pop();
                if(m.find(p.first)==m.end())m[p.first]=p.second->data;
                if(p.second->left)q.push({p.first-1,p.second->left});
                if(p.second->right)q.push({p.first+1,p.second->right});
            }
        }
        
        vector<int> ans;
        for(auto it:m)ans.push_back(it.second);
        return ans;
    }