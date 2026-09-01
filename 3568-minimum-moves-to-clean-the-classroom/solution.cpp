class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();

        vector<pair<int,int>> litter;

        int sr=-1,sc=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(classroom[i][j]=='L') litter.push_back({i,j});
            }
        }
        int L=litter.size();
        if(L==0) return 0;

        vector<vector<int>> litterId(m,vector<int>(n,-1));
        for(int i=0;i<L;i++){
            litterId[litter[i].first][litter[i].second]=i;
        }
        int fullmask=(1<<L)-1;
        vector<vector<vector<int>>> best(m,vector<vector<int>>(n,vector<int>(1<<L,-1)));

        struct state{
            int r,c;
            int mask;
            int enery;
            int dist;
        };

        queue<state> q;
        best[sr][sc][0]=energy;//intitalizing the best part where the comparision will start from.
        q.push({sr,sc,0,energy,0});

        int dr[4]={-1,1,0,0};//Rows and colums for traversing in bfs.
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto [r,c,mask,en,dist]=q.front();
            q.pop();

            if(mask==fullmask) return dist;

            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];

                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                if(classroom[nr][nc]=='X') continue;
                if(en==0) continue;

                int new_en=en-1;
                int nmask=mask;
                if(litterId[nr][nc]!=-1) nmask |= (1<<litterId[nr][nc]);

                if(classroom[nr][nc]=='R') new_en=energy;
                if(new_en<=best[nr][nc][mask]) continue;
                best[nr][nc][mask]=new_en;

                q.push({nr,nc,nmask,new_en,dist+1});
            }
        }
        return -1;
    }
};