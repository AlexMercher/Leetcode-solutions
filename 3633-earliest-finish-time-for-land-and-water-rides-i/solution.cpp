class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        int n=landStartTime.size();
        int m=waterStartTime.size();

        for(int i=0;i<n;i++){
            int landFinish=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                int waterfinish=max(landFinish,waterStartTime[j])+waterDuration[j];
                ans=min(ans,waterfinish);
            }
        }
        for(int i=0;i<m;i++){
            int waterFinish=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                int landFinish=max(waterFinish,landStartTime[j])+landDuration[j];
                ans=min(ans,landFinish);
            }
        }
        return ans;
    }
};