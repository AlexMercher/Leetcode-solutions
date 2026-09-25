# 1096. Brace Expansion II

---

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/brace-expansion-ii/

---

## Language

C++

---

## Explanation

expression
   ↓
split into UNION pieces
   ↓
for each piece:
    build all possible concatenations
   ↓
put all those results into one set

At the beginning:

set<string> res;

res means:

Everything that this entire expression can produce.

For example:

{a,b,c}

should eventually give:

res = {"a","b","c"}

Why set?

Because the grammar says duplicates are allowed during expansion but the final set must contain each word only once.

So:

res.insert(x);

automatically handles duplicates.

3. The outer while handles UNION
while(i < s.size() && s[i] != '}')

This loop keeps processing pieces until the current group ends.

The important thing is that a comma means:

OR

For example:

{a,b,c}

means:

a OR b OR c

So the outer loop is basically:

piece 1
   ↓
put its answers into res

piece 2
   ↓
put its answers into res

piece 3
   ↓
put its answers into res

if(s[i] == ','){
    i++;
    continue;
}

A comma doesn't produce a word.

It just says:

"The previous alternative is finished. Move to the next alternative."

For:

{a,b}

we read:

a
,
b

The comma itself contributes nothing.

So we just move over it.

curr does not mean the whole expression.

It means:

The set of strings we have built so far for the current concatenation.

Why start with:

{""}

instead of {}?

Because the empty string is the identity for concatenation.

For example:

"" + "a" = "a"

So if the first component is {a,b}, starting with:

curr = {""}

lets us do:

"" + a = a
"" + b = b

and get:

curr = {"a","b"}

This makes the later logic uniform.

6. The inner while handles CONCATENATION

This is:

while(i < s.size() && s[i] != ',' && s[i] != '}')

This loop means:

Keep reading things that are next to each other.

Remember:

AB

in this grammar means:

concatenate A and B

For example:

{a,b}{c,d}

has two adjacent pieces:

{a,b}
{c,d}

The first inner iteration processes {a,b}.

The second inner iteration processes {c,d}.

Then we combine them.

So:

outer while = UNION
inner while = CONCATENATION

That is the key structural idea of the whole parser.

7. part = the next piece

Inside the inner loop:

set<string> part;

part means:

What can this one next component represent?

That component can be either:

a single letter
a brace expression
8. Case 1: the next thing is {...}
if(s[i] == '{'){
    i++;
    part = parse(s, i);
    i++;
}

Suppose we're at:

{a,b}
↑
i

We see {.

First:

i++;

Now:

a,b}
↑
i

We're inside the braces.

Then:

part = parse(s, i);

The recursive call processes:

a,b

and returns:

{"a","b"}

So now:

part = {"a","b"}
9. Why is there another i++?

This:

i++;

after the recursive call skips the closing:

}

The recursive parser stops when it sees }, but it does not consume it.

So when it returns:

a,b}
   ↑
   i

We need:

i++;

to move past }.

So the pattern is:

{     → i++       enter braces
...   → parse     parse contents
}     → i++       leave braces
10. Case 2: the next thing is just a letter
else{
    part.insert(string(1, s[i]));
    i++;
}

Suppose:

a
↑
i

Then:

string(1, s[i])

creates:

"a"

and:

part.insert(...)

makes:

part = {"a"}

Then:

i++;

moves to the next character.

So a single letter is treated as an expression with exactly one possibility.

11. Now comes the actual concatenation

After we know what part represents:

set<string> next;

We combine:

curr

with:

part

using:

for(string a : curr){
    for(string b : part){
        next.insert(a + b);
    }
}

This is the Cartesian product from the problem statement.

If:

curr = {"a","b"}
part = {"c","d"}

then we make:

a + c = ac
a + d = ad
b + c = bc
b + d = bd

So:

next = {"ac","ad","bc","bd"}

This is exactly what concatenation means in the grammar.

12. Why curr = next?

After combining the old possibilities with the new piece:

curr = next;

means:

