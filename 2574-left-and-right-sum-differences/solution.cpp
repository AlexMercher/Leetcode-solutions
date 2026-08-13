class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left_sum=leftsum(nums);
        vector<int> right_sum=rightsum(nums);
        int n=left_sum.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(left_sum[i]-right_sum[i]);
        }
        return ans;
    }
    vector<int> leftsum(const vector<int> &nums){
        int first=0;
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=first;
            first=first+nums[i];
        }
        return ans;
    }
    vector<int> rightsum(const vector<int> &nums){
        int last=0;
        int n=nums.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=last;
            last=last+nums[i];
        }
        return ans;
    }
};