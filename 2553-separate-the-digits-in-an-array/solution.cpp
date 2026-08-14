class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int x:nums){
            int dup=x;
            if(x<9){
                ans.push_back(x);
                continue;
            }
            vector<int> temp;
            while(dup!=0){
                temp.push_back(dup%10);
                dup=dup/10;
            }
            reverse(temp.begin(),temp.end());
            for(int digit:temp) ans.push_back(digit);
        }
        return ans;
    }
};