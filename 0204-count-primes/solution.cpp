class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        // 2 is the only even prime.
        isPrime[0] = isPrime[1] = false;
        // Only odd numbers need to be checked.
        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (isPrime[i]) {
                // Mark only odd multiples.
                for (long long j = 1LL * i * i; j < n; j += 2LL * i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 1; // prime number 2
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                count++;
        }
        return count;
    }
};