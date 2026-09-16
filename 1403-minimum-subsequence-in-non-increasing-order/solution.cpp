class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        for(int x:nums) sum+=x;
        vector<int> ans;
        int curr=0;
        for(int i=n-1;i>=0;i--){
            if(curr>sum-curr) return ans;
            curr+=nums[i];
            ans.push_back(nums[i]);
        }
        return ans;
    }
};