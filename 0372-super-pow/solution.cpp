class Solution {
public:
    static constexpr int MOD=1337;
    int power(int a,int pow){
        if(pow==0) return 1;
        int half=power(a,pow/2);
        long long ans=(half*half)%MOD;

        if(pow%2) ans=ans*a%MOD;
        return ans;
    }
    int solve(int a, vector<int>& b, int i) {
        if (i < 0) return 1;

        int prev = solve(a, b, i - 1);

        return (long long)power(prev, 10) * power(a, b[i]) % MOD;
    }
    int superPow(int a, vector<int>& b) {
        if(a==0) return 0;
        if(a==1) return 1;
        return solve(a%MOD,b,b.size()-1);
    }
};