# 467. Unique Substrings in Wraparound String

---

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/unique-substrings-in-wraparound-string/

---

## Language

C++

---

## Explanation

if(i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1) {
    len++;
}
else {
    len = 1;
}

Let's break it down piece by piece.

1. What are we trying to detect?

The infinite wraparound string is:

abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz...

So the only valid consecutive transitions are:

a → b
b → c
c → d
...
y → z
z → a

That means when we are at:

s[i]

we want to know:

Is s[i] exactly the next character after s[i-1] in the wraparound alphabet?

If yes, the current valid substring can be extended.

If no, we must start a new valid substring from s[i].

That is exactly what:

len++

versus:

len = 1

is doing.

2. First understand character subtraction

In C++, characters have integer values.

For lowercase English letters, their values are consecutive in the character encoding:

'a' = 97
'b' = 98
'c' = 99
...
'z' = 122

So:

'b' - 'a'

is:

98 - 97 = 1

and:

'c' - 'b'

is also:

99 - 98 = 1

Therefore for normal alphabet transitions:

s[i] - s[i-1] == 1

means:

previous → current

is consecutive.

For example:

a → b

gives:

'b' - 'a' = 1

while:

c → f

gives:

'f' - 'c' = 3

so that is not valid.

3. But there is a problem with z → a

This is the interesting part.

For:

z → a

character arithmetic gives:

'a' - 'z'

which is:

97 - 122 = -25

But in our circular alphabet, we want this transition to be treated as:

+1

because:

z → a

is exactly one step forward around the circle.

So we need a way to turn:

-25

into:

1

That's where:

+26

comes from.

4. Why +26?

Consider:

'a' - 'z'

which is:

-25

Add 26:

-25 + 26 = 1

Now:

('a' - 'z' + 26)

becomes:

1

Then:

1 % 26 = 1

So:

('a' - 'z' + 26) % 26 == 1

is true.

That means:

z → a

gets recognized as a valid transition.

5. Why % 26?

We have 26 letters, and the alphabet is circular.

The expression:

(s[i] - s[i-1] + 26) % 26

essentially calculates:

the forward distance between the two letters on a circular alphabet.

Let's see it.

a → b
'b' - 'a' = 1
1 + 26 = 27
27 % 26 = 1

Result:

1
b → c
'c' - 'b' = 1
1 + 26 = 27
27 % 26 = 1

Result:

1
y → z
'z' - 'y' = 1
1 + 26 = 27
27 % 26 = 1

Result:

1
z → a
'a' - 'z' = -25
-25 + 26 = 1
1 % 26 = 1

Result:

1

So all four are correctly identified.

6. Why are other transitions rejected?

Let's say:

c → e

Then:

'e' - 'c' = 2

So:

(2 + 26) % 26 = 2

Not 1.

Therefore:

if(... == 1)

is false.

So we do:

len = 1;

because the current character e must start a new valid substring.

7. What exactly is len?

This is very important.

len

means:

the length of the longest valid wraparound substring ending at s[i].

Not:

the length of the entire current stretch somewhere in the array.

It specifically describes the best valid substring ending at the current character.

8. Why len++?

Suppose:

s = "abcd"

At d, we have:

a → b → c → d

All transitions are valid.

Let's process it.

a

There is no previous character:

i = 0

So:

i > 0

is false.

Therefore:

len = 1;

Meaning:

longest valid substring ending at a = "a"
length = 1
b

Check:

b - a = 1

valid.

Therefore:

len++;

so:

len = 2

Meaning:

"ab"

is the longest valid substring ending at b.

c

Again:

c - b = 1

valid.

So:

len = 3

representing:

"abc"
d

Again:

d - c = 1

so:

len = 4

representing:

"abcd"
9. Why len = 1 when the transition fails?

Suppose:

s = "abx"

Process:

a → b → x

For:

a → b

valid:

len = 2

Now:

b → x

difference:

'x' - 'b' = 22

not 1.

So "abx" is not a valid wraparound substring.

But can x itself be a valid substring?

Yes:

"x"

Every single character is trivially present in base.

Therefore:

len = 1;

We restart the valid run from the current character.

This is exactly the same kind of idea as many "current valid run" problems:

valid extension?
    ↓
yes → extend current run

no
    ↓
current character starts a new run
10. Why do we need i > 0?

Because when:

i = 0

there is no:

s[i - 1]

i - 1 would be:

-1

which is outside the string.

So:

i > 0 &&

protects us from accessing the previous character when we're at the first character.

The && operator is evaluated left-to-right and uses short-circuit evaluation.

So:

i > 0 && ...

means:

Is there a previous character?
    ↓
NO → don't evaluate the second part
YES → evaluate the second part

This prevents an out-of-bounds access.

11. Put the entire condition into English

This:

(i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1)

means:

"There is a previous character, and the current character is exactly one step after the previous character in the circular alphabet."

If true:

len++;

meaning:

Extend the current valid substring.

If false:

len = 1;

meaning:

The current character cannot extend the previous valid substring, so start a new one here.

12. Let's do zab

This is the best example because it demonstrates the wraparound.

s = "zab"
i = 0
z

No previous character:

len = 1
i = 1

Current:

a

Previous:

z

Compute:

'a' - 'z'
= -25

-25 + 26
= 1

1 % 26
= 1

So:

len++;

and:

len = 2

This represents:

"za"
i = 2

Current:

b

Previous:

a

Compute:

'b' - 'a'
= 1

1 + 26
= 27

27 % 26
= 1

So:

len = 3

representing:

"zab"

Perfect.

13. Why can we then do maxLen[s[i]-'a'] = max(...)?

Suppose:

s = "zab"

we obtain:

at z → len = 1
at a → len = 2
at b → len = 3

So:

maxLen[z] = 1
maxLen[a] = 2
maxLen[b] = 3

Now think about all valid substrings ending in b:

"b"
"ab"
"zab"

There are exactly 3.

And that is why storing:

maxLen['b'] = 3

is enough to count all of them.

14. The formula is essentially circular distance

A useful mathematical interpretation is:

(s[i] - s[i-1] + 26) % 26

is the distance:

previous character → current character

on a circle of size 26.

For example:

a → b = 1
b → c = 1
...
y → z = 1
z → a = 1

a → c = 2
a → z = 25
z → b = 2

Only distance 1 is a valid wraparound step.

So:

== 1

is the whole validity condition.

15. A simpler equivalent condition

Because we're dealing only with lowercase English letters, you could also write:

if(i > 0 &&
   (s[i] == s[i-1] + 1 ||
    (s[i-1] == 'z' && s[i] == 'a')))

This directly says:

current = previous + 1
OR
previous = z and current = a

That is easier to read initially.

The modulo version:

(s[i] - s[i-1] + 26) % 26 == 1

is more general and elegant because it treats the alphabet as a circular numeric system.

---

## My Notes

😭

---

---

*Generated by LeetSync v1.0.0 — 2026-09-03 17:04 UTC*