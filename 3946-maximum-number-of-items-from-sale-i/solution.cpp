class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> bonus(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0){
                    bonus[i]++;
                }
            }
        }
        const int NEG=-1e9;
        vector<int> dp(budget+1,NEG);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int p=items[i][1];
            int b=bonus[i];
            vector<int> ndp=dp;

            for(int r=0;r<p&&r<=budget;r++){
                int best=NEG;
                for(int q=0;r+q*p<=budget;q++){
                    int c=r+q*p;
                    if(q>0){
                        int t=q-1;
                        int prev=r+t*p;
                        if(dp[prev]!=NEG){
                            best=max(best,dp[prev]-t);
                        }
                    }
                    if(q>0&&best!=NEG){
                        ndp[c]=max(ndp[c],best+b+q);
                    }
                }
            }
            dp.swap(ndp);
        }
        return *max_element(dp.begin(),dp.end());
    }
};