We have now successfully incorporated this component. curr should represent the possibilities built so far.

For example:

initial:
curr = {""}

read {a,b}:
curr = {"a","b"}

read {c,d}:
curr = {"ac","ad","bc","bd"}

read e:
curr = {"ace","ade","bce","bde"}

So curr grows one component at a time.

13. When does one concatenation end?

The inner loop stops at:

s[i] == ','

or:

s[i] == '}'

That means:

We've finished the current concatenation expression.

For example:

{a,b}{c,d},x

While processing:

{a,b}{c,d}

the inner loop handles both adjacent pieces.

When it reaches:

,

it stops.

At that point:

curr = {"ac","ad","bc","bd"}

Those are one complete union branch.

14. Put that branch into res

Now:

for(string x : curr){
    res.insert(x);
}

This means:

Add all possibilities from the current branch into the overall union.

Suppose:

curr = {"ac","ad","bc","bd"}

Then:

res
= previous results ∪ curr

Because res is a set, duplicates disappear automatically.

15. Why there are TWO loops?

This is the most important structural insight.

Outer loop
while(...)

represents:

UNION
Inner loop
while(...)

represents:

CONCATENATION

So mentally:

           parse()
             |
      ┌──────┴──────┐
      |             |
    UNION      CONCATENATION
      |             |
  alternatives    pieces
16. Let's trace a real expression

Take:

{a,b}{c,{d,e}}

We want:

ac
ad
ae
bc
bd
be
First component
{a,b}

Recursive parsing gives:

part = {"a","b"}

curr started as:

{""}

So:

"" + a = a
"" + b = b

Now:

curr = {"a","b"}
Second component

Now we encounter:

{c,{d,e}}

Recursive parsing gives:

part = {"c","d","e"}

Now combine:

a + c = ac
a + d = ad
a + e = ae

b + c = bc
b + d = bd
b + e = be

So:

curr =
{
    "ac",
    "ad",
    "ae",
    "bc",
    "bd",
    "be"
}

There is no more concatenation.

So put all of curr into res.

Final:

res =
{
    "ac",
    "ad",
    "ae",
    "bc",
    "bd",
    "be"
}
17. What the recursion is really doing

Suppose you have:

{{a,z},a{b,c},{ab,z}}

The outer expression has three alternatives:

{a,z}
a{b,c}
{ab,z}

So the outer parser does:

branch 1 → {"a","z"}

branch 2 → {"ab","ac"}

branch 3 → {"ab","z"}

Then puts them all into res:

a
z
ab
ac
ab
z

Because res is a set:

{"a","ab","ac","z"}

Exactly the required answer.

18. What i is doing during all this

This deserves special attention.

i is shared by recursive calls because you have:

int& i

Imagine:

{a,{b,c}}
 ^
 i

The outer parser says:

"Okay, I found `{`. I'll let a recursive parser handle what's inside."

Recursive parser moves:

{ a , { b , c } }
  ↑

then:

{ a , { b , c } }
          ↑

then eventually stops at:

{ a , { b , c } }
              ↑
              }

and returns.

The outer parser resumes from exactly that position.

That's why passing i by reference is essential.

19. What is each variable conceptually?

You can memorize the roles like this:

res
 ↓
"all answers for this whole expression"

curr
 ↓
"all answers for the current concatenation so far"

part
 ↓
"all answers for the next piece"

next
 ↓
"result after concatenating curr with part"

i
 ↓
"where am I in the expression?"

That is much more useful than memorizing individual lines.

20. And finally, braceExpansionII()
vector<string> braceExpansionII(string expression) {
    int i = 0;
    set<string> st = parse(expression, i);

    return vector<string>(st.begin(), st.end());
}

This is just the entry point.

Start reading from:

i = 0

Then:

parse(expression, i)

returns the complete set.

Because set is already sorted:

vector<string>(st.begin(), st.end())

converts it into the required vector<string>.

---

---

*Generated by LeetSync v1.0.0 — 2026-09-25 15:57 UTC*