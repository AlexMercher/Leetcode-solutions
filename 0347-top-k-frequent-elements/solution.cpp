class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x:nums) freq[x]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto [num,count]:freq){
            bucket[count].push_back(num);
        }
        vector<int> ans;
        for(int i=nums.size();i>0 && ans.size()<k;i--){
            for(int x:bucket[i]){
                ans.push_back(x);
                if(ans.size()==k) break;
            }
            
        }
    return ans;
    }
};