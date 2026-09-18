class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int m=image.size();
        int n=image[0].size();
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        int type=image[sr][sc];
        if(type==color) return image;
        q.push({sr,sc});
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            image[row][col]=color;
            for(int d=0;d<4;d++){
                int rn=row+dr[d];
                int cn=col+dc[d];
                if(rn<0 || cn<0 || rn>=m||cn>=n) continue;
                if(image[rn][cn]==type){
                    image[rn][cn]=color;
                    q.push({rn,cn});
                }
            }
        }
        return image;
    }
};