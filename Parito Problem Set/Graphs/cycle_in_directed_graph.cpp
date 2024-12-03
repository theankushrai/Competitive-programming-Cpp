// Detect Cycle in a Directed Graph
// Difficulty: MediumAccuracy: 27.88%Submissions: 422K+Points: 4
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

// Example 1:

// Input:



// Output: 1
// Explanation: 3 -> 3 is a cycle
// Example 2:
// Input:


// Output: 0
// Explanation: no cycle in the graph
// Constraints:
// 1 ≤ V, E ≤ 105

//using dfs 
//time complexity O(V+E)
//space complexity 3xO(V+E)

    
    bool dfs(int node , vector<vector<int>> &adj,vector<bool> &visited, vector<bool> &path_visited){
        if(path_visited[node]) return true;
        if(visited[node])return false;
        
        visited[node]=true;
        path_visited[node]=true;
        
        for(auto it : adj[node]){
            if(dfs(it,adj,visited,path_visited)) return true;
        }
        path_visited[node]=false;
        return false;
    }
    
        // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        
        vector<bool> visited(V,0);
        vector<bool> path_visited(V,0);
        
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path_visited))return true;
            }
            
        }
        return false;
    }
        