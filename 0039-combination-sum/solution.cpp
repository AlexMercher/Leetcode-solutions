class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(const vector<int>& candidates,int target,int index,vector<int>& curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(index==candidates.size()) return;
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target) continue;
            
            curr.push_back(candidates[i]);//choose
            backtrack(candidates,target-candidates[i],i,curr);//explore
            curr.pop_back();//undo
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates,target,0,curr);
        return ans;
    }
};