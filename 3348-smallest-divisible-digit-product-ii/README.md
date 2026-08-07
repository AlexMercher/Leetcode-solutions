# 3348. Smallest Divisible Digit Product II

---

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/smallest-divisible-digit-product-ii/

---

## Language

C++

---

## Explanation

# Smallest Divisible Digit Product II - Solution Explanation

## Problem Intuition

At first glance, this problem appears to be a **DP + Backtracking** problem because we need to construct the smallest number while satisfying a divisibility condition.

However, the key observation is that the **product of digits only depends on the prime factors {2,3,5,7}**. Once we realize this, the problem becomes much simpler.

Instead of tracking the actual product of digits (which can become extremely large), we only track how many prime factors are still required.

For example,

```
t = 360

360 = 2³ × 3² × 5¹
```

So instead of storing `360`, we store

```
need = [3,2,1,0]
```

where

```
need[0] -> powers of 2
need[1] -> powers of 3
need[2] -> powers of 5
need[3] -> powers of 7
```

---

# Overall Approach

The algorithm works in four phases.

1. Factorize `t` into prime exponents.
2. Check whether the original number already satisfies the requirement.
3. Try modifying the number from right to left while keeping the prefix unchanged.
4. If no number of the same length exists, construct the smallest valid number of greater length.

The entire solution runs in almost linear time.

---

# Function Explanations

---

## 1. primeFactor()

```cpp
bool primeFactor(u64 x)
```

### Purpose

Factorizes `t` into

```
2
3
5
7
```

and stores their exponents.

Example

```
t = 360

360 = 2³ × 3² × 5¹
```

becomes

```
exp =

[3,2,1,0]
```

### Why only these four primes?

Every digit from

```
1...9
```

contains only these prime factors.

For example,

```
8 = 2³
9 = 3²
6 = 2×3
```

If after removing

```
2,3,5,7
```

some factor still remains,

```
t = 26

26 = 2×13
```

then no digit product can ever produce

```
13
```

Therefore

```cpp
return x==1;
```

means

```
All factors were removable.
```

Otherwise,

```
return false
```

immediately.

---

## 2. modifyExp()

```cpp
modifyExp(char digit,int dir)
```

### Purpose

Updates the remaining required prime factors.

Suppose we still need

```
2³ × 3²
```

If we place digit

```
8
```

then

```
8 = 2³
```

so the remaining requirement becomes

```
3²
```

Instead of recomputing everything,

we simply do

```
exp[0]-=3
```

Similarly

```
6

=

2×3
```

updates

```
exp[0]--
exp[1]--
```

Passing

```
dir=-1
```

means

```
Use this digit.
```

Passing

```
dir=+1
```

means

```
Undo the choice.
```

This makes backtracking extremely cheap.

---

## 3. buildSuffix()

```cpp
string buildSuffix(...)
```

This is the heart of the solution.

Instead of asking

> Can we finish?

it directly constructs

> The smallest possible suffix that satisfies the remaining factors.

---

### Step 1

Extract remaining required factors.

```
e0 = remaining twos
e1 = remaining threes
e2 = remaining fives
e3 = remaining sevens
```

Negative values are clamped to zero because once a requirement is satisfied, extra factors are harmless.

---

### Step 2

Handle factors of 5 and 7.

Only one digit contributes them.

```
5 -> factor 5

7 -> factor 7
```

Therefore

```
Need 5²

↓

55
```

No optimization exists.

---

### Step 3

Pack powers of 2.

Instead of

```
2

2

2
```

use

```
8
```

because

```
8 = 2³
```

Hence

```cpp
digit[8]=e0/3;
```

The remainder is

```
0

1

2
```

which is handled later.

---

### Step 4

Pack powers of 3.

Instead of

```
3

3
```

use

```
9
```

because

```
9 = 3²
```

---

### Step 5

Handle remaining combinations.

If

```
Need

2¹

3¹
```

Instead of

```
2

3
```

use

```
6
```

saving one digit.

Similarly

```
Need

2²
```

uses

```
4
```

instead of

```
2

2
```

---

### Step 6

Check feasibility.

Suppose the suffix length is

```
5
```

but we require

```
7
```

digits.

Impossible.

Therefore

```cpp
valid=false;
```

---

### Step 7

Pad with ones.

```
1
```

does not affect the digit product.

Therefore any remaining positions are filled with

```
111...
```

---

### Step 8

Sort.

Initially we might have

```
875611
```

Sorting gives

```
115678
```

which is the lexicographically smallest suffix.

---

# Main Algorithm

---

## Step 1

Factorize

```
t
```

If impossible,

```
return "-1"
```

---

## Step 2

Check whether the original number already works.

Traverse every digit.

```
12355
```

Subtract its contribution.

If all required factors become

```
0
```

then

```
12355
```

already satisfies the condition.

Return immediately.

---

## Step 3

Search from right to left.

This is an important greedy idea.

Suppose

```
123456
```

We first try changing

```
12345_
```

Only if impossible do we try

```
1234__
```

Then

```
123___
```

Changing the rightmost possible digit guarantees the smallest larger number.

---

For every position,

try replacing it with

```
current_digit+1

...

9
```

For each candidate,

update the remaining required factors,

construct the optimal suffix,

and return immediately if successful.

---

## Step 4

No same-length answer exists.

Example

```
99999
```

Then we must construct

the smallest valid number

of length

```
n+1
```

If that length is still insufficient,

increase it further.

---

# Why This Works

The key insight is that **once the prefix is fixed, the suffix no longer requires searching**.

It has a unique greedy construction.

Therefore,

instead of exploring exponentially many suffixes,

the algorithm directly builds the optimal suffix.

This completely eliminates recursion and dynamic programming.

---

# Time Complexity

Prime Factorization

```
O(log t)
```

Processing original number

```
O(n)
```

Trying replacements

```
9n
```

Building suffix

```
O(1)
```

(Only constant number of prime exponents are processed.)

Overall

```
O(n)
```

---

# Space Complexity

```
O(1)
```

Only a few arrays of fixed size are maintained.

---

# Key Takeaways

- Reduce the problem to its mathematical core (prime exponents).
- Track **remaining requirements** instead of recomputing products.
- Update state incrementally instead of recalculating prefixes.
- Build the optimal suffix greedily instead of searching for one.
- Modify digits from **right to left** to obtain the smallest valid number.

This combination of mathematical reduction and greedy construction transforms a problem that initially appears exponential into an efficient linear-time solution.

---

## My Notes

I did not solve this problem optimally at all i can learn something from this guy that is wrote this solution hence i am submitting it to my github.

Kudos to the guy who can think such a solution on his own.

---

---

*Generated by LeetSync v1.0.0 — 2026-08-07 16:31 UTC*