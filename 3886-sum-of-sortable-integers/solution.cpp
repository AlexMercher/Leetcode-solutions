class Solution {
public:
    bool valid(const vector<int>& nums,const vector<int>& sorted, int k){
        int n=nums.size();
        for(int l=0;l<n;l+=k){
            int start=l;
            int drops=0;

            for(int t=0;t<k;t++){
                int curr=l+t;
                int next=l+(t+1)%k;
                if(nums[curr]>nums[next]){
                    drops++;
                    start=next;
                }
            }
            if(drops>1) return false;
            for(int t=0;t<k;t++){
                int idx=l+(start-l+t)%k;
                if(nums[idx]!=sorted[l+t]) return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        int ans=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            if(valid(nums,sorted,k)){
                ans+=k;
            }
        }
        return ans;
    }
};