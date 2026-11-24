class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int ans=2;
        for(int right=0;right<n;right++){
            for(int i=0;i<right;i++){
                if(gcd(nums[i],nums[right])!=1){
                    left=max(left,i+1);
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};