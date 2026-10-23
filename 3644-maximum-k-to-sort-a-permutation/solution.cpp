class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        bool found=false;
        for(int i=0;i<n;i++){
            if(i==nums[i]) continue;
            if(!found){
                k=nums[i];
                found=true;
            }else{
                k= k&nums[i];
            }
        }
        return found ?k : 0;
    }
};