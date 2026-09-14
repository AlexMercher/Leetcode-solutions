class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int best=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool valid=max(nums[i],nums[j]) <=2*min(nums[i],nums[j]);
                if(valid){
                    best=max(best,nums[i]^nums[j]);
                }
            }
        }
        return best;
    }
};