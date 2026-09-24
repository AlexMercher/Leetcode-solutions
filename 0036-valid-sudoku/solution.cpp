class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxs(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char c=board[i][j];
                int box=(i/3) * 3 + (j/3);
                if(rows[i].count(c)) return false;
                if(cols[j].count(c)) return false;
                if(boxs[box].count(c)) return false;
                rows[i].insert(c);
                cols[j].insert(c);
                boxs[box].insert(c);
            }
        }
        return true;
    }
};