// Given a Weighted Directed Acyclic Graph and a source vertex in the graph, find the shortest paths from given source to all other vertices
//to find shortest path we must first find the topological sort and then calculate the distance;

// 1.using dfs to find topological sort and then finding shortest path
// time complexity 2*(n+e)
//space complexity 3n
//auxlllary space n;

	void sort(int node, vector<bool> & vis,stack<int> &st, vector<int> adj[]){
	    vis[node]=true;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            sort(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<bool> vis(V,false);
	    
	    for(int i =0;i<V;i++){
	        if(!vis[i]){
	            sort(i,vis,st,adj);
	        }
	    }
        return st;
	}

void shortestpath(int V,int src, vector<int> adj[],vector<int> weight){
    stack<int> st =topologicalsort(V,adj);
    vector<int> dist=(V,INT_MAX);
    dist[src]=0;
    
    while(!st.empty()){
        int node=st.top();st.pop();
        for(auto it:adj[node]){
            if(dist[node]+weight[it]<dist[it]){
                dist[it]=dist[node]+weight[it];
            }
        }
    }
}

// 2.using Kahns algo to find topological sort and then finding shortest path
// time complexity 2*(n+e)
//space complexity 3n

// 1.using dfs to find topological sort and then finding shortest path
// time complexity 2*(n+e)
//space complexity 3n
//auxlllary space n;

void shortestpath(int V,int src, vector<int> adj[],vector<int> weight){
    stack<int> st =topologicalsort(V,adj);
    vector<int> dist=(V,INT_MAX);
    dist[src]=0;
    
    while(!st.empty()){
        int node=st.top();st.pop();
        for(auto it:adj[node]){
            if(dist[node]+weight[it]<dist[it]){
                dist[it]=dist[node]+weight[it];
            }
        }
    }
}