class Solution {
public:
    long build(int k){
        long x=0;
        for(int i=1;i<=k;i++){
            x|=((long)1<<i);
        }
        return x;
    }
    int minOperations(vector<int>& nums, int k) {
        long mask=0;
        long final=build(k);
        int n=nums.size();
        int count=0;
        for(int i=n-1;i>=0;i--){
            count++;
            if(nums[i]>k) continue;
            mask=mask | ((long)1<<nums[i]);
            if(final==mask) return count;
        }
        return -1;
    }
};