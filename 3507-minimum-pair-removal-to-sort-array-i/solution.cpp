class Solution {
public:
    bool issorted(const vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        
        while(!issorted(nums)){
            int idx=0;
            int n=nums.size();
            int minsum=nums[0]+nums[1];
            for(int i=1;i<n-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<minsum){
                    minsum=sum;
                    idx=i;
                }
            }
            nums[idx]=nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            count++;
        }
        return count;
    }
};