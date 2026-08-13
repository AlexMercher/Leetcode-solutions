class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int sum=0;
        for(int x:gain){
            sum+=x;
            if(sum>ans) ans=sum;
        }
        return ans;
    }
};