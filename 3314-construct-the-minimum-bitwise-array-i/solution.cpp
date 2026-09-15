class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int x:nums){
            if(x==2){
                ans.push_back(-1);
                continue;
            }
            int lowbit=(x+1) & -(x+1);
            ans.push_back(x-lowbit/2);
        }
        return ans;
    }
};