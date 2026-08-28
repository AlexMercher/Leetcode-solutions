class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        // Check whether a palindrome is possible.
        int odd = 0;
        char middle = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) {
                odd++;
                middle = 'a' + i;
            }
        }

        if(odd > n % 2)
            return "";

        // Build the first half.
        string half = "";

        for(int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);
        }

        int h = half.size();

        string targetHalf = target.substr(0, h);

        vector<int> cnt(26, 0);

        for(char c : half)
            cnt[c - 'a']++;

        string ansHalf = "";

        // Try to match target's first half.
        for(int i = 0; i < h; i++) {

            int cur = targetHalf[i] - 'a';

            if(cnt[cur] > 0) {
                ansHalf.push_back(targetHalf[i]);
                cnt[cur]--;
            }
            else {
                // Cannot continue matching.
                // Try to increase at this position.
                for(int c = cur + 1; c < 26; c++) {

                    if(cnt[c] == 0)
                        continue;

                    string newHalf = ansHalf;
                    newHalf.push_back('a' + c);

                    cnt[c]--;

                    for(int x = 0; x < 26; x++) {
                        newHalf += string(cnt[x], 'a' + x);
                    }

                    string result = newHalf;

                    if(n % 2)
                        result += middle;

                    string right = newHalf;
                    reverse(right.begin(), right.end());

                    result += right;

                    return result;
                }

                break;
            }
        }

        // We matched the complete half.
        // Build the complete palindrome and compare it with target.
        if(ansHalf.size() == h) {

            string result = ansHalf;

            if(n % 2)
                result += middle;

            string right = ansHalf;
            reverse(right.begin(), right.end());

            result += right;

            if(result > target)
                return result;
        }

        // The palindrome constructed from the matching half
        // was not strictly greater, so backtrack.
        for(int i = (int)ansHalf.size() - 1; i >= 0; i--) {

            int cur = targetHalf[i] - 'a';

            // Restore the character used at this position.
            cnt[cur]++;

            // Find the smallest character greater than target[i].
            for(int c = cur + 1; c < 26; c++) {

                if(cnt[c] == 0)
                    continue;

                string newHalf = targetHalf.substr(0, i);
                newHalf.push_back('a' + c);

                cnt[c]--;

                // Smallest possible suffix.
                for(int x = 0; x < 26; x++) {
                    newHalf += string(cnt[x], 'a' + x);
                }

                string result = newHalf;

                if(n % 2)
                    result += middle;

                string right = newHalf;
                reverse(right.begin(), right.end());

                result += right;

                return result;
            }
        }

        return "";
    }
};