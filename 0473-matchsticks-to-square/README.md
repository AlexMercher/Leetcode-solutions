# 473. Matchsticks to Square

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/matchsticks-to-square/

---

## Language

C++

---

## Explanation

1. First, what are we trying to do?

Suppose:

matchsticks = [1,1,2,2,2]

Total:

1+1+2+2+2 = 8

So each side of the square must have length:

8 / 4 = 2

Now the problem becomes:

Can we divide all matchsticks into 4 groups, each having sum 2?

For example:

1+1 = 2
2    = 2
2    = 2
2    = 2

Yes.

2. Why do we use a bitmask?

There are at most 15 matchsticks.

We need to remember:

Which matchsticks have already been used?

Instead of maintaining a vector<bool>, we use an integer where each bit represents one matchstick.

For:

matchsticks = [1,1,2,2,2]
index          0 1 2 3 4

we can represent:

bit 0 → stick 0 used?
bit 1 → stick 1 used?
bit 2 → stick 2 used?
bit 3 → stick 3 used?
bit 4 → stick 4 used?

For example:

mask = 00101

means:

stick 0 → used
stick 1 → not used
stick 2 → used
stick 3 → not used
stick 4 → not used
3. Checking whether a stick is already used

We use:

mask & (1 << i)

Suppose:

i = 2

then:

1 << 2 = 00100

If:

mask = 10101

then:

10101
00100
-----
00100

which is non-zero.

Therefore stick 2 is already used.

Hence:

if(mask & (1 << i))
    continue;

means:

Skip this matchstick because we already used it.

4. Marking a stick as used

When we choose stick i:

mask | (1 << i)

sets bit i to 1.

Example:

mask = 00101
i = 3

1 << 3 = 01000

00101
01000
-----
01101

Now stick 3 is marked as used.

So these two operations are the standard pair:

Check:
mask & (1 << i)

Mark:
mask | (1 << i)
5. What does currentSide mean?

This is the second important part.

dfs(mask, currentSide)

means:

We have already used the sticks represented by mask, and the current side of the square currently has length currentSide.

Suppose:

side = 2

and:

currentSide = 1

If we choose a matchstick of length 1:

1 + 1 = 2

we have completed this side.

So:

if(nextSide == side)
    nextSide = 0;

means:

Side completed → start building the next side.

6. Why don't we explicitly keep track of which of the 4 sides we are on?

Because we don't actually need to.

Suppose:

currentSide = 0

That means the current side is empty.

When we keep adding sticks:

0 → 1 → 2

we complete one side and reset:

2 → 0

Then we are implicitly building the next side.

After four sides are completed:

currentSide = 0

and if all matchsticks are used, we are done.

So:

if(mask == (1 << matchsticks.size()) - 1)
    return currentSide == 0;

means:

Every stick has been used, and the current side is also complete.

That means a complete square has been formed.

7. Why do we test currentSide + matchsticks[i] > side?

Because a side cannot exceed the target length.

Suppose:

side = 5
currentSide = 4

and we try a stick of length 3:

4 + 3 = 7

Impossible.

So:

if(currentSide + matchsticks[i] > side)
    continue;

prunes that branch immediately.

This is important because otherwise backtracking would explore many obviously impossible states.

8. What exactly does dfs() do?

Your function:

bool dfs(int mask, int currentSide)

is basically asking:

Can I finish the square from here?

For every unused matchstick:

choose stick
    ↓
add to current side
    ↓
if side complete:
    start next side
    ↓
recursively continue

If any choice succeeds:

if(dfs(...))
    return true;

then the whole problem is possible.

Otherwise:

return false;
9. Why is memoization needed?

Suppose you reach:

mask = 101001101
currentSide = 1

There may be many different orders in which you could have chosen the already-used sticks.

But once you reach the same state, the past order no longer matters.

The future possibilities depend only on:

which sticks are used
+
how much of the current side is filled

So we can cache:

memo[mask]

and avoid solving the same state repeatedly.

This is state compression.

10. Now why do we sort with rbegin() and rend()?

You have:

sort(matchsticks.rbegin(), matchsticks.rend());

Normally:

sort(matchsticks.begin(), matchsticks.end());

sorts in ascending order:

1 1 2 2 2

But:

sort(matchsticks.rbegin(), matchsticks.rend());

sorts in descending order:

2 2 2 1 1
Why do we want that?

This is a pruning optimization.

We try the largest matchsticks first.

Suppose:

side = 5

and remaining sticks are:

4, 4, 3, 2, 1

Trying the 4s first quickly tells us whether they can fit.

Large sticks are more likely to cause:

currentSide + stick > side

which immediately eliminates that branch.

For example:

currentSide = 3
stick = 4

gives:

3 + 4 > 5

so we immediately skip it.

If we tried small sticks first, we might spend a lot of time constructing partial sides before eventually discovering that a large stick cannot fit anywhere.

So descending sort is not required for correctness.

It is an optimization that makes the backtracking search much faster.

11. rbegin() and rend() specifically

You asked what these actually mean.

For:

vector<int> v = {1,2,3,4};

normal iterators:

v.begin()

points to:

1

and:

v.end()

points just after the last element.

Reverse iterators work in the opposite direction:

v.rbegin()

points to:

4

and:

v.rend()

is the position before the first element in reverse traversal.

Therefore:

sort(v.rbegin(), v.rend());

means:

Sort according to reverse traversal → descending order.

So:

begin → end
1 2 3 4

rbegin → rend
4 3 2 1
12. Why rbegin/rend instead of greater<int>()?

You could also write:

sort(matchsticks.begin(),
     matchsticks.end(),
     greater<int>());

which also gives:

4 3 2 1

Both are correct.

I personally like:

sort(v.rbegin(), v.rend());

when I simply want descending order because it is compact.

13. The entire algorithm in one picture
Calculate total
      ↓
total % 4 != 0?
      ↓ yes
    false

Calculate side = total / 4
      ↓
Sort sticks descending
      ↓
DFS(mask, currentSide)
      ↓
Try every unused stick
      ↓
Does it fit?
      ↓
YES
      ↓
Add it
      ↓
Side complete?
  ┌───────┴───────┐
 YES             NO
  ↓               ↓
reset to 0      continue
  └───────┬───────┘
          ↓
       recurse
          ↓
 all sticks used + side = 0?
          ↓
        true
The two most important ideas
Bitmask
mask

answers:

Which matchsticks have I already used?

currentSide

answers:

How much length have I currently built for this side?

Together:

dfs(mask, currentSide)

completely describes the state.

And:

sort(matchsticks.rbegin(), matchsticks.rend());

does not change the answer. It simply makes the backtracking find bad branches earlier, which is a classic pruning optimization.

---

## My Notes

Could not think in this was trying to make in using knapsack and making sure that we can make the total/4 and total/2 and thus increasing the learning complexity of the given question.

---

---

*Generated by LeetSync v1.0.0 — 2026-09-03 18:11 UTC*