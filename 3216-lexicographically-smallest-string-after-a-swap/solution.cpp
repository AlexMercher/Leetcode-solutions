class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
        for(int i=1;i<s.size();i++){
            int a=s[i-1]-'0';
            int b=s[i]-'0';
            if(((a&1)==(b&1))&& a>b){
                s[i-1]=char(b+'0');
                s[i]=char(a+'0');
                break;
            }
        }
        return s;
    }
};