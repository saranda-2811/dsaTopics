#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int V, vector<vector<int>>adj, vector<int> &visited)
    {
       
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    
    
bool isCycle(int V,vector<vector<int>>adj)
    {
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
    }

int main() {
    int n, m;
    cout<<"Enter number of vertices :\n";
    cin>>n;
    cout<<"Enter number of edges :\n";
    cin>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout<<endl;
    if(isCycle(n,adj))
        cout<<"cycle is present int the graph";
    else
        cout<<"No cycle present";
    return 0;
}
