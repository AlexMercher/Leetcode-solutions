class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();
        vector<int> sa(n);
        vector<int> rank = nums;
        vector<int> temp(n);

        iota(sa.begin(), sa.end(), 0);
        for (int len = 1; len < n; len *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b]) {
                    return rank[a] < rank[b];
                }
                int ra = (a + len < n) ? rank[a + len] : -1;
                int rb = (b + len < n) ? rank[b + len] : -1;
                return ra < rb;
            });
            temp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];
                pair<int, int> prev = {
                    rank[a],
                    (a + len < n) ? rank[a + len] : -1
                };
                pair<int, int> curr = {
                    rank[b],
                    (b + len < n) ? rank[b + len] : -1
                };

                temp[b] = temp[a] + (prev != curr);
            }
            rank.swap(temp);

            // All suffixes have distinct ranks
            if (rank[sa[n - 1]] == n - 1) {
                break;
            }
        }
        //KASAI ALGORITHM 
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }
        vector<int> lcp(n, 0);
        int h = 0;
        for (int i = 0; i < n; i++) {
            int r = pos[i];
            if (r == n - 1) {
                h = 0;
                continue;
            }
            int j = sa[r + 1];
            while (i + h < n &&
                   j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }
            lcp[r] = h;
            if (h > 0) {
                h--;
            }
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int r = pos[i];
            int maxLCP = 0;
            if (r > 0) {
                maxLCP = max(maxLCP, lcp[r - 1]);
            }

            if (r < n - 1) {
                maxLCP = max(maxLCP, lcp[r]);
            }

            int required = maxLCP + 1;
            if (required <= n - i) {
                ans = min(ans, required);
            }
        }
        return ans;
    }
};