class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        if (n==3)return nums[n-1]*nums[n-2]*nums[n-3];
        int first,second,third;
        int min1,min2;
        first=second=third=INT_MIN;
        min1=min2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>first){
                third=second;
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second){
                third=second;
                second=nums[i];
            }
            else third=max(third,nums[i]);
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else min2=min(nums[i],min2);
        }
        int ans1=first*second*third;
        int ans2=first*min1*min2;
        return (ans1>ans2)?ans1:ans2;
    }
};