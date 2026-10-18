class Solution {
public:
    static constexpr long long MOD=1'000'000'007LL;
    vector<vector<long long>> comb;

    long long countways(vector<int>& nums){
        int n=nums.size();
        if(n<=2) return 1;
        vector<int> left,right;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long ways=comb[n-1][left.size()];
        ways=ways*countways(left)%MOD;
        ways=ways*countways(right)%MOD;
        return ways;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        comb.assign(n+1,vector<long long>(n+1,0));

        for(int i=0;i<=n;i++){
            comb[i][0]=comb[i][i]=1;
            for(int j=1;j<i;j++){
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
            }
        }
        return (countways(nums)-1+MOD)%MOD;
    }
};