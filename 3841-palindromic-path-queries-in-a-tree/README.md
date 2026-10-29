# 3841. Palindromic Path Queries in a Tree

---

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/palindromic-path-queries-in-a-tree/

---

## Language

C++

---

## Explanation

Chunk 1: Representing characters using XOR masks
This is the foundation of the entire program.
1 << (s[u] - 'a')

Every character gets one unique bit:
So the resulting integer tells us exactly which characters occur an odd number of times.
__builtin_popcount((unsigned)mask) <= 1


__builtin_popcount counts the number of set bits. If at most one bit is set, at most one character has an odd frequency, so the path can form a palindrome.

Mental model: Every character toggles its own bit. Characters occurring an even number of times disappear from the final mask.

Chunk 2: Preparing the tree — adjacency list, Euler tour, and root-prefix masks
These declarations store the information we need about the tree:
vector<vector<int>> adj, up;
vector<int> depth, tin, tout, base;
string s;
int LOG, timer;


Each variable has a specific job.
Variable	Purpose
adj	Stores which nodes are connected to each node
up[j][u]	Stores the ancestor of u that is \(2^j\) levels above it
depth[u]	Distance from root 0 to node u
tin[u]	Euler-tour entry position of node u
tout[u]	Last Euler-tour position belonging to u's subtree
base[u]	Initial XOR mask along the path from root to u
LOG	Number of ancestor levels needed for binary lifting
timer	Assigns Euler-tour positions

Let's see how the preprocessing builds this information.
2.1 Build the adjacency list
for (auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
}


Because the tree is undirected, every edge is inserted in both directions.
2.2 DFS computes the initial information
void dfs(int u, int p) {
    tin[u] = timer++;
    up[0][u] = p;

    base[u] = (p == u ? 0 : base[p])
              ^ (1 << (s[u] - 'a'));

    for (int j = 1; j < LOG; j++) {
        up[j][u] = up[j - 1][up[j - 1][u]];
    }

    for (int v : adj[u]) {
        if (v == p) continue;

        depth[v] = depth[u] + 1;
        dfs(v, u);
    }

    tout[u] = timer - 1;
}


This function does four important things.

A. Assigns Euler-tour positions
tin[u] = timer++;


Each node gets a unique position when DFS enters it.

After DFS finishes a node's entire subtree:
tout[u] = timer - 1;


The subtree occupies the continuous interval:
[tin[u],tout[u]]
This property is essential for efficiently updating all nodes in a subtree.

B. Records the immediate parent
up[0][u] = p;


up[0][u] is the parent of node u. The root is its own parent here, so up[0][0] = 0.

C. Calculates the initial root-prefix XOR mask
base[u] = (p == u ? 0 : base[p])
          ^ (1 << (s[u] - 'a'));


For every node, this calculates:base[u]=base[parent[u]]^ mask(s[u])

D. Precomputes ancestors for binary lifting
for (int j = 1; j < LOG; j++) {
    up[j][u] = up[j - 1][up[j - 1][u]];
}


This uses the identity:
\[
up[j][u]=up[j-1][up[j-1][u]]
\]

In plain English, to go (2^j) levels up, go (2^{j-1}) levels up twice.

For example:
- up[0][u]: 1 level up.
- up[1][u]: 2 levels up.
- up[2][u]: 4 levels up.
- up[3][u]: 8 levels up.
This makes finding ancestors much faster than climbing one parent at a time.

2.3 Why calculate LOG?
LOG = 1;
while ((1 << LOG) <= n) LOG++;


We need enough ancestor levels to jump across the tree's maximum possible depth. For \(n=50{,}000\), only about 16 levels are needed.

That is why the ancestor table takes \(O(n\log n)\) space rather than storing every possible ancestor for every node.
Chunk 3: Finding the Lowest Common Ancestor (LCA)
The LCA of nodes u and v is their deepest shared ancestor.

For a query path from u to v, the route goes:
1. Upward from u to the LCA.
2. Downward from the LCA to v.
The function lca(u, v) finds this meeting point in \(O(\log n)\).
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];

    for (int j = 0; j < LOG; j++) {
        if (diff & (1 << j))
            u = up[j][u];
    }

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[j][u] != up[j][v]) {
            u = up[j][u];
            v = up[j][v];
        }
    }

    return up[0][u];
}


