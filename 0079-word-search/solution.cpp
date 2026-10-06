class Solution {
public:
    vector<vector<int>> visited;
    int m;int n;
    bool dfs(const vector<vector<char>>& board,string& word,int row,int col,int index){
        if(index==word.size()-1) return true;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,1,-1};
        for(int d=0;d<4;d++){
            int nr=row+dr[d];
            int nc=col+dc[d];
            if(nr<0 ||nc<0 || nr>=m || nc>=n) continue;
            if(visited[nr][nc]) continue;
            if(board[nr][nc]!=word[index+1]) continue;
            visited[nr][nc]=1;
            if(dfs(board,word,nr,nc,index+1)) return true;
            visited[nr][nc]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()>board.size()*board[0].size())return false;
        m=board.size();
        n=board[0].size();
        visited=vector<vector<int>>(m,vector<int>(n,0));
        
        unordered_map<char,int> boardFreq;
        unordered_map<char,int> wordFreq;
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                boardFreq[board[i][j]]++;
            }
        }
        for(char c : word){
            wordFreq[c]++;
        }
        for(auto& [key,value] : wordFreq){
            if(boardFreq[key]<value){
                return false;
            }
        }
        if(boardFreq[word[0]]>boardFreq[word.back()]){
            reverse(word.begin(),word.end());
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!=word[0]) continue;
                visited[i][j]=1;
                if(dfs(board,word,i,j,0)) return true;
                visited[i][j]=0;
            }
        }
        return false;
    }
};