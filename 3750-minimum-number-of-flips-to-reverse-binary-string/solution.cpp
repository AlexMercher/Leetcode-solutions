class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        while(n>0){
            s+=char('0'+(n&1));
            n>>=1;
        }
        int ans=0;
        int l=0;int r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) ans+=2;

            l++;
            r--;
        }
        return ans;
    }
};