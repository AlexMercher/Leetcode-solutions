# 3420. Count Non-Decreasing Subarrays After K Operations

---

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/

---

## Language

C++

---

## Explanation

# Count Non-Decreasing Subarrays After K Operations

## 1. Understanding the Problem

We are given an integer array `nums` and an integer `k`.

We can increment any element by 1, and we need to count how many contiguous subarrays can be converted into a non-decreasing array using at most `k` operations.

A non-decreasing array satisfies:

`nums[i] >= nums[i - 1]`

For example:

```cpp
nums = [3, 1, 2]
```

To make this array non-decreasing, we must convert it into:

```text
[3, 3, 3]
```

The required operations are:

- 3 requires 0 increments.
- 1 requires 2 increments.
- 2 requires 1 increment.

Total operations = 3.

## 2. Important Mathematical Observation

To make a subarray non-decreasing using only increments, every element must be at least as large as the maximum element preceding it within that subarray.

For a subarray `[l, r]`, the required value at every position is:

`target[i] = max(nums[l], nums[l+1], ..., nums[i])`

Therefore, the minimum number of operations is:

`cost(l, r) = sum(target[i] - nums[i])`

For example:

```text
Original:         [1, 4, 2, 3, 6]
Required values:  [1, 4, 4, 4, 6]
Operations:       [0, 0, 2, 1, 0]

Total cost = 3
```

We need to calculate this cost efficiently for different subarrays.

## 3. Sliding Window Observation

Two important properties help us use Sliding Window:

1. Extending a subarray to the right cannot decrease its required operations.
2. Removing the leftmost element cannot increase its required operations.

Therefore, we can maintain two pointers:

- `left`: Starting index of the current subarray.
- `right`: Farthest valid ending index.

For every left position, once we find the maximum valid right position, the number of valid subarrays starting there is:

`right - left + 1`

We add this value to our answer.

However, calculating the cost of every subarray by traversing its elements would be too expensive.

We need to optimize the cost calculation.

## 4. Monotonic Stack: Finding the Next Greater Element

Consider:

```text
nums = [1, 4, 2, 3, 6]
```

Starting from index 1, the running maximum remains 4 until we encounter 6.

The first position to the right containing a value strictly greater than the current element is called the Next Greater Element.

Define:

`nextGreater[i]`

as the first index to the right of `i` where:

`nums[index] > nums[i]`

If no such element exists, we use `n`.

We calculate this using a monotonic stack.

```cpp
vector<int> nextGreater(n, n);
vector<int> st;

for (int i = n - 1; i >= 0; i--) {

    while (!st.empty() && nums[st.back()] <= nums[i]) {
        st.pop_back();
    }

    if (!st.empty()) {
        nextGreater[i] = st.back();
    }

    st.push_back(i);
}
```

We scan from right to left.

We remove elements smaller than or equal to the current element because they cannot be the next strictly greater element.

Each index is pushed and popped at most once.

Time complexity: O(n).

## 5. Prefix Sum: Calculating Block Costs

The running maximum remains constant from index `i` until `nextGreater[i] - 1`.

For example:

```text
nums = [1, 4, 2, 3, 6]

Starting at index 1:

[4, 2, 3]

Required values:

[4, 4, 4]
```

Instead of traversing this block, we calculate its cost using Prefix Sum.

First, construct the prefix sum array:

```cpp
vector<long long> prefix(n + 1, 0);

for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
```

The sum of elements from index `i` to `nxt - 1` is:

`prefix[nxt] - prefix[i]`

Since every element in this block must become `nums[i]`:

`blockCost = nums[i] * (nxt - i) - (prefix[nxt] - prefix[i])`

Implementation:

```cpp
long long blockCost =
    1LL * nums[i] * (nxt - i)
    - (prefix[nxt] - prefix[i]);
```

## 6. Precompute Suffix Costs

Define:

`suffixCost[i]`

as the total cost of converting the entire suffix starting at index `i` into a non-decreasing array.

The suffix can be divided into blocks of constant running maximum.

Therefore:

`suffixCost[i] = blockCost[i] + suffixCost[nextGreater[i]]`

We calculate it from right to left:

```cpp
vector<long long> suffixCost(n + 1, 0);

for (int i = n - 1; i >= 0; i--) {

    int nxt = nextGreater[i];

    long long blockCost =
        1LL * nums[i] * (nxt - i)
        - (prefix[nxt] - prefix[i]);

    suffixCost[i] = blockCost + suffixCost[nxt];
}
```

The base case is:

`suffixCost[n] = 0`

This means that an empty suffix requires zero operations.

## 7. Binary Lifting: Skipping Multiple Blocks

We now have a chain of next-greater positions.

Following this chain one position at a time could take O(n).

We optimize it using Binary Lifting.

Define:

`up[j][i]`

as the position reached after following `2^j` next-greater links starting from index `i`.

The transitions are:

```cpp
up[0][i] = nextGreater[i];

up[j][i] = up[j-1][up[j-1][i]];
```

Construct the binary lifting table:

```cpp
int LOG = 1;

while ((1 << LOG) <= n) {
    LOG++;
}

vector<vector<int>> up(LOG, vector<int>(n + 1, n));

for (int i = 0; i < n; i++) {
    up[0][i] = nextGreater[i];
}

for (int j = 1; j < LOG; j++) {

    for (int i = 0; i <= n; i++) {

        up[j][i] = up[j-1][up[j-1][i]];
    }
}
```

Now we can jump over multiple complete blocks efficiently.

