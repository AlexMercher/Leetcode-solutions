class Solution {
public:
    set<vector<int>> ans;
    vector<int> currant;
    int n;
    void backtrack(const vector<int>& candidates,int index, int target, int sum){
        if(sum==target){
            ans.insert(currant);
            return;
        }
        for(int i=index;i<n;i++){
            if(sum+candidates[i]>target) break;
            if(i > index && candidates[i] == candidates[i-1])
                continue;//Skip the same branching as the elements are same.
            currant.push_back(candidates[i]);
            backtrack(candidates,i+1,target,sum+candidates[i]);
            currant.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n=candidates.size();
        backtrack(candidates,0,target,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};