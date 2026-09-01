class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int bestLen = 1;
        int bestIdx = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 &&
                   dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > bestLen) {
                bestLen = dp[i];
                bestIdx = i;
            }
        }
        vector<int> answer;
        while(bestIdx != -1) {
            answer.push_back(nums[bestIdx]);
            bestIdx = parent[bestIdx];
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};