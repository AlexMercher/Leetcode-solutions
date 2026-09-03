class Solution {
public:
    int M;
    vector<int> memo;
    bool solve(int mask,int remaining){
        if(remaining<=0) return false;
        if(memo[mask]!=-1) return memo[mask];
        for(int i=1;i<=M;i++){
            if(mask & (1<<(i-1))) continue;
            if(i>=remaining) return true;
            int newmask=mask | (1<<(i-1));
            if(!solve(newmask,remaining-i)) return memo[mask]=true;
        }
        return memo[mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=maxChoosableInteger) return true;

        M=maxChoosableInteger;
        int total=M*(M+1)/2;
        if(total<desiredTotal) return false;
        memo.assign(1<<M,-1);
        return solve(0,desiredTotal);
    }
};