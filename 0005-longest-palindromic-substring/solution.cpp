class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int start=0;
        int maxLen=1;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int l=0;l+len<=n;l++){
                int r=l+len-1;
                if(s[l]==s[r] && (len<=3 || dp[l+1][r-1])){
                    dp[l][r]=true;
                    if(len>maxLen){
                        maxLen=len;
                        start=l;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};