## 8. Calculate the Cost of Any Subarray [l, r]

This is where all our preprocessing comes together.

We want to calculate:

`getCost(l, r)`

First, initialize:

```cpp
int cur = l;
```

We jump through complete blocks using binary lifting without crossing `r`.

```cpp
for (int j = LOG - 1; j >= 0; j--) {

    int nxt = up[j][cur];

    if (nxt <= r) {
        cur = nxt;
    }
}
```

After these jumps, `cur` represents the beginning of the final partially covered block.

### Calculate the complete blocks' cost

We already know the suffix costs:

`suffixCost[l] - suffixCost[cur]`

This gives the total cost of all complete blocks before `cur`.

### Calculate the final partial block

Every element from `cur` to `r` must become `nums[cur]`.

Therefore:

`partialCost = nums[cur] * (r - cur + 1) - (prefix[r + 1] - prefix[cur])`

Combining both:

`getCost(l, r) = completeBlocksCost + partialCost`

Complete implementation:

```cpp
auto getCost = [&](int l, int r) -> long long {

    int cur = l;

    // Skip complete blocks using binary lifting
    for (int j = LOG - 1; j >= 0; j--) {

        int nxt = up[j][cur];

        if (nxt <= r) {
            cur = nxt;
        }
    }

    // Cost of all complete blocks
    long long total =
        suffixCost[l] - suffixCost[cur];

    // Cost of the final partial block
    long long partial =
        1LL * nums[cur] * (r - cur + 1)
        - (prefix[r + 1] - prefix[cur]);

    return total + partial;
};
```

Each cost query takes O(log n).

**Important:** The initial value must be `cur = l`, not `cur = 1`, because every query starts from a potentially different left boundary.

## 9. Sliding Window: Count Valid Subarrays

Now we have an efficient `getCost(l, r)` function.

We maintain:

```cpp
long long ans = 0;
int right = -1;
```

For every left position:

1. Extend `right` while the cost is at most `k`.
2. Once the maximum valid right position is found, all shorter subarrays starting at `left` are also valid.
3. Add `right - left + 1` to the answer.
4. Move the left pointer forward.

```cpp
for (int left = 0; left < n; left++) {

    if (right < left) {
        right = left;
    }

    while (right + 1 < n &&
           getCost(left, right + 1) <= k) {

        right++;
    }

    ans += right - left + 1;
}
```

The right pointer never moves backwards because removing elements from the left cannot increase the required operations.

Therefore, the total number of cost queries is O(n).

Each query costs O(log n), giving O(n log n) for this stage.

## 10. Complete Optimized C++ Implementation

```cpp
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Prefix Sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Next Greater Element
        vector<int> nextGreater(n, n);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) {
                nextGreater[i] = st.back();
            }

            st.push_back(i);
        }

        // Step 3: Suffix Costs
        vector<long long> suffixCost(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            int nxt = nextGreater[i];

            long long blockCost =
                1LL * nums[i] * (nxt - i)
                - (prefix[nxt] - prefix[i]);

            suffixCost[i] = blockCost + suffixCost[nxt];
        }

        // Step 4: Binary Lifting
        int LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(
            LOG, vector<int>(n + 1, n)
        );

        for (int i = 0; i < n; i++) {
            up[0][i] = nextGreater[i];
        }

        for (int j = 1; j < LOG; j++) {

            for (int i = 0; i <= n; i++) {

                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        // Step 5: Calculate cost of any subarray [l, r]
        auto getCost = [&](int l, int r) -> long long {

            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {

                int nxt = up[j][cur];

                if (nxt <= r) {
                    cur = nxt;
                }
            }

            long long total =
                suffixCost[l] - suffixCost[cur];

            long long partial =
                1LL * nums[cur] * (r - cur + 1)
                - (prefix[r + 1] - prefix[cur]);

            return total + partial;
        };

        // Step 6: Sliding Window
        long long ans = 0;
        int right = -1;

        for (int left = 0; left < n; left++) {

            if (right < left) {
                right = left;
            }

            while (right + 1 < n &&
                   getCost(left, right + 1) <= k) {

                right++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
```

## 11. Complexity Analysis

Let `n` be the length of the array.

| Operation | Time Complexity |
|---|---|
| Prefix Sum | O(n) |
| Next Greater Element | O(n) |
| Suffix Cost Precomputation | O(n) |
| Binary Lifting Construction | O(n log n) |
| Each Subarray Cost Query | O(log n) |
| Sliding Window | O(n log n) |

**Overall Time Complexity:**

`O(n log n)`

**Auxiliary Space Complexity:**

`O(n log n)`

The binary lifting table requires O(n log n) memory and dominates the other data structures.

## 12. Important DSA Takeaways

This problem combines four important techniques:

1. **Greedy Prefix Maximum:** To make a subarray non-decreasing using only increments, each element must reach at least the maximum of all preceding elements.
2. **Monotonic Stack:** Finds the next strictly greater element and identifies blocks where the running maximum remains constant.
3. **Binary Lifting:** Allows us to skip multiple blocks instead of processing them one by one.
4. **Sliding Window:** Counts valid subarrays efficiently because extending the window cannot decrease its cost and removing its leftmost element cannot increase its cost.

**The central idea:** Instead of calculating the cost of every subarray by examining all its elements, we preprocess the array into blocks of constant running maximum. Binary lifting lets us jump across those blocks efficiently, and Sliding Window handles the final counting.

---

---

*Generated by LeetSync v1.0.0 — 2026-11-13 15:50 UTC*