class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        int ans=0;
        for(auto [x,count]:freq){
            if(freq.find(x+1)!=freq.end()){
                ans=max(ans,count+freq[x+1]);
            }
        }
        return ans;
    }
};