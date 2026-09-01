class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int len=2;len<=n;len++){
            for(int lo=1;lo+len-1<=n;lo++){
                int hi=len+lo-1;
                dp[lo][hi]=INT_MAX;
                
                for(int k=lo;k<=hi;k++){
                    int left=dp[lo][k-1];
                    int right=dp[k+1][hi];
                    
                    int cost=k+max(left,right);
                    
                    dp[lo][hi]=min(dp[lo][hi],cost);
                }
            }
        }
        return dp[1][n];
    }
};