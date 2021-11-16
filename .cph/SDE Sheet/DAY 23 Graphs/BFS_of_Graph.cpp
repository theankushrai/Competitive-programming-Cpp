/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


Example 1:

Input:

Output: 0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3.After this 2 to 4, thus bfs will be
0 1 2 3 4.
Example 2:

Input:

Output: 0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2 3 4. 

Your task:
You don’t need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 104
*/

// 1.using queue
// time complexity O(N+E);
// Space complexity 2N + O(N+E) for storing graph

void bfs(int node,vector<bool>& vis,vector<int>& ans,vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int curr=q.front();q.pop();
            ans.push_back(curr);
            for(auto it:adj[curr]){
                if(!vis[it]){//if not visited
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
    }

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<int> ans;
        COMMENT IS FOR DISCONNECTED COMPONENTS
        for(int i =0;i<V;i++){
            if(!vis[i]){
                bfs(i,vis,ans,adj);
            }
        }
        return ans;
    }