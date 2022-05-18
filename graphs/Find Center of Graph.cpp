/*
problem link:  https://leetcode.com/problems/find-center-of-star-graph/
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int>store(n+1,0);
        for(auto &i:edges)
        {
            store[i[0]]++;
            store[i[1]]++;
        }
        
        for(int i=1;i<store.size();i++)
        {
            if(store[i]==n-1)
                return i;
        }
        return -1;
    }
};
