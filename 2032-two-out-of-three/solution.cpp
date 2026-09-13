class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        __int128 mask1=0;
        __int128 mask2=0;
        __int128 mask3=0;
        vector<int> ans;
        for(int x:nums1){
            mask1 |=((__int128)1<<x);
        }
        for(int x:nums2){
            mask2 |=((__int128)1<<x);
        }
        for(int x:nums3){
            mask3 |=((__int128)1<<x);
        }
        for(int x=1;x<=100;x++){
            int count=0;
            if(mask1 & ((__int128)1<<x)) count++;
            if(mask2 & ((__int128)1<<x)) count++;
            if(mask3 & ((__int128)1<<x)) count++;
            if(count>=2) ans.push_back(x);
        }
        return ans;
    }
};