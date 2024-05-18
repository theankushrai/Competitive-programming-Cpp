/*Given an unweighted graph, a source, and a destination, we need to find the shortest path from source to destination in the graph in the most optimal way.
 

unweighted graph
unweighted graph of 8 vertices 

Input: source vertex = 0 and destination vertex is = 7.
Output: Shortest path length is:2
        Path is::
        0 3 7

Input: source vertex is = 2 and destination vertex is = 6.
Output: Shortest path length is:5
        Path is::
        2 1 0 3 4 6*/

// 1.using BFS
//time complexity N+E;
//space complexity 2n;

void shortestPathUsingBfs(int src,queue<int> & q,vector<int>& distance,vector<int> adj[]){
    q.push(src);
    distance[src]=0;
    while(!q.empty()){
        int node=q.front();q.pop();
        
        for(auto it:adj[node]){
            if(distance[node]+1<distance[it]){
                distance[it]=distance[node]+1;
                q.push(it);
            }
        }
    }
}

vector<int> shortestpath(int V,int src, vector<int> adj[]){

    queue<int> q;
    vector<int> distance(V,INT_MAX);
    shortestPathUsingBfs(src,q,disance,adj);
    return distance;
}

//2.using dfs
//time complexity n+e;
//auxillary space n;
//space complexity n;

void shortestPathUsingDfs(int src, vector<int>& distance, vector<int> adj[]){
    for(auto it:adj[src]) {
        if(distance[src]+1<distance[it]){
            distance[it]=distance[src]+1;
            shortestPathUsingDfs(it,distance,adj);
        }
    }
}

vector<int> shortestpath(int V,int src, vector<int> adj[]){

    queue<int> q;
    vector<int> distance(V,INT_MAX);
    distance[src]=0;
    shortestPathUsingDfs(src,distance,adj);
    return distance;
}
