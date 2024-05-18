/*Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0
Your Task:
Your task is to complete the function graphColoring() which takes the 2d-array graph[], the number of colours and the number of nodes as inputs and returns true if answer exists otherwise false. 1 is printed if the returned value is true, 0 otherwise. The printing is done by the driver's code.
Note: In the given 2d-array graph[], if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 20
1 ≤ E ≤ (N*(N-1))/2
1 ≤ M ≤ N*/

// 1.backtracking
//time complexity MN;
//space complexity N;


bool is_safe(int node, bool graph[101][101], int color[],int N,int c){
    for(int i =0;i<N;i++){
        if(i!=node&&graph[i][node]==1&&color[i]==c)return false;
    }
    return true;
}

bool solve(int node,bool graph[101][101],int color[], int m, int N ){
    if(node==N)return true;
    
    for(int i=1;i<=m;i++){
        if(is_safe(node,graph,color,N,i)){
            color[node]=i;
            if(solve(node+1,graph,color,m,N))return true;
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N]={0};
    return solve(0, graph, color,m,N);
}
