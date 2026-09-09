class Solution {
public:
    long long countCommas(long long n) {
        if(n<999) return 0;
        long long ans=0;
        for(long long x=1000;x<=n;x*=1000){
            ans+=n-x+1;
        }
        return ans;
    }
};