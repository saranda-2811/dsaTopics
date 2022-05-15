//Cycle detection in UNDIRECTED graph using DFS
#include<bits/stdc++.h>
using namespace std;

bool cycleDfs(int node, vector<int> adj[], int vis[], int dfsvis[])
{
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(cycleDfs(it, adj, vis, dfsvis)) return true;
        }
        else if(dfsvis[it])
            return true;
    }
    dfsvis[node]=0;  //difference between directed and undirected
    return false;
}

bool isCyclic(int n, vector<int> adj[]) {
    //vector<int> vis(n, 0);
    //vector<int> dfsvis(n, 0);
    int vis[n], dfsvis[n];
    memset(vis, 0, sizeof vis);
    memset(dfsvis, 0, sizeof dfsvis);
    
    for(int i=0; i<n; i++) 
    {
        if(!vis[i]) {
            if(cycleDfs(i, adj, vis, dfsvis))
                return true;
        }
    }
    return false;
}

int main()
{
   int n, m; 
   cin>>n>>m;
   vector<int> adj[n];
   for(int i=0; i<m; i++) {
       int u, v;
       cin>>u>>v;
       adj[u].push_back(v);
   }
   if(isCyclic(n, adj))
   cout<<"yes";
    else
    cout<<"no";
   return 0;
}
