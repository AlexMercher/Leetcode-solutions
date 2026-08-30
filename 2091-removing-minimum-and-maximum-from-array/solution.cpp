class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minIdx=0;
        int maxIdx=0;

        for(int i=1;i<n;i++){
            if(nums[i]<nums[minIdx]) minIdx=i;
            if(nums[i]>nums[maxIdx]) maxIdx=i;
        }

        if(minIdx>maxIdx) swap(minIdx,maxIdx);

        int front=maxIdx+1;
        int back=n-minIdx;
        int bothends=minIdx+1+(n-maxIdx);
        return min({front,back,bothends});
    }
};