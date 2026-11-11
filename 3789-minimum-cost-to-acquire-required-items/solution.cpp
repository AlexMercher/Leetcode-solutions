class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mn=min(need1,need2);
        long long mx=max(need1,need2);

        long long direct=1LL*cost1*need1+1LL*cost2*need2;
        long long both=1LL*costBoth*mx;
        long long mixed=1LL*mn*costBoth+1LL*(need1-mn)*cost1+1LL*(need2-mn)*cost2;
        
        long long ans=min({direct,both,mixed});
        return ans;
    }
};