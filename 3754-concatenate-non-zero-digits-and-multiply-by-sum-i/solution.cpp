class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0;

        int power = 1;
        int temp = n;

        while(temp >= 10) {
            temp /= 10;
            power *= 10;
        }

        while(power > 0) {
            int digit = n / power;
            n %= power;
            power /= 10;

            if(digit != 0) {
                x = x * 10 + digit;
                sum += digit;
            }
        }

        return x * sum;
    }
};