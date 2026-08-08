class Solution {
public:
    int findGCD(vector<int>& nums) {
        int big,small;
        big=INT_MIN;
        small=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            big=max(big,nums[i]);
            small=min(small,nums[i]);
        }
        return big%small==0?small:find_gcd(big,small);
    }
    int find_gcd(int big,int small){
        if(small==0) return big;
        return find_gcd(small,big%small);
    }
};