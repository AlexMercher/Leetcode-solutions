class Solution {
public:
    void find(vector<int>& nums,int& index,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                index=mid;
                break;
            }else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        if(index==-1)return;
        while(index>0 && nums[index-1]==target) index--;
        return;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans;
        int index=-1;
        find(nums,index,target);
        if(index==-1) return ans;
        for(int i=index;i<n;i++){
            if(nums[i]==target) ans.push_back(i);
            else break;
        }
        return ans;
    }
};