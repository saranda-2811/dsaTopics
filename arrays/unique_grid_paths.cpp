//  https://leetcode.com/problems/unique-paths/

//Recursive soln

int uniquePaths(int m, int n) {
        return countPath(0, 0, m, n);
    }
    int countPath(int i, int j, int m, int n) {
        if(i==m-1 || j==n-1)
            return 1;
        
        if(i>=m || j>=n)
            return 1;
        
        return countPath(i+1, j, m, n)+countPath(i, j+1, m, n);
    }


// DP soln
// TC = O(N*M), SC = O(N*M)

int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                dp[i].push_back(-1);
        }
        return countPath(0, 0, m, n, dp);
    }
    int countPath(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i==m-1 || j==n-1)
            return 1;
        
        if(i>=m || j>=n)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        else
        return dp[i][j]=countPath(i+1, j, m, n, dp)+countPath(i, j+1, m, n, dp);
    }


// Combinatorics soln

int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res=1;
        
        for(int i=1; i<=r; i++)
        {
            res = res*(N-r+i)/i;
        }
        return (int)res;
    }
