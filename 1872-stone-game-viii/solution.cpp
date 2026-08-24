class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+stones[i];
        }
        long long best=prefix[n];
        for(int i=n-1;i>=2;i--){
            long long dp=best;
            best=max(best,prefix[i]-dp);
        }
        return best;
    }
};