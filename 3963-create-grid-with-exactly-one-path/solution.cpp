class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> answer(m,string(n,'#'));
        for(int i=0;i<m;i++){
            answer[i][n-1]='.';
        }
        for(int c=0;c<n;c++){
            answer[0][c]='.';
        }
        return answer;
    }
};