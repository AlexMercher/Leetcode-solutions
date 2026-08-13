class Solution {
public:
    int N;

    vector<int> lc, rc;
    vector<int> pref, suff, best, len;

    void pull(int p) {
        int L = p << 1;
        int R = L | 1;

        lc[p] = lc[L];
        rc[p] = rc[R];
        len[p] = len[L] + len[R];

        pref[p] = pref[L];
        suff[p] = suff[R];
        best[p] = max(best[L], best[R]);

        if (rc[L] == lc[R]) {
            best[p] = max(best[p], suff[L] + pref[R]);

            if (pref[L] == len[L])
                pref[p] = len[L] + pref[R];

            if (suff[R] == len[R])
                suff[p] = len[R] + suff[L];
        }
    }

    void update(int pos, char c) {
        int p = N + pos;

        lc[p] = rc[p] = c;
        pref[p] = suff[p] = best[p] = len[p] = 1;

        for (p >>= 1; p; p >>= 1)
            pull(p);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        N = 1;
        while (N < n)
            N <<= 1;

        int size = 2 * N;

        lc.resize(size);
        rc.resize(size);
        pref.assign(size, 0);
        suff.assign(size, 0);
        best.assign(size, 0);
        len.assign(size, 0);

        // Build leaves
        for (int i = 0; i < n; i++) {
            int p = N + i;

            lc[p] = rc[p] = s[i];
            pref[p] = suff[p] = best[p] = len[p] = 1;
        }

        // Build internal nodes
        for (int p = N - 1; p > 0; p--)
            pull(p);

        vector<int> ans;
        ans.reserve(queryIndices.size());

        for (int i = 0; i < queryIndices.size(); i++) {
            update(queryIndices[i], queryCharacters[i]);
            ans.push_back(best[1]);
        }

        return ans;
    }
};