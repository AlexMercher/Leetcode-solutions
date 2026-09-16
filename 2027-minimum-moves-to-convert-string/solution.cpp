class Solution {
public:
    int minimumMoves(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='X'){
                ans++;
                for(int j=i;j<i+3 && j<n;j++){
                    s[j]='0';
                }
            }
        }
        return ans;
    }
};