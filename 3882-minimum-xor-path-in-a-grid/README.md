# 3882. Minimum XOR Path in a Grid

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/minimum-xor-path-in-a-grid/

---

## Language

C++

---

## Explanation

vector<bitset<1024>> dp(n);


This creates n bitsets, each containing 1024 bits.

Why 1024? Because every grid value is between 0 and 1023, and XOR of numbers in this range also stays within 0 to 1023.

Therefore, we need exactly one bit position for every possible XOR value:
- Bit 0 represents XOR value 0.
- Bit 1 represents XOR value 1.
- Bit 2 represents XOR value 2.
- ...
- Bit 1023 represents XOR value 1023.
If dp[c][7] == 1, that means XOR value 7 is reachable at the cell currently represented by dp[c].

It does not mean the seventh bit of an XOR result is set. The bit's index represents the entire XOR result.

Step A: Capture the possibilities from the top
bitset<1024> top = dp[c];


We process the grid row by row, from left to right.

At the beginning of processing a cell, dp[c] still contains the possibilities from the previous row. Therefore, it represents the cell directly above our current position.

We copy it into top so those possibilities remain available even after we update dp[c].
Step B: Capture the possibilities from the left
bitset<1024> left;

if (c > 0) {
    left = dp[c - 1];
}


When c > 0, dp[c-1] has already been updated for the current row. It therefore represents the cell immediately to our left.

Notice the difference:
- top contains the previous row's possibilities.
- left contains the current row's possibilities.
This is how we reuse just one row of DP instead of storing a bitset for every grid cell.

Step C: Clear the old possibilities for the current cell
dp[c].reset();


We are about to calculate the possibilities for the current cell, so we clear the old bitset.

This is essential. The old bitset represents the cell above, not the cell we're currently processing.
Step D: Handle the starting cell
if (r == 0 && c == 0) {
    dp[c].set(grid[r][c]);
    continue;
}


At the starting cell, there is no top or left cell. The only possible path contains the starting cell itself.

Therefore, if grid[0][0] is 1, we set bit 1:
dp[c].set(1);


This means XOR value 1 is reachable at the starting cell.

The continue skips the normal transition because there are no previous cells to process.
Step E: Generate all new XOR values
int v = grid[r][c];

for (int x = 0; x < 1024; x++) {
    if (top[x] || left[x]) {
        dp[c].set(x ^ v);
    }
}


This is the heart of the algorithm.

The loop considers every possible XOR value, from 0 to 1023.
- top[x] asks: can XOR value x reach the cell from above?
- left[x] asks: can XOR value x reach the cell from the left?
- If either is true, we calculate x ^ v.
- dp[c].set(x ^ v) marks the new XOR value as reachable.
We use || because either predecessor is enough to make a path possible.

Also, setting a bit more than once does no harm. A bit is simply 1 whether one path or a hundred paths produce that XOR value.

Let's trace the same grid:
grid = {
    {1, 2},
    {3, 4}
};


Initially, both bitsets are empty:
dp[0] = {}
dp[1] = {}


Here, {} means no XOR values have been marked as reachable yet.
Cell (0, 0): value = 1
The special starting-cell condition runs:
dp[0].set(1);


Reachable XOR values at this cell
1
Only XOR value 1

Current row state:
dp[0] = {1}
dp[1] = {}



Cell (0, 1): value = 2
This cell is to the right of the starting cell.
top  = dp[1];  // {}
left = dp[0];  // {1}


XOR value 1 is reachable from the left. So we calculate:
\[
1\oplus2=3
\]

And mark it:
dp[1].set(3);


Current row state:
dp[0] = {1}
dp[1] = {3}


At cell (0, 1), XOR value 3 is reachable.

Cell (1, 0): value = 3
We start the second row, at the leftmost cell.
top  = dp[0];  // {1}
left = {};     // no cell to the left


XOR value 1 comes from above:
\[
1\oplus3=2
\]

So the new state is:
dp[0] = {2}
dp[1] = {3}


Notice that dp[0] changed from {1} to {2}. That is correct: it now represents the cell containing 3, not the cell containing 1.

Cell (1, 1): value = 4
This is the destination cell.
top  = dp[1];  // {3}
left = dp[0];  // {2}


There are two reachable XOR values from the previous cells.

From the top:
\[
3\oplus4=7
\]

From the left:
\[
2\oplus4=6
\]

The resulting bitset represents both possibilities:
dp[1] = {6, 7}


The destination can be reached with XOR 6 or XOR 7.

5. How do we find the minimum XOR?
After processing every cell, the final bitset dp[n-1] represents all possible XOR values at the bottom-right cell.

Your code does this:
for (int x = 0; x < 1024; x++) {
    if (dp[n - 1][x]) {
        return x;
    }
}


This is clever because we scan the possible XOR values in ascending order.

For our example, the destination bitset contains:
XOR value:  0  1  2  3  4  5  6  7  ...
Reachable:  0  0  0  0  0  0  1  1  ...


- XOR values 0 through 5 are not reachable.
- XOR value 6 is reachable, so dp[n-1][6] is true.
- We immediately return 6.
We don't need to check 7 or anything greater because we have already found the smallest reachable XOR value.

That is how the algorithm finds the minimum: DP records all reachable values, and the final ascending scan selects the first reachable one.

---

---

*Generated by LeetSync v1.0.0 — 2026-10-28 10:30 UTC*