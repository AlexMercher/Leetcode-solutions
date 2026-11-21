# 3331. Find Subtree Sizes After Changes

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/find-subtree-sizes-after-changes/

---

## Language

C++

---

## Explanation

1. Build the original tree
vector<vector<int>> children(n);

for (int i = 1; i < n; i++) {
    children[parent[i]].push_back(i);
}


What are we doing?

The input gives us a parent array, but DFS is easier when we have access to the children of every node.

For example:
parent = [-1, 0, 4, 0, 1];


We construct:
0 → [1, 3]
1 → [4]
4 → [2]
2 → []
3 → []


Now, starting from any node, we can easily explore its children.

Important: This is the original tree. We must preserve it because all parent changes are determined using the original ancestor relationships.

2. Initialize the data structures for DFS
vector<int> newParent = parent;

vector<int> last(26, -1);

vector<int> previous(n, -1);

vector<int> order;
order.reserve(n);

stack<pair<int, bool>> st;

st.push({0, false});


Let's understand what each variable does.
Variable	Purpose
newParent	Stores the final parent of every node
last	Stores the most recently encountered node for each character along the current DFS path
previous	Stores the previous value of last when entering a node
order	Stores the DFS preorder traversal
st	Performs iterative DFS

Why do we initialize newParent = parent?
Because the problem says that if we cannot find an ancestor with the same character, the node's parent remains unchanged.

Therefore, we only modify newParent[node] when we find a matching ancestor.
Why last(26, -1)?
There are 26 lowercase English characters.
last[0] = last['a' - 'a'];
last[1] = last['b' - 'a'];


Initially, every entry is -1, meaning that we haven't encountered that character on our current DFS path.
What does previous store?
This is important.

Suppose the current node has character a.

Before updating last['a'], we save its previous value.
previous[node] = last[s[node] - 'a'];


We need this information to restore the ancestor state when we finish exploring the current node.

We will understand this in the next chunk.
Why are we using stack<pair<int,bool>>?
The boolean identifies whether we are entering or leaving a node.
st.push({node, false}); // Enter node
st.push({node, true});  // Exit node


This lets us implement recursive DFS iteratively.

We use iterative DFS to avoid recursion-stack overflow when the tree contains up to 10^5 nodes.

DFS: Find the closest matching ancestor
This is the most important part of the implementation.
while (!st.empty()) {

    auto [node, isExit] = st.top();
    st.pop();

    int c = s[node] - 'a';

    // Exit node
    if (isExit) {
        last[c] = previous[node];
        continue;
    }

    // Enter node
    order.push_back(node);

    previous[node] = last[c];

    if (last[c] != -1) {
        newParent[node] = last[c];
    }

    last[c] = node;

    st.push({node, true});

    for (int i = (int)children[node].size() - 1; i >= 0; i--) {
        st.push({children[node][i], false});
    }
}


Let's divide this further.
3.1. Extract the node and identify its character
auto [node, isExit] = st.top();
st.pop();

int c = s[node] - 'a';


We extract the node and convert its character into an integer between 0 and 25.

For example:
'a' → 0
'b' → 1
'c' → 2


3.2. Handle the exit event (Backtracking)
if (isExit) {
    last[c] = previous[node];
    continue;
}


This is extremely important.

Remember that last[c] represents the most recently encountered node with character c along the current DFS path.

Suppose we have:
       0(a)
        |
       1(b)
        |
       2(a)


When we enter node 2:
previous[2] = last['a'];


At this point:
last['a'] = 0


Then we update:
last['a'] = 2;


Now imagine we finish exploring node 2.

We execute:
last['a'] = previous[2];


So:
last['a'] = 0


Why restore it?

Because node 2 is no longer part of the current DFS path once we finish exploring it.

Without restoration, other branches might incorrectly consider node 2 as their ancestor.

This process is called Backtracking.

Think of it as:
- Entering a node: Save the previous state and update it.
- Leaving a node: Restore the previous state.
3.3. Handle the entry event
order.push_back(node);

previous[node] = last[c];


First, we record the node in our DFS preorder.

Then we save the previously encountered node with the same character.

Remember, last[c] contains the closest matching ancestor because DFS reaches ancestors before descendants.

Now:
if (last[c] != -1) {
    newParent[node] = last[c];
}


If a matching ancestor exists, we update the new parent.

Otherwise, newParent[node] retains its original parent.

Finally:
last[c] = node;


We mark the current node as the most recently encountered node with this character.

This makes it available as a potential matching ancestor for its descendants.
3.4. Schedule the exit event and children
st.push({node, true});

for (int i = (int)children[node].size() - 1; i >= 0; i--) {
    st.push({children[node][i], false});
}


Why do we push the exit event before the children?

Remember, a stack follows LIFO (Last In, First Out).

We want the following execution order:
Enter parent
    Enter child
        Enter grandchild
        Exit grandchild
    Exit child
Exit parent


By pushing the exit event first and then pushing the children, the children are processed before the exit event.

We push children in reverse order so they are processed in their original adjacency-list order.

This recreates recursive DFS behavior using an explicit stack.

4. Calculate subtree sizes using reverse DFS order
Once DFS finishes, we have two important things:
1. newParent: The final parent of every node.
2. order: The original DFS preorder traversal.
Now comes an interesting optimization.

Normally, we could construct another adjacency list using newParent and perform another DFS to calculate subtree sizes.

But we don't need to!

We can directly calculate the subtree sizes using reverse DFS order.
vector<int> ans(n, 1);

for (int i = n - 1; i > 0; i--) {

    int node = order[i];

    ans[newParent[node]] += ans[node];
}


Let's understand why this works.
4.1. Initialize every node's subtree size to 1
vector<int> ans(n, 1);


Every node contributes at least itself to its subtree.

Therefore, initially:
ans[0] = 1
ans[1] = 1
ans[2] = 1
...


4.2. Process nodes in reverse DFS order
for (int i = n - 1; i > 0; i--)


DFS preorder visits a parent before its descendants.

Therefore, reversing the traversal ensures that descendants are processed before their ancestors.

This is exactly what we need for subtree-size calculation.
4.3. Add the current node's subtree size to its new parent
int node = order[i];

ans[newParent[node]] += ans[node];


Suppose:
Node 2 has subtree size = 1
New parent of node 2 = 1


We execute:
ans[1] += ans[2];


Now node 1's subtree size includes node 2.

Later, when node 1 is processed, its accumulated subtree size is added to its own new parent.

This propagates subtree sizes all the way to the root.
Why does reverse original DFS order work even though the tree has changed?
This is the clever part.

Every new parent is either:
- The original parent, or
- An ancestor of the node in the original tree.
Therefore, the new parent always appears before the node in the original DFS preorder.

Consequently, in reverse preorder, the node is always processed before its new parent.

That guarantees correct bottom-up aggregation without building the modified tree again.
At this point, every node has received the subtree sizes of all its descendants in the final tree.

The resulting array is exactly what the problem asks for.

---

---

*Generated by LeetSync v1.0.0 — 2026-11-21 15:43 UTC*