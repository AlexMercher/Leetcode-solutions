class Solution {
public:
    int minOperations(vector<int>& nums) {
        int val=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int adj=nums[i-1]-nums[i]+1;
                val+=adj;
                nums[i]+=adj;
            }
        }
        return val;
    }
};