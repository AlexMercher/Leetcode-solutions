class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool nonzero=false;
        for(int x:nums)
        {
            xr^=x;
            if(xr!=0) nonzero=true;
        }
        if(xr!=0) return nums.size();
        if(nonzero) return nums.size()-1;
        return 0;
    }
};