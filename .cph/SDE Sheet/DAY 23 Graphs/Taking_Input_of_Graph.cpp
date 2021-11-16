#include <bits/stdc++.h> 
#include<vector>
using namespace std;
 
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i =0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[u].push_back(v);in case of undirected;
    }
 return 0;
}