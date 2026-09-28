class Solution {
public:
    bool canfinish(const vector<int>& piles,int h,int k){
        long long hour=0;
        for(int pile:piles){
            hour+=(pile+k-1)/k;
        
            if(hour>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());

        while(left<=right){
            int mid=left+(right-left)/2;
            if(canfinish(piles,h,mid)){
                right=mid-1;
            }else left=mid+1;
        }
        return left;
    }
};