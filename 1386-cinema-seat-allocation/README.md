# 1386. Cinema Seat Allocation

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/cinema-seat-allocation/

---

## Language

C++

---

## Explanation

## Bitmasking

1. This line
rows[row] |= (1 << s);

Suppose:

row = 3;
s = 5;

We want to record:

Seat 5 in row 3 is reserved.

We represent the reserved seats using the bits of an integer.

1 << s
1 << 5

Binary:

0000000001
       ↑
      bit 5

More explicitly:

bit:    9 8 7 6 5 4 3 2 1 0
        ---------------------
        0 0 0 0 1 0 0 0 0 0

So:

1 << 5

produces:

00100000

which is the integer 32.

The important thing isn't the number 32.

It's:

bit 5 is now ON.

2. Why |=?

Suppose row 1 has:

seat 2 reserved
seat 5 reserved
seat 8 reserved

We process them one by one.

First:
rows[1] |= (1 << 2);

Mask becomes:

0000000100
Then:
rows[1] |= (1 << 5);

Mask becomes:

0000100100
Then:
rows[1] |= (1 << 8);

Mask becomes:

0100100100

So the mask is basically a compact representation:

seat:  10 9 8 7 6 5 4 3 2 1
        0  0 1 0 0 1 0 0 1 0

Meaning:

seat 2 → reserved
seat 5 → reserved
seat 8 → reserved

|= means:

Turn this bit ON while keeping all previously ON bits.

That's why we don't use:

rows[row] = (1 << s);

because that would erase the previously recorded reservations.

3. Why is rows an unordered_map?

We have:

unordered_map<int,int> rows;

Think:

row number → reservation mask

For example:

rows[1] → 0100100100
rows[2] → 0000010000
rows[3] → 1000000000

We only store rows that actually have reservations.

This is extremely important because:

n <= 10^9

We absolutely cannot create:

vector<int> rows(n);

Instead, if only 5000 rows have reservations, we store only those 5000.

4. Now this line
int ans = (n - rows.size()) * 2;

This is another important trick.

Suppose:

n = 1,000,000,000

and only:

rows.size() = 1000

rows have reservations.

That means:

1,000,000,000 - 1,000 = 999,999,000

rows have no reservations at all.

For an empty row, we can always fit:

2 groups

because:

2 3 4 5       6 7 8 9

are both available.

Therefore:

(n - rows.size()) * 2

immediately calculates all unaffected rows.

We don't need to iterate over them.

This is the same general trick:

Huge universe + small number of affected elements → process only the affected elements.

5. Now the interesting part
int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);

The left group requires:

2 3 4 5

So we create a mask where bits 2, 3, 4 and 5 are ON.

Let's calculate:

1 << 2 = 0000000100
1 << 3 = 0000001000
1 << 4 = 0000010000
1 << 5 = 0000100000

OR them:

0000000100
0000001000
0000010000
0000100000
----------
0000111100

So:

left

represents:

seats: 10 9 8 7 6 5 4 3 2 1
       -------------------------
        0  0  0  0 0 1 1 1 1 0

Exactly:

2,3,4,5
6. Middle mask
int middle =
    (1 << 4) |
    (1 << 5) |
    (1 << 6) |
    (1 << 7);

This represents:

4 5 6 7

Binary:

0001111000
7. Right mask
int right =
    (1 << 6) |
    (1 << 7) |
    (1 << 8) |
    (1 << 9);

This represents:

6 7 8 9

Binary:

1111000000
8. Now the beautiful part: checking a group

Suppose:

mask

contains the reserved seats for a row.

We want to ask:

Are any of the seats required by the left group reserved?

We do:

(mask & left) == 0

Remember:

AND:
1 & 1 = 1
1 & 0 = 0
0 & 1 = 0
0 & 0 = 0

So if:

mask  = reserved seats
left  = seats required by group

then:

mask & left

shows the seats that are:

both reserved AND required by the group

Example

Suppose reserved seats are:

2 and 3

Then:

reserved mask:
0000001100

Left group:

0000111100

AND:

0000001100
0000111100
----------
0000001100

Result isn't zero.

Therefore:

(mask & left) == 0

is:

false

So the left group cannot sit there.

9. If there are no conflicts

Suppose only seat 8 is reserved:

reserved:
0100000000

Left:

0000111100

AND:

0100000000
0000111100
----------
0000000000

Therefore:

(mask & left) == 0

is true.

So:

The left group can sit there.

The complete mental picture

Think of the integer as a row of switches:

             RESERVED SEATS


seat:     10 9 8 7 6 5 4 3 2 1
           ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
bits:      0 0 0 0 0 1 1 0 1 0
                         ↑
                    seats 2,3,5

Then the group is another mask:

LEFT GROUP


seat:     10 9 8 7 6 5 4 3 2 1
bits:      0 0 0 0 0 1 1 1 1 0

AND them:

reserved & group

If result:

0

→ no collision → group can sit

If result:

!= 0

→ collision → group cannot sit

The general bitmask pattern

This cinema problem is teaching you a very reusable pattern:

// Add an item
mask |= (1 << i);


// Remove an item
mask &= ~(1 << i);


// Toggle an item
mask ^= (1 << i);


// Check an item
(mask & (1 << i)) != 0;


// Check whether two sets overlap
(mask1 & mask2) != 0;


// Check whether two sets are disjoint
(mask1 & mask2) == 0;

So the cinema problem is essentially:

Reservations
     ↓
convert to bitmask
     ↓
Group requirements → bitmask
     ↓
AND
     ↓
0?       → available
non-zero → blocked

Once this clicks, bitmasking becomes much less mysterious. You're basically using the bits of an integer as a tiny set<bool> with very fast operations.

---

## My Notes

Was not able to think of bitmasking and i was always getting the TLE errors;

---

---

*Generated by LeetSync v1.0.0 — 2026-08-19 10:44 UTC*