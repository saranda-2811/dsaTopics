/*

problem link : https://leetcode.com/problems/find-if-path-exists-in-graph/

*/

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
