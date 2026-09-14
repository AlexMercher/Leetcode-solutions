class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<bool> ispresent(51,false);
        int ans=0;
        for(int x:nums){
            if(ispresent[x]) ans^=x;
            ispresent[x]=true;
        }
        return ans;
    }
};