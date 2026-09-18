class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int perimeter=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                for(int d=0;d<4;d++){
                    int row=i+dr[d];
                    int col=j+dc[d];
                    if(row<0||row>=m||col<0||col>=n||grid[row][col]==0){
                         perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};