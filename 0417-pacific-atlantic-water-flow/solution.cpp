class Solution {
public:
    int m,n;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};

    vector<vector<bool>> pacific,atlantic;

    void dfs(const vector<vector<int>>& heights,vector<vector<bool>>& visited,int r,int c){
        visited[r][c]=true;
        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr<0||nc<0||nr>=m||nc>=n || visited[nr][nc]) continue;

            if(heights[nr][nc]>=heights[r][c]) dfs(heights,visited,nr,nc);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();

        pacific=vector<vector<bool>>(m,vector<bool>(n,false));
        atlantic = vector<vector<bool>>(m, vector<bool>(n, false));

        //From top row to the left col;
        for(int r=0;r<m;r++) dfs(heights,pacific,r,0);//left col;
        for(int c=0;c<n;c++) dfs(heights,pacific,0,c);//Top row;

        for(int c=0;c<n;c++) dfs(heights,atlantic,m-1,c);
        for(int r=0;r<m;r++) dfs(heights,atlantic,r,n-1);

        vector<vector<int>> ans;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(pacific[r][c] && atlantic[r][c])
                    ans.push_back({r,c});
            }
        }
        return ans;
    }
};