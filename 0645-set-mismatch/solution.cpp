class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=1;i<=n;i++){
            x^=i;
        }
        for(int i:nums) x^=i;

        int bit=x&-x;//Rightmost set bit is obtained by this, now we categorize;
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            if(i & bit) a^=i;
            else b^=i;
        }
        for(int num:nums){
            if(num & bit) a^=num;
            else b^=num;
        }
        for(int num:nums){
            if(num==a) return {a,b};
        }
        return {b,a};
    }
};