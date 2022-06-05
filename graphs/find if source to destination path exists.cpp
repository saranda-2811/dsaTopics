/*

problem link : https://leetcode.com/problems/find-if-path-exists-in-graph/

*/
//Anurag's code
class Solution {
public:
    vector<vector<int>>adj;
    vector<int>v;
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n+1);
        for(auto &i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        v.resize(n);
        fill(v.begin(),v.end(), 0);
        queue<int>q;
        q.push(source);
        v[source]=1;
        while(!q.empty())
        {
            int node=q.front();
            if(node==destination)
                return true;
            q.pop();
            for(auto child:adj[node])
            {
                if(!v[child])
                {
                   if(child==destination)
                       return true;
                   q.push(child);
                   v[child]=1; 
                }
                
            }
        }
        return false;
    }
};




//Saranda's code
class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, int dest) {
        vis[i]=true;
        
        for(auto it: adj[i]) {
            if(vis[dest]==true)
                return;
            if(!vis[it]) {
                dfs(it, adj, vis, dest);
            }
        } 
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(source, adj, vis, destination);
        if(vis[destination]==true)
            return true;
        return false;
    }
};
