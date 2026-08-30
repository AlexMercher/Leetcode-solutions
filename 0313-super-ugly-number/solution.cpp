class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1) return 1;
        int k=primes.size();
        vector<long long> dp(n);
        vector<int> ptr(k,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long next=LLONG_MAX;

            for(int j=0;j<k;j++){
                next=min(next,dp[ptr[j]]*primes[j]);
            }
            dp[i]=next;
            for(int j=0;j<k;j++){
                if(dp[ptr[j]]*primes[j]==next) ptr[j]++;
            }
        }
        return dp[n-1];
    }
};