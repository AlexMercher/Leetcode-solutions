class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            unordered_set<int> seen;
            for(int j=i+1;j<n;j++){
                int need=-nums[i]-nums[j];
                if(seen.find(need)!=seen.end()){
                    ans.insert({nums[i],need,nums[j]});
                }
                seen.insert(nums[j]);
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};