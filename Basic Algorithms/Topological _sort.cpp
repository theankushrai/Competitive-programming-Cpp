// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

// Examples:

// Input: adj = [[], [0], [0], [0]] 

// Output: 1
// Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]
// Input: adj = [[], [3], [3], [], [0,1], [0,2]]

// Output: 1
// Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]
// Constraints:
// 2  ≤  V  ≤  103
// 1  ≤  E  ≤  (V * (V - 1)) / 2



    
    #Function to return list containing vertices in Topological order.
    def topologicalSort(self,adj):
        # Code here
        N=len(adj)
        in_deg=[0]*N
        for node in adj:
            for nei in node:
                in_deg[nei]+=1
        
        
        q=deque()
        
        for i,val in enumerate(in_deg):
            if val==0:
                q.append(i)
                
        result = []
        while q:
            node = q. popleft()
            result.append(node)
                
            for nei in adj[node]:
                in_deg[nei]-=1
                if in_deg[nei] == 0:
                    q.append(nei)
        
        return result


