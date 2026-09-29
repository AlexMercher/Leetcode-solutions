class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if((m+n-1)%2) return false;
        if(grid[0][0]==')'||grid[m-1][n-1]=='(') return false;
        
        vector<vector<vector<char>>> visited(m,vector<vector<char>>(n,vector<char>(m+n,0)));
        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        while(!q.empty()){
            auto [r,c,bal]=q.front();
            q.pop();

            if(r==m-1&&c==n-1){
                if(bal==0) return true;
                continue;
            }

            if(r+1<m){
                int newBal=bal+(grid[r+1][c]=='('?1:-1);
                if(newBal>=0 && !visited[r+1][c][newBal]){
                    visited[r+1][c][newBal]=1;
                    q.push({r+1,c,newBal});
                }
            }
            if(c+1<n){
                int newBal=bal+(grid[r][c+1]=='('?1:-1);
                if(newBal>=0&&!visited[r][c+1][newBal]){
                    visited[r][c+1][newBal]=1;
                    q.push({r,c+1,newBal});
                }
            }
        }
        return false;
    }
};