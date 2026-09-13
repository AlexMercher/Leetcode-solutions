class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=start^goal;
        return __builtin_popcount(count);
    }
};