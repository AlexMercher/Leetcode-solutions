class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<bitset<1024>> dp(n);

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                bitset<1024> top=dp[c];
                bitset<1024> left;

                if(c>0) left=dp[c-1];
                dp[c].reset();
                if(r==0 && c==0){
                    dp[c].set(grid[r][c]);
                    continue;
                }
                int v=grid[r][c];
                for(int x=0;x<1024;x++){
                    if(top[x] || left[x]){
                        dp[c].set(x^v);
                    }
                }
            }
        }
        for(int i=0;i<1024;i++){
            if(dp[n-1][i]) return i;
        }
        return -1;
    }
};