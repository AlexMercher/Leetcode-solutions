class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums)ans^=x;
        int a=0;
        int b=0;
        unsigned int mask=(unsigned int)ans&-(unsigned int)ans;
        for(int x:nums){
            if(mask&(unsigned int)x) a^=x;
            else b^=x;
        }
        return {a,b};
    }
};