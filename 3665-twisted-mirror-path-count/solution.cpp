class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        const int MOD=1e9+7;
        vector<int> down(n,0);

        int ans=0;
        for(int i=0;i<m;i++){
            long long left=(i==0?1:0);
            for(int j=0;j<n;j++){
                long long top=down[j];

                if(grid[i][j]==0){ 
                    long long ways=(left+top)%MOD;
                    left=ways;
                    down[j]=ways;
                    if(i==m-1&&j==n-1) ans=ways;
                }else{
                    long long nextRight=top;
                    long long nextDown=left;
                    left=nextRight;
                    down[j]=nextDown;
                }
            }
        }
        return ans;
    }
};