class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
        int low=0;
        int high=m;

        while(low<=high){
            int partitionX=(low+high)/2;
            int partitionY=(m+n+1)/2-partitionX;

            int maxleftX=(partitionX==0)? INT_MIN:nums1[partitionX-1];
            int minRightX=(partitionX==m)? INT_MAX:nums1[partitionX];
            int maxleftY=(partitionY==0)? INT_MIN:nums2[partitionY-1];
            int minRightY=(partitionY==n)? INT_MAX:nums2[partitionY];

            if(maxleftX<=minRightY && maxleftY<=minRightX){
                if((m+n)%2==1){
                    return max(maxleftX,maxleftY);
                }
                return (max(maxleftX,maxleftY)+min(minRightX,minRightY))/2.0;
            }
            else if(maxleftX > minRightY){
                high=partitionX-1;
            }
            else {
                low=partitionX+1;
            }
        }
        return 0.0;
    }
};