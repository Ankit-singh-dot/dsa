# Find the Duplicate Number

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 31, 2026 |
| **Tags** | Array, Two Pointers, Binary Search, Bit Manipulation, Pigeonhole Principle, Floyd's Cycle Finding Algorithm |
| **Link** | [View Problem](https://leetcode.com/problems/find-the-duplicate-number/) |
| **Runtime** | 0 ms |
| **Memory** | 64.9 MB |

## Problem Description

<p>Given an array of integers <code>nums</code> containing&nbsp;<code>n + 1</code> integers where each integer is in the range <code>[1, n]</code> inclusive.</p>

<p>There is only <strong>one repeated number</strong> in <code>nums</code>, return <em>this&nbsp;repeated&nbsp;number</em>.</p>

<p>You must solve the problem <strong>without</strong> modifying the array <code>nums</code>&nbsp;and using only constant extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,4,2,2]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,3,4,2]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3,3,3,3]
<strong>Output:</strong> 3</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n + 1</code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li>All the integers in <code>nums</code> appear only <strong>once</strong> except for <strong>precisely one integer</strong> which appears <strong>two or more</strong> times.</li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b></p>

<ul>
	<li>How can we prove that at least one duplicate number must exist in <code>nums</code>?</li>
	<li>Can you solve the problem in linear runtime complexity?</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++🔥2 optimal Approaches🔥O(n) and O(nlogn)🔥constant space
**Author**: [@ribhav_32](https://leetcode.com/ribhav_32/)
**Upvotes**: 458 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-the-duplicate-number/solutions/4916414/)

---

# **PLEASE UPVOTE\uD83D\uDC4D**
![b772cc9a-b8c8-45ab-941f-ac36c1900ea2_1696303869.2008665.png](https://assets.leetcode.com/users/images/5834d094-01ae-4508-8795-0703cee8e5b8_1711243639.7934008.png)

# Approach 1: Binary Search

- ##### Since the numbers in the array are in the range [1, n] and there\'s only one repeated number, we can use binary search to find the duplicate number.
- ##### We perform binary search on the range [1, n], and for each mid value, we count the number of elements in the array that are less than or equal to the mid value.
- ##### If the count is greater than mid, then the duplicate lies in the left half of the range; otherwise, it lies in the right half.
- ##### If there\'s no duplicate, in a sorted array, we would expect nums[i] to be equal to i + 1 for each i. However, with a duplicate, there will be more than i + 1 numbers less than or equal to mid.
- ##### We continue narrowing down the range until we find the duplicate number.

## Complexity
- Time complexity: O(NlogN)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

## Code
```
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            // Count the numbers less than or equal to mid
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            // If count is greater than mid, the duplicate lies in the left half
            if (count > mid) {
                right = mid;
            } else { // Otherwise, it lies in the right half
                left = mid + 1;
            }
        }

        return left;
    }
};

```

# Approach 2: Slow and fast pointer
- ##### The key intuition behind this method is that if there\'s a cycle in the linked list, the fast and slow pointers will eventually meet.
- ##### We treat the array as a linked list, where the index represents the node and the value at that index represents the next node.
- ##### Using the fast-slow pointers technique, we traverse the linked list.
- ##### The slow pointer moves one step at a time while the fast pointer moves two steps at a time.
- ##### If there\'s a cycle in the linked list (indicating a duplicate number), the fast and slow pointers will eventually meet.
- ##### After identifying the meeting point, we reset the slow pointer to the start and move both pointers at the same pace until they meet again. The meeting point will be the duplicate number.

## Complexity
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

## Code
```
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

```

![image.png](https://assets.leetcode.com/users/images/41086303-e477-44e0-b45b-2dca854a7a5e_1711243439.4241164.png)



</details>
