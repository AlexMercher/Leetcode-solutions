class Solution {
public:
    int minMoves(vector<int>& nums) {
        int target=*min_element(nums.begin(),nums.end());
        long long moves=0;
        for(int x:nums) moves+=(x-target);
        return (int)moves;
    }
};