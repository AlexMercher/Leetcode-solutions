class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minsuffix(n);
        minsuffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            minsuffix[i]=min(nums[i],minsuffix[i+1]);
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            int score=maxi-minsuffix[i];
            if(score<=k) return i;
        }
        return -1;
    }
};