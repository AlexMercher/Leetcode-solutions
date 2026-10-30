# 3970. Shortest Path With At Most K Consecutive Identical Characters

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/

---

## Language

C++

---

## Explanation

1. Understanding the problem
We are given a directed, weighted graph where:
- n represents the number of nodes.
- edges[i] = [u, v, w] represents a directed edge from node u to node v with weight w.
- labels[i] represents the character assigned to node i.
- k represents the maximum number of consecutive identical characters allowed in a path.
We need to find the minimum-cost path from node 0 to node n-1 such that we never encounter more than k consecutive identical characters.

For example:
n = 3
edges = [[0,1,1], [1,2,1], [0,2,3]]
labels = "aab"
k = 1

There are two possible paths:
Path	Labels	Cost	Valid for k = 1?
0 → 1 → 2	aab	2	No
0 → 2	ab	3	Yes

The answer is 3.

Notice something important: the cheapest path is not necessarily the valid path.

That is the additional challenge we need to incorporate into Dijkstra's algorithm.

2. Why can't we use normal Dijkstra?
In normal Dijkstra's algorithm, we maintain:
dist[node]


This represents the minimum cost required to reach a particular node.

Suppose we reach node u through two different paths:
Path A: 0 → 1 → u
Path B: 0 → 2 → u


Both paths reach the same node, but their character histories might be different.

For example:
Path A: aa
Path B: ba


Suppose k = 2.

At the current node, the character is a.

The next node also has character a.
- Path A would produce aaa, which is invalid.
- Path B would produce baa, which is valid.
Therefore, knowing only the current node is insufficient.

We need additional information about the state in which we reached that node.

3. Approach: Dijkstra with an expanded state
Initially, we could think of maintaining three dimensions:
\[
dist[node][lastChar][count]
\]

Where:
- node: Current node.
- lastChar: Last character encountered.
- count: Number of consecutive occurrences of that character.
However, this creates unnecessary memory consumption.

Let's understand why.
Step 1: Remove the unnecessary dimension
Ask yourself:

When we are currently standing at node u, what is the last character encountered?

The answer is always:
labels[u]


Why?

Because we visit nodes in sequence, and the current node itself determines the last character in the path.

We do not need to store it separately!

Therefore, we can reduce our state to: dist[node][count]

Now we maintain only:
- node: Current node.
- count: Consecutive occurrences of labels[node].
This is called State Compression.
Example
Suppose:
labels = "aab"


Consider the following states:
Current node	Current character	Consecutive count
0	a	1
1	a	2
2	b	1

We do not need to store the character because it can always be retrieved through labels[node].

This is the most important optimization in our solution.

Step 2: Construct the adjacency list
We need to represent the directed graph efficiently.
vector<vector<pair<int,int>>> adj(n);

for (auto &e : edges) {
    adj[e[0]].push_back({e[1], e[2]});
}


Each adjacency list entry contains:
{destination, weight}


For example:
edges = [[0,1,1], [1,2,1], [0,2,3]]


The adjacency list becomes:
0 → {(1,1), (2,3)}
1 → {(2,1)}
2 → {}


We use an adjacency list because we only need to visit the outgoing neighbours of the current node.

Step 3: Create the distance array
Our state is: dist[node][count]
The maximum consecutive count is k.

Therefore, every node has k + 1 possible count positions.
const long long INF = LLONG_MAX;

vector<long long> dist(
    (size_t)n * (k + 1), INF
);


You might wonder why we are using a one-dimensional array instead of a two-dimensional array.

Both approaches are possible.

However, we can flatten a two-dimensional array into a one-dimensional array using an index calculation.

The mapping is:	{index = node x (k+1) + count}

Step 4: Initialize the starting state
We start at node 0.

Since we have visited only one node, the initial consecutive count is always 1.
dist[1] = 0;
Therefore:
dist[1] = 0;


Our starting state is:
Node = 0
Count = 1
Cost = 0



Step 5: Initialize the priority queue
In Dijkstra's algorithm, we use a min-heap to process the state with the minimum distance first.
using State = pair<long long, int>;

priority_queue<
    State,
    vector<State>,
    greater<State>
> pq;


Each entry contains:
{cost, encoded_state}


We push the starting state:
pq.push({0, 1});


The priority queue now contains:
Cost = 0
State = 1


Remember, our encoded state contains both the node and its consecutive count.

4. The main Dijkstra loop
This is where the actual algorithm works.
while (!pq.empty()) {

    auto [cost, id] = pq.top();
    pq.pop();

    int u = id / (k + 1);
    int cnt = id % (k + 1);

    if (cost != dist[id])
        continue;

    if (u == n - 1)
        return (int)cost;

    // Process neighbours
}


Let's understand each part.
A. Extract the minimum-cost state
auto [cost, id] = pq.top();
pq.pop();


We extract the state with the lowest cost.
We reverse this calculation:
int u = id / (k + 1);
int cnt = id % (k + 1);


Integer division gives us the node.

Modulo gives us the consecutive count.

For example, if:
k = 2
id = 5


Then:
u = 5 / 3 = 1
cnt = 5 % 3 = 2


Our current state is:
Node = 1
Count = 2


C. Ignore outdated states
if (cost != dist[id])
    continue;


Why is this necessary?

Suppose we initially discover a state with cost 10.

Later, we find another path reaching the same state with cost 5.

The priority queue still contains the older entry with cost 10.

We do not need to process it anymore because we already have a better route.

This condition skips such outdated entries.
D. Check whether we reached the destination
if (u == n - 1)
    return (int)cost;


We return when the destination state is extracted from the min-heap.

Why not return when we first discover the destination?

Because we might discover it through a path costing 20, but a cheaper path costing 10 could still exist.

Dijkstra guarantees that when a state is extracted with its minimum distance, that distance is final.

Therefore, this is the correct place to terminate.

5. State transitions — The most important part
Now we process all outgoing edges from the current node.
for (auto &[v, w] : adj[u]) {

    int newCnt;

    if (labels[u] == labels[v])
        newCnt = cnt + 1;
    else
        newCnt = 1;

    if (newCnt > k)
        continue;

    long long newCost = cost + w;

    int newId = v * (k + 1) + newCnt;

    if (newCost < dist[newId]) {

        dist[newId] = newCost;

        pq.push({newCost, newId});
    }
}


There are two important cases.
Case 1: Current and next nodes have the same character
if (labels[u] == labels[v])
    newCnt = cnt + 1;


Suppose:
Current path: aa
Current count: 2

Next node's character: a


We get:
New path: aaa
New count: 3


We increment the consecutive count.
Case 2: Current and next nodes have different characters
else
    newCnt = 1;


Suppose:
Current path: aa
Current count: 2

Next node's character: b


We get:
New path: aab
New count: 1


Why do we reset the count to 1?

Because a new consecutive character sequence has started.
Case 3: Check the constraint
if (newCnt > k)
    continue;


If the new consecutive count exceeds k, we reject this transition.

We simply do not explore that path.
Case 4: Update the distance
long long newCost = cost + w;

int newId = v * (k + 1) + newCnt;

if (newCost < dist[newId]) {

    dist[newId] = newCost;

    pq.push({newCost, newId});
}


We calculate the new cost and encode the destination state.

If the new cost is better than the previously recorded cost, we update the distance and push the new state into the priority queue.

Notice that we are not comparing only the destination node.

We are comparing:
Destination node + Consecutive count

Two different consecutive counts represent two different states.

---

---

*Generated by LeetSync v1.0.0 — 2026-10-30 16:44 UTC*