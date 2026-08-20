class Solution {
public:
    int n,m;
    string s,p;
    vector<vector<int>> dp;
    bool solve(int i,int j){
        if(j==m) return i==n;
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool match = (i<n && (s[i]==p[j] || p[j]=='.'));
        bool star= (j+1<m && p[j+1]=='*');

        if (star){
            bool skip = solve(i,j+2); //consuming no character
            bool take= match && solve(i+1,j); // consuming one character.
            return dp[i][j]=skip || take;
        }
        if (match) return dp[i][j]=solve(i+1,j+1);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        this->s=s;
        this->p=p;
        n=s.size();
        m=p.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0);
    }
};