/*
A bipartite graph is possible if the graph coloring is possible using two colors
that vertices in a set are colored with the same color.
Note that it is possible to color a cycle graph with even cycle using two colors.
For example, see the following graph. 
*/

/*There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.*/

//1.brute force - using backtracking m coloring problme to check if graph can be colored with two colors
//time complexity mn;
//space complexity n;

// 2.using BFS
//time complexity n+e;
//space complexity 2n;

bool check(int node,vector<int>& color,vector<vector<int>> adj){
        queue<int> q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int curr=q.front();q.pop();
            for(auto it:adj[curr]){
                if(color[it]==-1){
                    color[it]=1-color[curr];
                    q.push(it);
                }
                else if(color[curr]==color[it])return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n =adj.size();
        vector<int> color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,color,adj))return false;
            }
        }
        return true;
    }

//3.using DFS
//time complexity n+3;
//space complexity 2n;
//auxillary space n;

    bool check(int node,int prevcolor,vector<int>& color,vector<vector<int>> adj){
        color[node]=prevcolor;
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(!check(it,1-prevcolor,color,adj))return false;
            }
            else if(color[it]==prevcolor)return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n =adj.size();
        vector<int> color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,0,color,adj))return false;
            }
        }
        return true;
    }