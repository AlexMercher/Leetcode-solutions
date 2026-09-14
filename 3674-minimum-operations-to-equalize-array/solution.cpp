class Solution {
public:
    bool isequal(const vector<int>& nums){
        int prev=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(prev!=nums[i]) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        if(isequal(nums)) return 0;
        return 1;
    }
};