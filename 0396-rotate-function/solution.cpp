class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        long long sum=0;
        long long F=0;
        for(int i=0;i<n;i++){ // Calculating sum and F(0) in the given question
            sum+=nums[i];
            F+=1LL*i*nums[i];
        }
        long long ans=F;
        for(int k=1;k<n;k++){
            F=F+sum-1LL*n*nums[n-k];
            ans=max(ans,F);
        }
        return ans;
    }
};