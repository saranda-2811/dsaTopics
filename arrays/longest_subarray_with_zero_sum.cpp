//  https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// prefix sum
int LongestSubsetWithZeroSum(vector < int > arr) {

    unordered_map<int, int> mp;
    int mx=0, sum=0;
    for(int i=0; i<arr.size(); i++)
    {
        sum+=arr[i];
        if(sum==0)
            mx = i+1;
        else
        {
            if(mp.find(sum)!=mp.end())
                mx = max(mx, i-mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return mx;
}
