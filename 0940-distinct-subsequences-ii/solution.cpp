class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod=1e9+7;
        long long dp=1;
        vector<long long> last(26,0);
        for(char c:s){
            int idx=c-'a';
            long long oldDp=dp;
            dp=(2*dp-last[idx]+mod)%mod;
            last[idx]=oldDp;
        }
        return (dp-1+mod)%mod;
    }
};