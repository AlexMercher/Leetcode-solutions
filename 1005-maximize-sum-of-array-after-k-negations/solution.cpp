class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n && k>0;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
                k--;
            } 
        }
        int sum=0;
        int mini=INT_MAX;
        for(int x:nums){
            sum+=x;
            mini=min(mini,abs(x));
        }
        if(k&1) sum-=2*mini;
        return sum;
    }
};