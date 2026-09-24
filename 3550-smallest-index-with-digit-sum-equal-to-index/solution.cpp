class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n!=0){
            int dig=n%10;
            sum+=dig;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==digitsum(nums[i])) return i;
        }
        return -1;
    }
};