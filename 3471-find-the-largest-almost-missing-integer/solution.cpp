class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        vector<int> windowcount(51,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(i>=k){
                freq[nums[i-k]]--;
            }
            if(i>=k-1){
                for(int x=0;x<=50;x++){
                    if(freq[x]>0) windowcount[x]++;
                }
            }
        }
        for(int x=50;x>=0;x--){
            if(windowcount[x]==1) return x;
        }
        return -1;
    }
};