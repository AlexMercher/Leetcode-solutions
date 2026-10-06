class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(const vector<int>& nums,int index){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return ans;
    }
};