The logic has three stages:
- Equalize depths: Move the deeper node upward until both nodes are at the same depth.
- Jump upward together: Starting with the largest jumps, move both nodes up whenever their ancestors differ.
- Return the parent: When the nodes are immediately below the LCA, return up[0][u].
We need the LCA because the root-prefix masks of u and v share a common section. The LCA lets us cancel that shared section correctly.
Chunk 4: Fenwick tree — making character updates efficient
This is the most important optimization in the program.

We have already computed base[u], the original root-to-node XOR mask. But suppose the character at node u changes from 'a' to 'c'.

Every node in u's subtree has a root-to-node path that passes through u. Therefore, every root-prefix mask in that subtree must be corrected.

Updating each descendant individually could take \(O(n)\) time. The Fenwick tree lets us apply the correction to the entire subtree in \(O(\log n)\).
4.1 What is stored in the Fenwick tree?
struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}


This Fenwick tree stores XOR corrections at Euler-tour positions. It does not store the characters themselves.

The three methods are:
void add(int i, int x) {
    for (; i <= n; i += i & -i)
        bit[i] ^= x;
}


add applies an XOR value at a Fenwick index. The expression i & -i identifies the lowest set bit of i, which determines the next Fenwick index to update.
int query(int i) {
    int ans = 0;
    for (; i > 0; i -= i & -i)
        ans ^= bit[i];
    return ans;
}


query(i) calculates the XOR of all corrections from the beginning through index i.

Both operations take \(O(\log n)\).
4.2 Why does the range update use two points?
void rangeXor(int l, int r, int x) {
    add(l + 1, x);
    if (r + 2 <= n) add(r + 2, x);
}


The desired operation is to XOR x into every Euler position in the inclusive range [l, r].

Fenwick trees are normally 1-indexed, but our Euler positions are 0-indexed, so we convert positions using +1.

We place a marker at the beginning of the range and another immediately after the range:
- At l + 1, start applying correction x.
- At r + 2, cancel that correction by applying x again.

This is the classic difference-array technique adapted to XOR, with the Fenwick tree making prefix queries and point markers efficient.
4.3 Getting the current root-prefix mask
auto prefixmask = [&](int u) {
    return base[u] ^ fw.query(tin[u] + 1);
};


Here:
- base[u] is the original root-prefix mask.
- fw.query(tin[u] + 1) gives all corrections affecting node u.
- XORing them produces the current root-prefix mask.
The lambda is simply a small helper function that performs this calculation whenever we need it.
4.4 Processing an update
if (op == "update") {
    ss >> c;

    int delta = (1 << (s[u] - 'a'))
              ^ (1 << (c - 'a'));

    fw.rangeXor(tin[u], tout[u], delta);
    s[u] = c;
}


Let's say node u changes from 'a' to 'c'.
int delta = mask('a') ^ mask('c');


This is the difference between the old character's parity contribution and the new character's contribution.

Then:
fw.rangeXor(tin[u], tout[u], delta);


applies that correction to the entire subtree of u, using the Euler-tour interval.

Finally:
s[u] = c;


updates the actual character stored at the node.

Why this is efficient: the program does not visit every descendant. One subtree range update takes \(O(\log n)\), regardless of the subtree's size.
Chunk 5: Answering a path query
Now we combine everything.
else {
    ss >> v;

    int w = lca(u, v);

    int mask = prefixmask(u)
             ^ prefixmask(v)
             ^ (1 << (s[w] - 'a'));

    ans.push_back(
        __builtin_popcount((unsigned)mask) <= 1
    );
}


There are three steps.
5.1 Find the meeting point
int w = lca(u, v);


Find the LCA of the two nodes. Call it w.
5.2 Calculate the path's character mask
int mask = prefixmask(u)
         ^ prefixmask(v)
         ^ (1 << (s[w] - 'a'));


This formula is the heart of the query.

Let:
- (P[u]) be the current XOR mask from root to u.
- (P[v]) be the current XOR mask from root to v.
- (C[w]) be the character mask at the LCA.
PathMask=XOR(P[u],P[v],C[w])
Both root-prefix paths contain the root-to-LCA section. XORing the two prefix masks cancels the shared section, including the LCA's character:

But the actual path from u to v includes the LCA exactly once. So we XOR its character back in.

This produces exactly the parity mask of the characters on the required path, without visiting the individual nodes.
5.3 Check whether a palindrome is possible
ans.push_back(
    __builtin_popcount((unsigned)mask) <= 1
);


If at most one bit is set, at most one character has an odd frequency. The query returns true; otherwise, it returns false.

The result is appended to ans. Update operations do not add anything to the answer array.

---

---

*Generated by LeetSync v1.0.0 — 2026-10-29 09:22 UTC*