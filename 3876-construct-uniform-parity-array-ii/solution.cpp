class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn=*min_element(nums1.begin(),nums1.end());
        bool hasOdd=false;// If even one odd is present then its not possibel to make an all even array as the smallest odd will not be convered to even as nums[i]-nums[j] would become negative or it would remain odd.
        for(int x:nums1){
            if(x%2==1){
                hasOdd=true;
                break;
            }
        }
        if(!hasOdd){
            return true; // If all elements are even then its possible to make an all even array
        }
        return mn%2==1;// If the minimum element is even its not possible to make an all odd array otherwise its possible to make an all odd array, 
    }
};