class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=INT_MIN;
        int second=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>first){
                second=first;
                first=nums[i];
            }
            else second=max(second,nums[i]);
        }
        return (first-1)*(second-1);
    }
};