// https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm
        
         int count=0, ele=0;
        
        for(auto i: nums)
        {
            if(count==0)
                ele=i;
            if(i==ele)
                count+=1;
            else
                count-=1;
        }
        return ele;
    }
