class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod=1e9+7;
        long long even=1;
        long long odd=0;
        long long sum=0;
        long long ans=0;
        for(int x:arr){
            sum+=x;
            if(sum%2==1){
                ans+=even;
                odd++;
            }else{
                ans+=odd;
                even++;
            }
            ans%=mod;
        }
        return ans;
    }
};