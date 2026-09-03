class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        if(total%2==1) return false;
        int target=total/2;

        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int x:nums){
            for(int j=target;j>=x;j--){
                dp[j]=dp[j]||dp[j-x];
            }
        }
        return dp[target];
    }
};