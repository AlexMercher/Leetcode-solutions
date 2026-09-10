class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int rem=0;
        vector<bool> arr;
        for(int x:nums){
            rem=(rem*2+x)%5;
            arr.push_back(rem==0);
        }
        return arr;
    }
};