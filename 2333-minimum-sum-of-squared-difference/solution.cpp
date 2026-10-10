class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> diff(n);
        int mx=0;
        long long total=0;

        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            mx=max(mx,diff[i]);
            total+=diff[i];
        }

        vector<long long> freq(mx+1);
        for(int d:diff) freq[d]++;

        long long k=1LL*k1+k2;
        for(int x=mx; x>0 && k>0;x--){
            long long take=min(k,freq[x]);
            freq[x]-=take;
            freq[x-1]+=take;
            k-=take;
        }

        long long ans=0;
        for(int x=1;x<=mx;x++) ans+=freq[x]*x*x;
        return ans;
    }
};