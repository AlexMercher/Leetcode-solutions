class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool lower = false, upper = false, digit = false;

        for(char c : password) {
            if(islower(c)) lower = true;
            else if(isupper(c)) upper = true;
            else if(isdigit(c)) digit = true;
        }

        int missing = !lower + !upper + !digit;

        int replace = 0;

        // Calculate replacement requirements
        for(int i = 0; i < n; ) {
            int j = i;

            while(j < n && password[j] == password[i])
                j++;

            int len = j - i;

            if(len >= 3)
                replace += len / 3;

            i = j;
        }

        // Too short
        if(n < 6)
            return max(6 - n, missing);

        // Valid length
        if(n <= 20)
            return max(replace, missing);

        // Too long
        int deletions = n - 20;
        int remaining = deletions;

        // len % 3 == 0
        for(int i = 0; i < n && remaining > 0; ) {
            int j = i;

            while(j < n && password[j] == password[i])
                j++;

            int len = j - i;

            if(len >= 3 && len % 3 == 0) {
                replace--;
                remaining--;
            }

            i = j;
        }

        // len % 3 == 1
        for(int i = 0; i < n && remaining > 0; ) {
            int j = i;

            while(j < n && password[j] == password[i])
                j++;

            int len = j - i;

            if(len >= 3 && len % 3 == 1) {
                int d = min(remaining, 2);
                replace -= d / 2;
                remaining -= d;
            }

            i = j;
        }

        // Remaining deletions: every 3 can remove 1 replacement
        replace -= remaining / 3;

        return deletions + max(missing, replace);
    }
};