class Solution {
public:
    int getCost(string& s,int l,int r){
        int len=r-l+1;
        int best=INT_MAX;
        for(int d=1;d<len;d++){
            if(len%d!=0) continue;
            int changes=0;
            for(int offset=0;offset<d;offset++){
                int left=l+offset;
                int right=l+offset+((len-1-offset)/d)*d;
                while(left<right){
                    if(s[left]!=s[right]){
                        changes++;
                    }
                    left+=d;
                    right-=d;
                }
            }
            best=min(best,changes);
        }
        return best;
    }
    int minimumChanges(string s, int k) {
        int n=s.size();
        const int INF=INT_MAX/2;
        vector<vector<int>> cost(n,vector<int>(n,INF));

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cost[i][j]=getCost(s,i,j);
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(k+1,INF));

        dp[0][0]=0;
        for(int j=1;j<=k;j++){
            for(int i=2*j;i<=n;i++){
                for(int p=2*(j-1);p<=i-2;p++){
                    dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p][i-1]);
                }
            }
        }
        return dp[n][k];
    }
};