class Solution {
public:
    int balancedStringSplit(string s) {
        int countL=0;
        int ans=0;
        int n=s.size();
        for(char c:s){
            if(c=='L'){
                countL++;
            }
            else if(c=='R'){
                countL--;
            }
            if(countL==0) ans++;
        }
        return ans;
    }
};