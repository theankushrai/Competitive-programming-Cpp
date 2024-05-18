/*Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   

Output: 1
Explanation: 1->2->3->4->1 is a cycle.
Example 2:

Input: 

Output: 0
Explanation: No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i][0] and edges[i][1] represent an edge.

 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


 

Constraints:
1 ≤ V, E ≤ 105*/

// 1.using bfs
// time complexity O(N+E);
// Space complexity 2N + O(N+E) for storing graph

bool bfscycle(int i , vector<bool>& vis, vector<int> adj[]){
        queue<pair<int,int>> q;//first is curr node, second is parent node;
        vis[i]=true;
        q.push({i,-1});
        while(!q.empty()){
            pair<int,int> node=q.front();q.pop();
            for(auto it:adj[node.first]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it,node.first});
                }
                else if(it!=node.second)return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(bfscycle(i,vis,adj))return true;
            }
        }
        return false;
    }

//2.using dfs
// time complexity O(n+e);
//space complexity O(n+e) for adj +O(n) for visited+auxillary n;

bool dfscycle(int node, int parent, vector<bool>& vis, vector<int> adj[]){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=true;
                if(dfscycle(it,node,vis,adj))return true;
            }
            else if(it!=parent)return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(dfscycle(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }