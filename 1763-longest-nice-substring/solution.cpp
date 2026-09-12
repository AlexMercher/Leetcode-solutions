class Solution {
public:
    string solve(string& s,int l,int r){
        if(l>r) return "";
        int lower=0;
        int upper=0;
        for(int i=l;i<=r;i++){
            if(s[i]>='a' && s[i]<='z') lower |=(1<<(s[i]-'a'));
            else upper |=(1<<(s[i]-'A'));
        }
        for(int i=l;i<=r;i++){
            int bit;
            if(s[i]>='a'&&s[i]<='z') bit=1<<(s[i]-'a');
            else bit=1<<(s[i]-'A');

            if((lower & bit)==0 || (upper & bit)==0){
                string left=solve(s,l,i-1);
                string right=solve(s,i+1,r);

                if(left.size()>=right.size()) return left;
                return right;
            }
        }
        return s.substr(l,r-l+1);
    }
    string longestNiceSubstring(string s) {
        return solve(s,0,s.size()-1);
    }
};