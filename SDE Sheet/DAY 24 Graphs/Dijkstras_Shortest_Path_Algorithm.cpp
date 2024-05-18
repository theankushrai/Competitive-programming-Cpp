/*Well simply explained, an algorithm that is used for finding the shortest distance, 
or path, from starting node to target node in a weighted graph is known as Dijkstra’s Algorithm.*/

/*
Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 9 is 9 - 0 = 9.
 

Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes number of vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
0 ≤ S < V
*/

//DIJKSTRA'S ALGORITHM
//Time complexity (n+e)*log n for priority queue;
//time complexity can be generalized to n log n;
//space compolexity 2n; distance array and priority queue;

//for vector<vector<int>> adj[]
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        pq.push({S,0});
        
        while(!pq.empty()){
            auto node=pq.top();pq.pop();
            
            for(auto it:adj[node.first]){
                if(dist[node.first]+it[1]<dist[it[0]]){
                    dist[it[0]]=dist[node.first]+it[1];
                    pq.push({it[0],dist[it[0]]});
                }
            }
        }
        return dist;
    }

//for vector<pair<int,int>> adj[]
vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        pq.push({S,0});
        
        while(!pq.empty()){
            auto node=pq.top();pq.pop();
            int n=node.first;       
            for(auto it:adj[n]){
                int w=it.second;
                if(dist[n]+it.second<dist[it.first]){
                    dist[it.second]=dist[node.first]+it.first;
                    pq.push({it.first,dist[it.first]});
                }
            }
        }
        return dist;
    }