class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        bool seen[501]={};//False is the default value true if the number of occurences is odd.
        if(n%2!=0) return false;
        for(int x:nums){
            seen[x]=!seen[x];
        }
        for(int x=1;x<=500;x++){
            if(seen[x]) return false;
        }
        return true;
    }
};