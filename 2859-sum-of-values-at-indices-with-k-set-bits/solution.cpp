class Solution {
public:
    int bitcount(int x){
        return __builtin_popcount(x);
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(bitcount(i)==k) sum+=nums[i];
        }
        return sum;
    }
};