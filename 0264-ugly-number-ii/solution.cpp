class Solution {
public:
    int solve(int n){
        vector<long long> dp(n);
        dp[0]=1;
        int p2=0;
        int p3=0;
        int p5=0;

        for(int i=1;i<n;i++){
            long long next2=dp[p2]*2;
            long long next3=dp[p3]*3;
            long long next5=dp[p5]*5;

            dp[i]=min({next2,next3,next5});

            if(dp[i]==next2) p2++;
            if(dp[i]==next3) p3++;
            if(dp[i]==next5) p5++;
        }
        return dp[n-1];
    }
    int nthUglyNumber(int n) {
        return solve(n);
    }
};