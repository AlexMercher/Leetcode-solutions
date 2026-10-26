class Solution {
public:
    int m,n;
    long long sum=0;
    void dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=m||c>=n) return;
        if(grid[r][c]==0) return;
        sum+=grid[r][c];
        grid[r][c]=0;
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);//Exploring all the different sides
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0) continue;
                dfs(grid,r,c);
                if(sum%k==0) ans++;
                sum=0;
            }
        }
        return ans;
    }
};