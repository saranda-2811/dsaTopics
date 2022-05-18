#include<bits/stdc++.h>
using namespace std;

/*shortest path in undirected graph 
Input:
9 11
0 1
0 3
1 3
1 2
2 6
3 4
4 5
5 6
6 7
7 8
6 8
output: 
0 1 2 1 2 3 3 4 2147483647
*/
void shortestBfs(int n, int src, vector<vector<int>> adj)
{
    queue<int> q;
    q.push(src);
    
    vector<int> dis(n, INT_MAX);
    dis[src]=0;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
            if(dis[node]+1 < dis[it])
            {
                dis[it] = dis[node]+1;
                q.push(it);
            }
        }
    }
  
    for(int i=0; i<n; i++)
        cout<<dis[i]<<" ";
}

int main() 
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    
    for(int i=0; i<n; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    shortestBfs(n, 0, adj);
    return 0;
}
