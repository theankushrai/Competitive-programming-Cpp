/*Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices
 such that for every directed edge u v, vertex u comes before v in the ordering.
  Topological Sorting for a graph is not possible if the graph is not a DAG.*/

/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2
*/

// 1.using dfs
// time complexiy n+e;
//space complexity 2n;
//auxillary space n;


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
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}