# 1656. Design an Ordered Stream

---

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/design-an-ordered-stream/

---

## Language

C++

---

## Explanation

1. The storage
vector<string> stream;

We make an array where:

stream[id] = value of that id

For:

insert(3, "ccccc")

we do:

stream[3] = "ccccc";

So:

ID:       1       2       3       4       5
        ┌─────┬─────┬─────┬─────┬─────┐
stream: │ ""  │ ""  │ccccc│ ""  │ ""  │
        └─────┴─────┴─────┴─────┴─────┘

We're using id directly as the index.

That's why the vector has:

stream.resize(n + 1);

We ignore index 0 and use 1...n.

2. What is ptr?
int ptr;

This is the most important variable.

It means:

"What is the smallest ID that I have not returned yet?"

Initially:

ptr = 1;

because the first thing we need to return is ID 1.

So initially:

ptr
 ↓
ID:    1    2    3    4    5
       ?    ?    ?    ?    ?
3. Now insert ID 3
insert(3, "ccccc");

First:

stream[idKey] = value;

becomes:

stream[3] = "ccccc";

Now:

ID:       1       2       3       4       5
        ┌─────┬─────┬───────┬─────┬─────┐
        │ ""  │ ""  │ ccccc │ ""  │ ""  │
        └─────┴─────┴───────┴─────┴─────┘
          ↑
         ptr=1

Now this loop runs:

while (ptr < stream.size() && stream[ptr] != "")

Let's substitute:

ptr = 1
stream[1] = ""

So:

stream[1] != ""

is false.

Therefore the loop never starts.

So:

return ans;

returns:

[]

Why?

Because even though ID 3 exists, we're still waiting for ID 1.

4. Insert ID 1

Now:

insert(1, "aaaaa");

We first store:

stream[1] = "aaaaa";

Now:

ID:       1       2       3       4       5
        aaaaa     ""    ccccc    ""     ""
         ↑
        ptr=1

Then:

while (ptr < stream.size() && stream[ptr] != "")

Check:

ptr = 1
stream[1] = "aaaaa"

So it exists.

Enter loop:

ans.push_back(stream[ptr]);
ptr++;

So:

ans = ["aaaaa"]
ptr = 2

Now loop checks again:

stream[2] = ""

So stop.

Return:

["aaaaa"]
Notice something important

We did not return "ccccc".

Why?

Because ID 2 is missing.

So even though ID 3 is present, we cannot return it yet.

The output has to remain:

1 → 2 → 3 → 4 → 5
5. Insert ID 2

Now:

insert(2, "bbbbb");

Store:

ID:       1       2       3       4       5
        aaaaa   bbbbb   ccccc    ""     ""
                   ↑
                 ptr=2

Now loop:

First iteration
stream[2] = "bbbbb"

exists.

Return it:

ans = ["bbbbb"]
ptr = 3
Second iteration

Now:

stream[3] = "ccccc"

exists too.

So return that as well:

ans = ["bbbbb", "ccccc"]
ptr = 4
Third check
stream[4] = ""

Missing.

Stop.

Return:

["bbbbb", "ccccc"]

This is the important idea:

Once the missing ID gets filled, we keep walking forward as long as the next IDs are already present.

6. Insert ID 5

Now:

insert(5, "eeeee");

Storage:

ID:       1       2       3       4       5
        aaaaa   bbbbb   ccccc    ""    eeeee
                             ↑
                           ptr=4

We are not waiting for ID 1 anymore.

We've already returned 1,2,3.

That's why ptr is now 4.

Check:

stream[4] = ""

So immediately stop.

Even though 5 exists, we can't return it.

Why?

Because ID 4 is still missing.

7. Insert ID 4

Now:

insert(4, "ddddd");

Storage:

ID:       1       2       3       4       5
        aaaaa   bbbbb   ccccc   ddddd   eeeee
                                     ↑
                                   ptr=4

Now:

stream[4] != ""

So:

ans = ["ddddd"]
ptr = 5

Then check ID 5:

stream[5] = "eeeee"

It exists.

So:

ans = ["ddddd", "eeeee"]
ptr = 6

Now we're done.

8. Why ptr solves the whole problem

Imagine we had:

ID:       1    2    3    4    5    6
value:    ✓    ✓    ✓    ?    ✓    ?
                         ↑
                        ptr

We don't care about 1,2,3 anymore.

They have already been returned.

We only care about:

ptr = 4

And the rule is:

Is ID 4 available?
    ↓ no
return nothing

Later:

ID:       1    2    3    4    5    6
value:    ✓    ✓    ✓    ✓    ✓    ?
                         ↑
                        ptr

Now:

4 exists → return
5 exists → return
6 doesn't exist → stop

So the returned chunk is:

[4,5]
9. Why don't we reset ptr every time?

This is very important.

Suppose we've already returned:

["aaaaa", "bbbbb", "ccccc"]

Then:

ptr = 4

We don't want to start checking from 1 again.

If we did, we'd keep returning the same values.

So ptr only moves:

1 → 2 → 3 → 4 → 5 → ...

It never goes backward.

That's what guarantees every value gets returned exactly once.

10. The code in plain English

Your function:

vector<string> insert(int idKey, string value) {
    stream[idKey] = value;

    vector<string> ans;

    while (ptr < stream.size() && stream[ptr] != "") {
        ans.push_back(stream[ptr]);
        ptr++;
    }

    return ans;
}

means:

"Put this value into its correct ID position. Then, starting from the first ID I haven't already returned, keep taking values as long as there are no gaps."

So the condition:

stream[ptr] != ""

is basically checking:

"Do I currently have the next required value?"

And:

ptr++;

means:

"Good, that one is done. Now I need the next ID."

That's the whole mechanism.

The mental model

Think of ptr as a door:

1 → 2 → 3 → 4 → 5
        ↑
       door

Values can arrive behind the door in any order.

But the door only opens when the value immediately at ptr exists.

Once it exists:

ptr → output → move ptr

and it keeps going until it hits a missing value.

That's why the chunks are exactly the largest currently available consecutive block.

---

---

*Generated by LeetSync v1.0.0 — 2026-09-22 13:14 UTC*