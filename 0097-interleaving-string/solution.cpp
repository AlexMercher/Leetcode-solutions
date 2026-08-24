class Solution {
public:
    string s1,s2,s3;
    int m,n;
    vector<vector<int>> memo;
    
    bool solve(int i,int j){
        if(i==m && j==n) return true;
        if(memo[i][j]!=-1) return memo[i][j];
        int k=i+j;
        bool ans=false;
        if(i<m && s1[i]==s3[k]) ans=solve(i+1,j);
        if(!ans && j<n && s2[j]==s3[k]) ans=solve(i,j+1);

        return memo[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        this->s1=s1;
        this->s2=s2;
        this->s3=s3;

        m=s1.size();
        n=s2.size();

        memo.assign(m+1,vector<int>(n+1,-1));
        return solve(0,0);
    }
};