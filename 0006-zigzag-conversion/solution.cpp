class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>s.size()||numRows==1) return s;
        vector<string> rows(numRows);
        int row=0;
        int dir=1;
        for(char c:s){
            rows[row]+=c;
            if(row==0) dir=1;
            else if(row==numRows-1) dir=-1;
            row+=dir;
        }
        string ans="";
        for(string row:rows) ans+=row;
        return ans;
    }
};