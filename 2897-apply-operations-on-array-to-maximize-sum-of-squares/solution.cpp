class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bitCount(31, 0);

        // Count how many numbers contain each bit
        for (int x : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if ((x >> bit) & 1) {
                    bitCount[bit]++;
                }
            }
        }

        long long ans = 0;

        // Construct the k numbers with the most combined bits
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (bitCount[bit] > 0) {
                    x |= (1LL << bit);
                    bitCount[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};