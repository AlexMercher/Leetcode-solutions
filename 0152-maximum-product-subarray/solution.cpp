class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int best=nums[0];
        for(int i=1;i<n;i++){
            int newMAX=max({nums[i],nums[i]*maxi,nums[i]*mini});
            int newMINI=min({nums[i],nums[i]*maxi,nums[i]*mini});

            maxi=newMAX;
            mini=newMINI;
            best=max(best,maxi);
        }
        
        return best;
    }
};