class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);
        for(int x:nums){
            vector<long long> curr(k,0);
            int val=x%k;
            curr[val]++;
            for(int r=0;r<k;r++){
                if(dp[r]==0) continue;

                int nr=(long long)r*val % k;
                curr[nr]+=dp[r];
            }
            for(int r=0;r<k;r++){
                ans[r]+=curr[r];
            }
            dp=move(curr);
        }
        return ans;
    }
};