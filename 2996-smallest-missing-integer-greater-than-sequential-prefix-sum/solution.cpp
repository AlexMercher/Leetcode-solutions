class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum=nums[0];
        int n=nums.size();
        int i=1;
        while(i<n&&nums[i]==nums[i-1]+1) sum+=nums[i++];
        unordered_set<int> s(nums.begin(),nums.end());
        while(s.count(sum)) sum++;
        return sum;
    }
};