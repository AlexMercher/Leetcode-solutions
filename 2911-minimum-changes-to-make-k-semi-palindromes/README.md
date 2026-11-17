# 2911. Minimum Changes to Make K Semi-palindromes

---

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/

---

## Language

C++

---

## Explanation

# Minimum Changes to Make K Semi-Palindromes

## 1. Understanding the Problem

We are given a string `s` and an integer `k`.

We need to divide the string into exactly `k` non-empty, contiguous substrings such that every substring becomes a semi-palindrome using the minimum number of character changes.

A semi-palindrome is a string where we can choose a proper divisor `d` of its length and divide its characters into `d` groups. Every group must be a palindrome.

Our objective is to minimize the total character changes across all `k` substrings.

We solve this using:

1. Divisor Enumeration + Palindrome Cost Calculation.
2. Dynamic Programming for String Partitioning.

## 2. Understanding How to Make a Substring Semi-Palindromic

Consider:

```cpp
s = "abcabc";
```

Its length is 6.

The proper divisors of 6 are:

`d = 1, 2, 3`

We try each divisor.

### Case 1: d = 1

All characters belong to one group:

```text
abcabc
```

We need the entire string to become a palindrome.

We compare symmetric characters:

- a and c: Different.
- b and b: Same.
- c and a: Already accounted for.

One character change is required for the mismatched pair.

### Case 2: d = 2

We create two groups by taking characters at intervals of 2:

```text
Group 1: a c b
Group 2: b a c
```

Each group must independently become a palindrome.

- Group 1: Compare a and b. One change required.
- Group 2: Compare b and c. One change required.

Total changes = 2.

### Case 3: d = 3

We create three groups:

```text
Group 1: a a
Group 2: b b
Group 3: c c
```

All groups are already palindromes.

Total changes = 0.

Therefore, `"abcabc"` is already a semi-palindrome.

The important observation is that we try every proper divisor and choose the one requiring the minimum number of changes.

## 3. Calculate the Cost of Making Any Substring Semi-Palindromic

Define:

`cost[l][r]`

as the minimum number of character changes required to make substring `s[l...r]` a semi-palindrome.

For every substring:

1. Calculate its length.
2. Enumerate all proper divisors.
3. Divide the substring into groups using each divisor.
4. Compare symmetric characters within every group.
5. Count mismatched pairs.
6. Store the minimum cost among all valid divisors.

### Understanding the grouping

Suppose:

```text
Substring = "abcdef"
Length = 6
d = 2
```

The two groups are:

```text
Group 1: a c e
Group 2: b d f
```

The character positions in each group differ by `d`.

For a group, we compare its first and last characters, then move inward.

If two symmetric characters differ, we need exactly one character change.

For example:

```text
a c e

a != e
```

Only one change is required to make this group a palindrome.

### Code to calculate the substring cost

```cpp
int getCost(string& s, int l, int r) {

    int len = r - l + 1;

    int best = INT_MAX;

    // Try every proper divisor
    for (int d = 1; d < len; d++) {

        if (len % d != 0)
            continue;

        int changes = 0;

        // Process each group
        for (int offset = 0; offset < d; offset++) {

            int left = l + offset;

            int right =
                l + offset + ((len - 1 - offset) / d) * d;

            // Compare symmetric characters
            while (left < right) {

                if (s[left] != s[right]) {
                    changes++;
                }

                left += d;
                right -= d;
            }
        }

        best = min(best, changes);
    }

    return best;
}
```

### Understanding the important variables

- `d`: Number of groups.
- `offset`: Identifies which group we are processing.
- `left`: Current character from the beginning of the group.
- `right`: Current character from the end of the group.
- `changes`: Number of mismatched symmetric pairs.

We use `left += d` and `right -= d` because characters belonging to the same group are separated by `d` positions.

## 4. Precompute the Cost of Every Substring

We don't want to calculate the same substring cost repeatedly during DP.

Therefore, we precompute all possible substring costs and store them in a 2D array.

```cpp
vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

for (int i = 0; i < n; i++) {

    for (int j = i + 1; j < n; j++) {

        cost[i][j] = getCost(s, i, j);
    }
}
```

We start `j` from `i + 1` because a substring of length 1 cannot be semi-palindromic.

After this step:

`cost[i][j]`

contains the minimum changes required to make substring `s[i...j]` a semi-palindrome.

We have now converted the string problem into a numerical cost problem.

## 5. Dynamic Programming: Divide the String into K Substrings

Now we need to divide the string into exactly `k` semi-palindromic substrings with minimum total cost.

Define:

`dp[i][j]`

Meaning:

The minimum number of character changes required to divide the first `i` characters of the string into exactly `j` semi-palindromic substrings.

For example:

`dp[6][2]`

represents the minimum cost of dividing the first six characters into exactly two semi-palindromic substrings.

### Step 1: Understand the choices

Suppose we are calculating:

`dp[i][j]`

We need to decide where the last substring begins.

Let its starting index be `p`.

Our partition becomes:

```text
Previous part: s[0 ... p-1]

Last substring: s[p ... i-1]
```

