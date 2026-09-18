class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=nums[0];
        int a=nums[n-1];
        int b=nums[n-2];
        return a+b-c;
    }
};