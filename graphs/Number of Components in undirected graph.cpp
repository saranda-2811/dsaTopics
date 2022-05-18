/*

problem link : https://leetcode.com/problems/number-of-provinces/

*/



class Solution {
public:
    void bfs(int src,vector<int>&v,vector<vector<int>>&g)
    {
        v[src]=1;
        queue<int>q;
        q.push(src);
        v[src] = 1;
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            for(auto child:g[node])
            {
                if(!v[child])
                {
                    q.push(child);
                    v[child] = 1;
                }
            }         
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        vector<vector<int>>g(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    g[i+1].push_back(j+1);
                    g[j+1].push_back(i+1);
                }

            }
        }
    
        vector<int>v(n+1,0);
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(!v[i])
            {
                count++;
                bfs(i,v,g);
            }
        }
        return count;
        }
};
