class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        const int INF=1e9;
        int ans=INF;
        int left=0;
        int sum=0;
        vector<int> best(n,INF);
        for(int right=0;right<n;right++){
            sum+=arr[right];
            while(sum>target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int len=right-left+1;
                if(left>0 && best[left-1]!=INF){
                    ans=min(ans,len+best[left-1]);
                }
                best[right]=min(best[right],len);
            }
            if(right>0)
                best[right]=min(best[right],best[right-1]);
        }
    return ans==INF?-1:ans;
    }
};