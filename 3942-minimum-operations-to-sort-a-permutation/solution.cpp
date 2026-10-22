class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        bool inc=true, dec=true;
        for(int i=1;i<n;i++){
            if(nums[i]!=(nums[i-1]+1)%n) inc=false;
            if(nums[i]!=(nums[i-1]-1+n)%n) dec=false;
        }
        if(inc){
            int d=find(nums.begin(),nums.end(),0)-nums.begin();
            return min(d,n-d+2);//Rotate to bring 0 to the front
        }
        if(dec){
            int k=n-1-nums[0];
            return 1+min(k,n-k);
        }
        return -1;
    }
};