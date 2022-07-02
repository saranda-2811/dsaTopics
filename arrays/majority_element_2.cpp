//  https://leetcode.com/problems/majority-element-ii/

vector<int> majorityElement(vector<int>& nums) {
        //extended boyer moore's algorithm
        
        int n1=-1, n2=-1, c1=0, c2=0, i, n=nums.size();
        
        for(i=0; i<n; i++)
        {
            if(nums[i]==n1)   //the order of if conditions matter, first check if nums[i]==n1 and vice versa or not
                c1++;
            else if(nums[i]==n2)
                c2++;
            else if(c1==0)
            {
                n1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                n2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1=0;
        c2=0;
        for(i=0; i<n; i++) 
        {
            if(nums[i]==n1)
                c1++;
            else if(nums[i]==n2)
                c2++;
        }
        if(c1>n/3)
            ans.push_back(n1);
        if(c2>n/3)
            ans.push_back(n2);
        
        return ans;
    }
