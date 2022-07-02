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


//GAP METHOD

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int c=0;
        for(int i=m; i<m+n; i++)
            nums1[i] = nums2[c++];
        
        int gap=ceil((float)(m+n)/2), p1, p2;
        while(gap>0)
        {
            p1 = 0;
            p2 = gap;
            while(p2<m+n)
            {
                if(nums1[p1]>nums1[p2])
                    swap(nums1[p1], nums1[p2]);
                p1++;
                p2++;
            }
            if(gap==1)
                gap=0;
            else
                gap = ceil((float)gap/2);
        }
    }
