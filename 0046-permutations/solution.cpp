class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> used;
    void backtrack(const vector<int>& nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=1;
            curr.push_back(nums[i]);
            backtrack(nums);
            used[i]=0;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(),0);
        backtrack(nums);
        return ans;
    }
};