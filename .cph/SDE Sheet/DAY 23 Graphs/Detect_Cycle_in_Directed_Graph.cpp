/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105

*/

// 1.using bfs (KAHN'S aLGO)
// time complexity O(N+E);
// Space complexity 2N + O(N+E) for storing graph

bool check_via_bfs(int n, vector<int>& indeg,queue<int>&q,vector<int> adj[]){
        int count=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            count++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        //if count is n that means we have dont have a cycle
        if(count==n)return false;
        return true;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indeg(V,0);
        queue<int> q;
        
        for(int i =0;i<V;i++) for(auto it:adj[i]) indeg[it]++;
        for(int i =0;i<V;i++) if(indeg[i]==0) q.push(i);
        
        return check_via_bfs(V,indeg,q,adj);
    }


//2.using dfs
// time complexity O(n+e);
//space complexity O(n+e) for adj +O(2n) for visited and dfs vis vector + auxillary n;

bool iscycle(int node, vector<bool>& vis,vector<bool>& dfsvis,vector<int> adj[]){
        vis[node]=true;
        dfsvis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(iscycle(it,vis,dfsvis,adj))return true;
            }
            else if(dfsvis[it])return true;
        }
        dfsvis[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> dfsvis(V,false);
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(iscycle(i,vis,dfsvis,adj))return true;
            }
        }
        return false;
    }