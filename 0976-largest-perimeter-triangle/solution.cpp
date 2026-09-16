class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-1;i>=2;i--){
            int sum=nums[i]+nums[i-1]+nums[i-2];
            if(nums[i-2]+nums[i-1]>nums[i]){
                return sum;
            }
        }
        return 0;
    }
};