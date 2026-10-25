class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=m||c>=n) return;
        if(grid[r][c]==1) return;

        grid[r][c]=1;
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);//Exploring all the different sides
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        for(int r=0;r<m;r++){
            dfs(grid,r,0);//Checking the first column for any 0
            dfs(grid,r,n-1);//Checking the last column for any 0
        }

        for(int c=0;c<n;c++){
            dfs(grid,0,c);//Checking the first row for any 0
            dfs(grid,m-1,c);//Checking the last row for any 0
        }

        int ans=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) continue;
                ans++;
                dfs(grid,r,c);
            }
        }
        return ans;
    }
};