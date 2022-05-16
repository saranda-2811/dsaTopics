//TOPOLIGICAL SORT USING DFS IN DAG

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &s) 
{
    vis[node] = 1;
    
    for(auto it: adj[node]) 
    {
        if(!vis[it])
            dfs(it, adj, vis, s);
    }
    s.push(node);
}

vector<int> topoDfs(vector<vector<int>> adj, int n) 
{
    vector<int> vis(n, 0);
    stack<int> s;
    for(int i=0; i<n; i++) 
    {
        if(!vis[i])
            dfs(i, adj, vis, s);
    }
    
    vector<int> topo;
    while(!s.empty()) 
    {
        topo.push_back(s.top());
        s.pop();
    }
    return topo;
}
int main() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	
	for(int i=0; i<n; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	}
	vector<int> ans = topoDfs(adj, n);
	for(auto it: ans)
	    cout<<it<<" ";
	return 0;
}
