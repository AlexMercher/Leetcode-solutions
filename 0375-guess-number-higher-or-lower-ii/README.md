# 375. Guess Number Higher or Lower II

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/guess-number-higher-or-lower-ii/

---

## Language

C++

---

## Explanation

1. What does dp[lo][hi] mean?

It means:

dp[lo][hi]
=
minimum money required to guarantee finding the
number when the possible numbers are from lo to hi.

For example:

dp[2][5]

means:

What is the minimum amount of money I need to guarantee finding the hidden number if it is somewhere between 2 and 5?

2. Why do we calculate by interval length?

Our recurrence for:

dp[lo][hi]

depends on smaller intervals:

dp[lo][k-1]
dp[k+1][hi]

These intervals are always smaller than [lo, hi].

Therefore we must calculate smaller intervals first.

That's why:

for(int len = 2; len <= n; len++)

starts with intervals of length 2.

For example, for n = 4:

length 2:
[1,2] [2,3] [3,4]

length 3:
[1,3] [2,4]

length 4:
[1,4]

By the time we calculate [1,4], all the smaller intervals it needs are already available.

This is the standard bottom-up interval DP order:

small intervals
      ↓
larger intervals
      ↓
whole interval
3. How do we get hi?

We know:

lo
len

So:

int hi = lo + len - 1;

For example:

lo = 2
len = 3

hi = 2 + 3 - 1
   = 4

So the interval is:

[2,4]
4. Why do we initialize dp[lo][hi] = INT_MAX?

We are going to try every possible guess.

Initially we don't know which guess is best.

So:

dp[lo][hi] = INT_MAX;

means:

current best answer = infinity

Then every candidate guess can improve it.

5. Try every possible first guess

Suppose the current interval is:

[1,4]

We can guess:

1
2
3
4

So:

for(int k = lo; k <= hi; k++)

tries every possible first guess.

6. What happens after guessing k?

Suppose:

lo = 1
hi = 4
k = 2

We guess 2.

If the guess is wrong, the hidden number must be either:

[1,1]

or:

[3,4]

So:

int left = dp[lo][k - 1];
int right = dp[k + 1][hi];

becomes:

left  = dp[1][1]
right = dp[3][4]
7. Why do we take max(left, right)?

Because we need enough money for the worst possible outcome.

The hidden number could be on either side.

Suppose:

left = 2
right = 7

Then you must have:

7

dollars available for the remaining game, because the hidden number might be on the right.

So:

max(left, right)

represents the worst case after choosing k.

8. Why add k?

If our guess k is wrong, we pay k dollars.

Therefore:

int cost = k + max(left, right);

means:

money spent on current wrong guess
+
money needed for the worst remaining interval
9. Why take min afterward?

Now we've calculated the cost of choosing one particular k.

But we are free to choose the first guess.

So we want the best first guess.

Therefore:

dp[lo][hi] =
    min(dp[lo][hi], cost);

This gives the basic minimax structure:

                choose guess k
                     ↓
            ┌────────┴────────┐
            ↓                 ↓
         hidden left       hidden right
            ↓                 ↓
          cost L             cost R
            └────────┬────────┘
                     ↓
                MAX(L, R)
                     ↓
            cost for this k
                     ↓
        try every possible k
                     ↓
                 MIN(...)

So remember:

MIN = our choice
MAX = worst case
10. Why is dp[lo][hi] = 0 initially for some intervals?

Because the vector is initialized with zeros:

vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

An interval containing one number needs 0 dollars.

For example:

[5]

You guess 5 correctly immediately.

You don't pay anything.

Therefore:

dp[5][5] = 0

Similarly, the empty intervals created by:

dp[lo][k-1]
dp[k+1][hi]

at boundaries are also naturally treated as 0.

11. Why don't we calculate intervals of length 1?

Because they are already correctly initialized:

dp[i][i] = 0

So we start:

len = 2
12. Small dry run: n = 3

Start with:

dp[i][i] = 0
Interval [1,2]

Try k = 1:

cost = 1 + max(dp[1][0], dp[2][2])
     = 1 + max(0,0)
     = 1

Try k = 2:

cost = 2 + max(dp[1][1], dp[3][2])
     = 2

Therefore:

dp[1][2] = 1
Interval [2,3]

Similarly:

dp[2][3] = 2
Interval [1,3]

Try k = 1:

cost = 1 + max(dp[1][0], dp[2][3])
     = 1 + 2
     = 3

Try k = 2:

cost = 2 + max(dp[1][1], dp[3][3])
     = 2

Try k = 3:

cost = 3 + max(dp[1][2], dp[4][3])
     = 3 + 1
     = 4

Therefore:

dp[1][3] = min(3,2,4)
         = 2

Answer:

2
13. Why the n + 2 table is useful

The recurrence can produce:

dp[lo][k - 1]

when:

k = lo

giving:

dp[lo][lo-1]

which is an empty interval.

It can also produce:

dp[k + 1][hi]

when:

k = hi

giving:

dp[hi+1][hi]

So we allow the indexes:

0 ... n+1

hence:

n + 2

The extra positions represent empty intervals and let the recurrence stay clean.

---

## My Notes

The recurrence was too hard to think and array index out of bounds error was still there because i was only using the n+1 not n+2 in the dp state init.

---

---

*Generated by LeetSync v1.0.0 — 2026-09-01 04:49 UTC*