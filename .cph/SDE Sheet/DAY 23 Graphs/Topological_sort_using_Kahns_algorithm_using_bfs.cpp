//KAHN'S ALGORITHM

/*Solution: In this article we will see another way to find the linear ordering of vertices in a directed acyclic graph (DAG). The approach is based on the below fact:
A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0. 
Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which means that all paths will be of finite length. Now let S be the longest path from u(source) to v(destination). Since S is the longest path there can be no incoming edge to u and no outgoing edge from v, if this situation had occurred then S would not have been the longest path 
=> indegree(u) = 0 and outdegree(v) = 0
Algorithm: Steps involved in finding the topological ordering of a DAG: 
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then. 
 

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighbouring nodes.
If in-degree of a neighbouring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty.
Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph*/

//Topological sort

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

// 1.using bfs kahns algorithm
// time complexity n+e+n;
//space complexity n+n for queue and indegree array

void bfs(vector<int>& indeg, queue<int>& q, vector<int>& ans,vector<int> adj[]){
	    while(!q.empty()){
	        int node=q.front();q.pop();
	        ans.push_back(node);
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(indeg[it]==0)q.push(it);
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indeg(V,0);
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i =0;i<V;i++) for(auto it:adj[i]) indeg[it]++;//storing indegree
	    for(int i =0;i<V;i++) if(indeg[i]==0) q.push(i);
	    
	    bfs(indeg,q,ans,adj);
	    return ans;
	}