The previous part must be divided into exactly `j-1` semi-palindromic substrings.

Its minimum cost is:

`dp[p][j-1]`

The cost of making the final substring semi-palindromic is:

`cost[p][i-1]`

Therefore, the total cost becomes:

`dp[p][j-1] + cost[p][i-1]`

We try every possible starting position `p` and select the minimum.

### Step 2: DP recurrence

```text
dp[i][j] =
    min(
        dp[p][j-1] + cost[p][i-1]
    )
```

Where:

- `p` must be at least `2 * (j-1)` because every previous substring requires at least two characters.
- `p` must be at most `i-2` because the last substring must also contain at least two characters.

### Step 3: Initialize DP

```cpp
vector<vector<int>> dp(
    n + 1,
    vector<int>(k + 1, INT_MAX / 2)
);
```

Initially, all states are infinity because we haven't found a valid partition.

Our base case is:

```cpp
dp[0][0] = 0;
```

An empty string divided into zero substrings requires zero changes.

### Step 4: Implement the transitions

```cpp
for (int j = 1; j <= k; j++) {

    for (int i = 2 * j; i <= n; i++) {

        for (int p = 2 * (j - 1); p <= i - 2; p++) {

            dp[i][j] = min(
                dp[i][j],
                dp[p][j - 1] + cost[p][i - 1]
            );
        }
    }
}
```

We start `i` at `2*j` because every semi-palindromic substring must have at least two characters.

Finally, our answer is:

`dp[n][k]`

This represents the minimum changes required to divide the entire string into exactly `k` semi-palindromic substrings.

## 6. Dry Run

Consider Example 1:

```cpp
s = "abcac";
k = 2;
```

We need to divide the string into exactly two substrings.

One possible partition is:

```text
"ab" | "cac"
```

### First substring: "ab"

Its only valid divisor is `d = 1`.

The group is:

```text
a b
```

The characters differ, so one change is required.

```text
ab → aa
```

Cost = 1.

### Second substring: "cac"

Its length is 3, and its proper divisor is `d = 1`.

The group is:

```text
c a c
```

It is already a palindrome.

Cost = 0.

Total cost:

```text
1 + 0 = 1
```

The DP examines all possible partition positions and finds this minimum.

Final answer = 1.

## 7. Complete C++ Implementation

```cpp
class Solution {
private:

    // Calculate minimum changes to make s[l...r] semi-palindromic
    int getCost(string& s, int l, int r) {

        int len = r - l + 1;

        int best = INT_MAX;

        // Enumerate proper divisors
        for (int d = 1; d < len; d++) {

            if (len % d != 0)
                continue;

            int changes = 0;

            // Process each group
            for (int offset = 0; offset < d; offset++) {

                int left = l + offset;

                int right =
                    l + offset + ((len - 1 - offset) / d) * d;

                // Check palindrome symmetry
                while (left < right) {

                    if (s[left] != s[right]) {
                        changes++;
                    }

                    left += d;
                    right -= d;
                }
            }

            best = min(best, changes);
        }

        return best;
    }

public:

    int minimumChanges(string s, int k) {

        int n = s.size();

        const int INF = INT_MAX / 2;

        // PART 1: Precompute substring costs

        vector<vector<int>> cost(
            n, vector<int>(n, INF)
        );

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                cost[i][j] = getCost(s, i, j);
            }
        }

        // PART 2: Dynamic Programming

        // dp[i][j] = Minimum cost to divide
        // first i characters into exactly j substrings

        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 1, INF)
        );

        // Base case
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {

            for (int i = 2 * j; i <= n; i++) {

                for (int p = 2 * (j - 1); p <= i - 2; p++) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
```

## 8. Complexity Analysis

Let `n` be the length of the string.

**Precomputation:**

For every substring, we examine its proper divisors and compare symmetric characters within each group.

A conservative upper bound is:

`O(n^4)`

A tighter bound is:

`O(sum over L of (n-L+1) * L * tau(L))`

where `tau(L)` represents the number of positive divisors of `L`.

**Dynamic Programming:**

There are `O(nk)` states, and each state can examine up to `O(n)` possible partition positions.

Therefore:

`O(kn^2)`

**Space Complexity:**

- Substring cost matrix: `O(n^2)`
- DP table: `O(nk)`

Total:

`O(n^2 + nk)`

## 9. Important Takeaways

1. **Divisor Enumeration:** A semi-palindrome requires a proper divisor of its length to determine its repeating groups.
2. **Palindrome Checking:** Every mismatched symmetric pair requires exactly one character change.
3. **Precomputation:** Calculate every substring's minimum semi-palindrome cost once and reuse it during DP.
4. **Partition DP:** Whenever a string must be divided into exactly `k` valid segments, consider where the last segment begins.
5. **DP State:** `dp[i][j]` represents the minimum cost of partitioning the first `i` characters into exactly `j` valid substrings.

The central idea is to separate the problem into two independent parts: first determine the cost of making any substring semi-palindromic, then use Dynamic Programming to find the optimal partition.

---

---

*Generated by LeetSync v1.0.0 — 2026-11-17 10:20 UTC*