class Solution {
public:
    vector<vector<int>> memo;
    vector<int> prefix;
    int solve(int l,int r){
        if(l==r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int ans=0;
        for(int k=l;k<r;k++){
            int left=prefix[k+1]-prefix[l];
            int right=prefix[r+1]-prefix[k+1];
            if(left<right){
                ans=max(ans,left+solve(l,k));
            }
            else if(right<left){
                ans=max(ans,right+solve(k+1,r));
            }
            else{
                ans=max(ans,max(left+solve(l,k), right+solve(k+1,r)));
            }
        }
        return memo[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        prefix.resize(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+stoneValue[i];
        }
        memo.assign(n,vector<int>(n,-1));
        return solve(0,n-1);
    }
};