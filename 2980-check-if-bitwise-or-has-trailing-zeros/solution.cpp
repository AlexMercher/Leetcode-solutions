class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count=0;
        for(int x:nums){
            if((x&1)==0) count++;
            if(count>=2) return true;
        }
        return false;
    }
};