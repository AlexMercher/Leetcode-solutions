class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> cols;
    vector<int> diag;
    vector<int> antiDiag;
    int n;
    void backtrack(int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            int d2=row+col;
            int d1=row-col+n-1;
            if(cols[col]||diag[d1]||antiDiag[d2]) continue;

            board[row][col]='Q';
            cols[col]=1;
            diag[d1]=1;
            antiDiag[d2]=1;
            backtrack(row+1);
            board[row][col]='.';
            cols[col]=0;
            diag[d1]=0;
            antiDiag[d2]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        board=vector<string> (n,string(n,'.'));
        cols=vector<int> (n,0);
        diag=vector<int> (2*n-1,0);
        antiDiag=vector<int> (2*n-1,0);

        backtrack(0);
        return ans;
    }
};