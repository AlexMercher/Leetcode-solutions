class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minsuffix(n);
        minsuffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            minsuffix[i]=min(nums[i],minsuffix[i+1]);
        }
        int prefixmax=nums[0];
        for(int i=0;i<n;i++){
            prefixmax=max(prefixmax,nums[i]);
            int instability=prefixmax-minsuffix[i];
            if(instability<=k) return i;
        }
        return -1;
    }
};