class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastIndex;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(lastIndex.find(nums[i])!=lastIndex.end()){
                if(i-lastIndex[nums[i]]<= k) return true;
            }
            lastIndex[nums[i]]=i;
        }
        return false;
    }
};