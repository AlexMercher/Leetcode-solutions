class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
        unordered_set<int> seen;
        vector<int> ans;
        for(int x:nums){
            if(seen.find(x)==seen.end()){
                seen.insert(x);
                k--;
                ans.push_back(x);
            }
            if(k==0) break;
        }
        return ans;
    }
};