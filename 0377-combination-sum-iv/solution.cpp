class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const long long limit=(long long)INT_MAX+1;
        vector<long long> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int x:nums){
                if(i<x) continue;
                if(dp[i-x]>=limit-dp[i]){
                    dp[i]=limit;
                }
                else dp[i]+=dp[i-x];
                if(dp[i]==limit) break;
            }
        }
        return (int)dp[target];
    }
};