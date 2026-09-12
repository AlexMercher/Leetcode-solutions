class Solution {
public:
    struct state{
        long long score=0;
        vector<int> ids;
    };
    bool better(const state& a, const state &b){
        if(a.score!=b.score) return a.score>b.score;
        return a.ids < b.ids;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<array<long long,4>> a;
        for(int i=0;i<n;i++){
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            return x[0]<y[0];
        });
        vector<long long> starts(n);

        for(int i=0;i<n;i++){
            starts[i]=a[i][0];
        }
        vector<int> next(n);
        for(int i=0;i<n;i++){
            next[i]=lower_bound(starts.begin(),starts.end(),a[i][1]+1)-starts.begin();
        }
        vector<vector<state>> dp(n+1,vector<state>(5));
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=4;k++){
                state skip=dp[i+1][k];
                state take=dp[next[i]][k-1];
                take.score+=a[i][2];

                int idx=(int)a[i][3];
                auto it=lower_bound(take.ids.begin(), take.ids.end(),idx);
                take.ids.insert(it,idx);
                if(better(take,skip)) dp[i][k]=take;
                else dp[i][k]=skip;
            }
        }
        return dp[0][4].ids;
    }
};