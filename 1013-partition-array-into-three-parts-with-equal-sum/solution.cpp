class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int x:arr) sum+=x;
        if(sum%3!=0) return false;

        int target=sum/3;
        int curr=0;
        int part=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            curr+=arr[i];
            if(curr==target){
                part++;
                curr=0;
            }
            if(part==2 && i<n-1) return true;
        }
        return false;
    }
};