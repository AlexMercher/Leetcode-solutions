class Solution {
public:
    int m,n;
    int count;
    void dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0|| r>=m|| c>=n || grid[r][c]==0) return;
        count++;
        grid[r][c]=0;
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int best=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count=0;
                    dfs(grid,i,j);
                    best=max(count,best);
                }
            }
        }
        return best;
    }
};