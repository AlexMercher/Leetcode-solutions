class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber!=0){
            columnNumber--;
            int dig=columnNumber%26;
            ans=char(dig+'A')+ans;
            columnNumber/=26;
        }
        return ans;
    }
};