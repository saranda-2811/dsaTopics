//  https://leetcode.com/problems/search-a-2d-matrix/

// O(N) TC

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target==matrix[0][0])
            return true;
        
        int row=matrix.size(), col=matrix[0].size(), pos=-1;
        if(row==1)
        {
            for(int i=0; i<col; i++)
                if(target==matrix[0][i])
                    return true;
        }
        
        for(int i=1; i<row; i++)
        {
            if(target>=matrix[i-1][0] && target<matrix[i][0])
                pos=i-1;
            if(target>matrix[i-1][0] && target<=matrix[i-1][col-1])
                pos=i-1;
            if(target==matrix[i][0])
                pos=i;
        }
        
        if(pos!=-1)
        {
            for(int i=0; i<col; i++)
            {
                if(target==matrix[pos][i])
                    return true;
            }   
        }
        else
        {
            for(int i=0; i<col; i++)
            {
                if(target==matrix[row-1][i])
                    return true;
            }
        }
        return false;
    }


//BINARY SEARCH

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target==matrix[0][0])
            return true;
        
        int row=matrix.size(), col=matrix[0].size();
        int low=0, hi=(row*col)-1;
        
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            if(target<matrix[mid/col][mid%col])
                hi=mid-1;
            if(target==matrix[mid/col][mid%col])
                return true;
            if(target>matrix[mid/col][mid%col])
                low=mid+1;
        }
        return false;
    }
