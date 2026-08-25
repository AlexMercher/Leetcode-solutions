class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int x:nums){
            if(x%k==0) s.insert(x);
        }
        for(int i=1;;i++){
            if(!s.count(i*k)) return i*k;
        }
    }
};