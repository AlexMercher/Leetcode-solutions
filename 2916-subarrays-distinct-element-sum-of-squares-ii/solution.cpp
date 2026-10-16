class Solution {
    static constexpr long long MOD = 1'000'000'007LL;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    int n;
    vector<Node> seg;

    void apply(int node, int l, int r, long long d) {
        long long oldSum = seg[node].sum;
        long long len = r - l + 1LL;
        long long dm = d % MOD;

        // Update sum of squares using the old sum.
        long long addSq = (2LL * dm % MOD) * oldSum % MOD;
        addSq = (addSq + (len % MOD) * dm % MOD * dm % MOD) % MOD;

        seg[node].sq = (seg[node].sq + addSq) % MOD;
        seg[node].sum = (oldSum + (len % MOD) * dm % MOD) % MOD;

        seg[node].lazy += d;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) return;

        int mid = l + (r - l) / 2;
        long long d = seg[node].lazy;

        apply(node * 2, l, mid, d);
        apply(node * 2 + 1, mid + 1, r, d);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        if (ql <= mid) {
            update(node * 2, l, mid, ql, qr);
        }

        if (qr > mid) {
            update(node * 2 + 1, mid + 1, r, ql, qr);
        }

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node{});

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            // x is new for starts after its previous occurrence.
            int left = last[x] + 1;

            // Increase distinct counts for all affected starts.
            update(1, 0, n - 1, left, i);

            last[x] = i;

            // Sum of squares of all subarrays ending at i.
            ans = (ans + seg[1].sq) % MOD;
        }

        return (int)ans;
    }
};