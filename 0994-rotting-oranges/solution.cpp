class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int total_fresh=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                else if(grid[i][j]==1) total_fresh++;
                else q.push({i,j});//Rotten Oranges are there.
            }
        }

        int time=0;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty() && total_fresh!=0){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nr=r+dr[d];
                    int nc=c+dc[d];
                    if(nr<0||nc<0||nr>=m||nc>=n||grid[nr][nc]==0)continue;
                    if(grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        total_fresh--;
                        q.push({nr,nc});
                    } 
                }
            }
        }
        return total_fresh==0?time:-1;
    }
};