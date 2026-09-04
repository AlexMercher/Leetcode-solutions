# 4. Median of Two Sorted Arrays

---

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)  ![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

---

## Problem

https://leetcode.com/problems/median-of-two-sorted-arrays/

---

## Language

C++

---

## Explanation

This solution uses binary search on the smaller array to find the correct partition between the two sorted arrays.

Core idea

Suppose we have:

nums1 = [1, 3]
nums2 = [2, 4, 5, 6]

Combined:

[1, 2, 3, 4, 5, 6]

We don't actually need to merge them. Instead, we divide both arrays into a left half and a right half such that:

The left half contains exactly half of all elements.
Every element in the left half is ≤ every element in the right half.

For example:

nums1: [1 | 3]
nums2: [2, 4 | 5, 6]
             ↑

The elements on the left are:

[1, 2, 4]

and on the right:

[3, 5, 6]

For an even number of elements, the median is:

(max element on left + min element on right) / 2
1. Always binary-search the smaller array
if(nums1.size()>nums2.size()){
    return findMedianSortedArrays(nums2,nums1);
}

This is important because the binary search runs from 0 to m, where m is the size of nums1.

So we want:

m <= n

This gives a time complexity of:

O(log(min(m,n)))
2. Set up the binary search
int m=nums1.size();
int n=nums2.size();
int low=0;
int high=m;

We're searching for the correct partition position in nums1.

If:

partitionX = 2

then:

nums1[0], nums1[1]

are on the left, and:

nums1[2], nums1[3], ...

are on the right.

3. Calculate both partitions
int partitionX=(low+high)/2;
int partitionY=(m+n+1)/2-partitionX;

The total number of elements on the left must be:

(m + n + 1) / 2

So if partitionX elements come from nums1, then the remaining elements must come from nums2:

partitionY = totalLeft - partitionX

The +1 makes the formula work conveniently for both odd and even lengths.

4. Find the four important boundary values
int maxleftX=(partitionX==0)? INT_MIN:nums1[partitionX-1];
int minRightX=(partitionX==m)? INT_MAX:nums1[partitionX];

int maxleftY=(partitionY==0)? INT_MIN:nums2[partitionY-1];
int minRightY=(partitionY==n)? INT_MAX:nums2[partitionY];

We only care about the elements immediately around the partitions.

They look like this:

nums1: ... maxleftX | minRightX ...
nums2: ... maxleftY | minRightY ...

For example:

nums1 = [1, 3 | 8]
             ↑
nums2 = [2, 4 | 5, 6]
             ↑

Then:

maxleftX  = 3
minRightX = 8

maxleftY  = 4
minRightY = 5

INT_MIN and INT_MAX handle cases where the partition is at the beginning or end of an array.

5. Check whether the partition is correct
if(maxleftX<=minRightY && maxleftY<=minRightX)

These are the two conditions we need:

maxleftX <= minRightY
maxleftY <= minRightX

Why?

Because every element in the left side must be ≤ every element in the right side.

Since each individual array is already sorted, we only need to compare the two boundary elements.

If both conditions are true, we've found the correct partition.

6. Find the median
Odd total length
if((m+n)%2==1){
    return max(maxleftX,maxleftY);
}

If the total number of elements is odd, the median is the largest element on the left.

For example:

[1, 2, 3 | 4, 5]

The median is:

3

Therefore:

max(maxleftX, maxleftY)
Even total length
return (max(maxleftX,maxleftY)+min(minRightX,minRightY))/2.0;

For an even number of elements:

[1, 2, 3 | 4, 5, 6]

The two middle elements are:

3 and 4

So:

median = (3 + 4) / 2 = 3.5

That's why we calculate:

(max(left) + min(right)) / 2.0

Using 2.0 ensures floating-point division.

7. Adjust the binary search

If:

maxleftX > minRightY

then we've taken too many elements from nums1.

high=partitionX-1;

We move the partition in nums1 to the left.

Otherwise:

low=partitionX+1;

This means we've taken too few elements from nums1, so we move the partition to the right.

Example

Consider:

nums1 = [1, 3]
nums2 = [2, 4, 5]

Total = 5, so we need 3 elements on the left.

Suppose:

partitionX = 1
partitionY = 2

The partition becomes:

nums1: [1 | 3]
nums2: [2, 4 | 5]

Therefore:

maxleftX  = 1
minRightX = 3

maxleftY  = 4
minRightY = 5

Check:

1 <= 5   ✓
4 <= 3   ✗

So the partition is wrong.

Since:

maxleftY > minRightX

we need more elements from nums1:

partitionX++

Eventually:

nums1: [1, 3 |]
nums2: [2 | 4, 5]

Now:

maxleftX = 3
minRightX = INT_MAX

maxleftY = 2
minRightY = 4

Both conditions hold:

3 <= 4
2 <= INT_MAX

Total length is odd, so:

median = max(3, 2) = 3
Complexity

Let:

m = nums1.size()
n = nums2.size()

Because the smaller array is binary-searched:

Time:

O(log(min(m,n)))

Space:

O(1)

No merged array is created.

In one sentence

The algorithm binary-searches for a partition in the smaller sorted array such that the combined left half contains half the elements and every left-side element is ≤ every right-side element; the median then comes directly from the two partition boundaries.

---

## My Notes

Could not think of this needed the help of gpt for this one.

---

---

*Generated by LeetSync v1.0.0 — 2026-09-04 06:09 UTC*