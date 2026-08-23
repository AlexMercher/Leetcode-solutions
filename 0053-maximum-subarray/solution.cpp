class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,best=nums[0];
        int n=nums.size();
        for(int right=0;right<n;right++){
            sum+=nums[right];
            best=max(sum,best);
            if(sum<0){
                sum=0;
            }
        }
        return best;
    }
};