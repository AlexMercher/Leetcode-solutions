class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool seen[101];
        int ans=0;
        for(int x:nums){
            if(x>0 && !seen[x]){
                ans++;
                seen[x]=true;
            }
        }
        return ans;
    }
};