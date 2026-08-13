class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int minimum=INT_MAX;
        for(int x:nums){
            int sum=sumofdigits(x);
            minimum=min(minimum,sum);
        }
        return minimum;
    }
    int sumofdigits(int x){
        if(x<=9) return x;
        int sum=0;
        while(x!=0){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
};