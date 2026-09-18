class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> freq(101,0);
        int sum=0;
        int mx=INT_MIN;
        for(int x:nums){
            mx=max(mx,x);
            if(x>0 && freq[x]==0){
                freq[x]++;
                sum+=x;
            }
        }
        return sum==0?mx:sum;
    }
};