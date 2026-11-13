class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        vector<int> nextGreater(n,n);
        vector<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.back()]<=nums[i]){
                st.pop_back();
            }
            if(!st.empty()){
                nextGreater[i]=st.back();
            }
            st.push_back(i);
        }
        vector<long long> suffixCost(n+1,0);
        for(int i=n-1;i>=0;i--){
            int nxt=nextGreater[i];
            long long blockCost=1LL*nums[i]*(nxt-i)-(prefix[nxt]-prefix[i]);
            suffixCost[i]=blockCost+suffixCost[nxt];
        }
        int LOG=1;
        while((1<<LOG)<=n){
            LOG++;
        }
        vector<vector<int>> up(LOG,vector<int>(n+1,n));
        for(int i=0;i<n;i++){
            up[0][i]=nextGreater[i];
        }
        for(int j=1;j<LOG;j++){
            for(int i=0;i<=n;i++){
                up[j][i]=up[j-1][up[j-1][i]];
            }
        }
        auto getCost=[&](int l,int r) -> long long{
            int cur=l;
            for(int j=LOG-1;j>=0;j--){
                int nxt=up[j][cur];
                if(nxt<=r) cur=nxt;
            }
            long long total=suffixCost[l]-suffixCost[cur];
            long long partial=1LL*nums[cur]*(r-cur+1)-(prefix[r+1]-prefix[cur]);

            return total+partial; 
        };
        long long ans=0;
        int right=-1;
        for(int left=0;left<n;left++){
            if(right<left) right=left;
            while(right+1<n && getCost(left,right+1)<=k){
                right++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
};