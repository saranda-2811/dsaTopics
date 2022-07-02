void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.size()==1 && nums1[0]==0 && nums2.size()==1 && nums2[0]!=0)
        {
            nums1[0] = nums2[0];
            return;
        }
        if(nums1.size()==1 || nums2.size()==0)
            return;
        int a, first, i, j;
        for(i=0; i<m; i++)
        {
            //swap
            if(nums1[i]>nums2[0])
            {
                a=nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = a;
            }
            
            //sort nums2
            //insertion sort
            first = nums2[0];
            for(j=1; j<n && nums2[j]<first; j++)
                nums2[j-1] = nums2[j];
            
            nums2[j-1] = first; 
        }
        int c=0;
        for(int i=m; i<m+n; i++)
        {
            nums1[i] = nums2[c++];
        }
    }
