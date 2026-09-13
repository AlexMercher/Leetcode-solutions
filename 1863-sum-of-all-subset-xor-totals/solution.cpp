class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        for(int x:nums) ans|=x;
        return ans*(1<<(nums.size()-1));
    }
};