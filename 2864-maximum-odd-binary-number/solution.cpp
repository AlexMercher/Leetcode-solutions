class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=count(s.begin(),s.end(),'1');
        int n=s.size();
        string ans="";
        for(int i=0;i<ones-1;i++){
            ans+='1';
        }
        for(int i=0;i<n-ones;i++){
            ans+='0';
        }
        return ans+='1';
    }
};