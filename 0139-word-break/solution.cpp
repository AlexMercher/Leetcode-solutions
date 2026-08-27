class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0]=true; // empty substring is always possible so its true

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(!dp[j]) continue;
                string word=s.substr(j,i-j);
                if(dict.count(word)){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};