class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unsigned int n=num;
        string ans="";
        while(n!=0){
            int dig=n%16;
            if(dig<=9){
                ans.push_back(dig+'0');
            }
            else ans.push_back((dig-10)+'a');
            n=n/16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};