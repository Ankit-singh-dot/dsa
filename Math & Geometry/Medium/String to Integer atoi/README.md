# String to Integer (atoi)

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | java |
| **Solved On** | September 1, 2026 |
| **Tags** | String |
| **Link** | [View Problem](https://leetcode.com/problems/string-to-integer-atoi/) |
| **Runtime** | 1 ms |
| **Memory** | 43.8 MB |

## Approach

wlkrg nklrgrwgwr

## Problem Description

<p>Implement the <code>myAtoi(string s)</code> function, which converts a string to a 32-bit signed integer.</p>

<p>The algorithm for <code>myAtoi(string s)</code> is as follows:</p>

<ol>
	<li><strong>Whitespace</strong>: Ignore any leading whitespace (<code>" "</code>).</li>
	<li><strong>Signedness</strong>: Determine the sign by checking if the next character is <code>'-'</code> or <code>'+'</code>, assuming positivity if neither present.</li>
	<li><strong>Conversion</strong>: Read the integer by skipping leading zeros&nbsp;until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.</li>
	<li><strong>Rounding</strong>: If the integer is out of the 32-bit signed integer range <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>, then round the integer to remain in the range. Specifically, integers less than <code>-2<sup>31</sup></code> should be rounded to <code>-2<sup>31</sup></code>, and integers greater than <code>2<sup>31</sup> - 1</code> should be rounded to <code>2<sup>31</sup> - 1</code>.</li>
</ol>

<p>Return the integer as the final result.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "42"</span></p>

<p><strong>Output:</strong> <span class="example-io">42</span></p>

<p><strong>Explanation:</strong></p>

<pre>The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "<u>42</u>" ("42" is read in)
           ^
</pre>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = " -042"</span></p>

<p><strong>Output:</strong> <span class="example-io">-42</span></p>

<p><strong>Explanation:</strong></p>

<pre>Step 1: "<u>   </u>-042" (leading whitespace is read and ignored)
            ^
Step 2: "   <u>-</u>042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -<u>042</u>" ("042" is read in, leading zeros ignored in the result)
               ^
</pre>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "1337c0d3"</span></p>

<p><strong>Output:</strong> <span class="example-io">1337</span></p>

<p><strong>Explanation:</strong></p>

<pre>Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "<u>1337</u>c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
</pre>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "0-1"</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<pre>Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "<u>0</u>-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
</pre>
</div>

<p><strong class="example">Example 5:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "words and 987"</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>Reading stops at the first non-digit character 'w'.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code> consists of English letters (lower-case and upper-case), digits (<code>0-9</code>), <code>' '</code>, <code>'+'</code>, <code>'-'</code>, and <code>'.'</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅ [JAVA / C++] : Simple | Pictorial Explanation | 32 bit int | Easy
**Author**: [@akshayaamar05](https://leetcode.com/akshayaamar05/)
**Upvotes**: 426 👍
**Link**: [View Original Post](https://leetcode.com/problems/string-to-integer-atoi/solutions/1402936/)

---

<img src = "https://assets.leetcode.com/users/images/de56766c-2376-41e3-bd34-8f6e762249ff_1642241065.7559516.jpeg" width = 100%>

<img src = "https://assets.leetcode.com/users/images/e632f7e8-9a2e-4416-a58d-85dbf2428473_1642242240.3520854.jpeg" width = 100%>

<u>**BASIC IDEA:**</u>

1. **Start traversing the provided string**(`str`)
2. **Skip all the leading white spaces**.  eg:   `"  -123456"  --> "-123456"`
3. **Check for sign cases**(+-). eg: `"-123456"`. If `+`, then set the variable(boolean) `isNegative` to `true` and if it\'s `-`, set `isNegative` to `false`
4. **Iterate over the next remaining characters and keep adding them in `result` by converting the digits**(in character form) **to integer form.** eg: `"-123456" --> -123456`, until the **non-digit character** is found.

<u>**NOTE:**</u> Logic is implemented in such a way that after performing above 3 steps, if it finds characters(English letters (lower-case and upper-case), digits (0-9), \' \', \'+\', \'-\', and \'.\') before the digit character, it will give output as 0(zero) eg: `"abc-123456" --> 0` and if it finds characters(English letters (lower-case and upper-case), digits (0-9), \' \', \'+\', \'-\', and \'.\')  after the digit characters, it will return the number eg: `"-123456abc" --> -123456`
<br>

**C++ / JAVA CODE:**
<iframe src="https://leetcode.com/playground/SkWRoqDm/shared" frameBorder="0" width="100%" height="1000"></iframe>


* **Let\'s understand what** 
`if(result > (Integer.MAX_VALUE / 10) || (result == (Integer.MAX_VALUE / 10) && digit > 7)){`
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;`
`}`
**means in <u>JAVA</u>? You will be able to figure out this statement easily for <u>C++</u> code too.**

	* `result > (Integer.MAX_VALUE / 10)` means:
	Suppose, 
	`result = 214748365`(9 digits)
	`Integer.MAX_VALUE = 2147483647`(10 digits) and `Integer.MAX_VALUE / 10 = 214748364`(9 digits)
	Here, it is clearly evident that `result > Integer.MAX_VALUE / 10`( i.e. 214748365 > 214748364) and if we try to add even 0(zero) in result `214748365`(9 digits), the number will become `2147483650`(10 digits) which is obviously greater than `2147483647(Integer.MAX_VALUE which is of 10 digits)`. So even before adding `0(zero) or any other digit`, we return the `Integer.MAX_VALUE` or `Integer.MIN_VALUE`, according to the sign case, in order <u>to avoid integer overflow.</u>


	* And, `result == (Integer.MAX_VALUE / 10) && digit > 7` means:
	Suppose, 
	`result = 214748364`(9 digits), and
	`Integer.MAX_VALUE / 10 = 214748364`(9 digits)
	Now, if the result is equal to the Integer.MAX_VALUE / 10 (214748364 == 214748364) and the digit is greater than 7 i.e. `digit > 7` and if we try to add 8(assume the digit greater than 7 to be 8) to the result, then the number will become `2147483648`(10 digits), which will result in integer overflow. So, even before adding the digit which is greater than 7, we return the `Integer.MAX_VALUE` or `Integer.MIN_VALUE`, according to the sign case,  <u>to avoid integer overflow.</u>

<hr>

**More optimized by using char and int variable in order to avoid calling charAt(index) and Integer.MAX_VALUE / 10 repeatedly**

**<u>Optimized C++ / JAVA CODE</u>**

<iframe src="https://leetcode.com/playground/mNLPE63o/shared" frameBorder="0" width="100%" height="800"></iframe>

**SUGGESTION:**
**In JAVA**, you can replace the following condition 
```
if(result > (Integer.MAX_VALUE / 10) || (result == (Integer.MAX_VALUE / 10) && digit > 7))
                return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
```
with
```
if(result > (Integer.MAX_VALUE - digit) / 10)
                return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
```

And, **In C++**, you can replace the following condition 
```
if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7))
                return isNegative ? INT_MIN : INT_MAX;
```
with
```
if(result > (INT_MAX - digit) / 10)
                return isNegative ? INT_MIN : INT_MAX;
```
<hr>

**COMPLEXITY:**
* **Time: O(n)**, where n is the length of String
* **Space: O(1)**, in-place

<u>**Refer to the following github repsitory for more leetcode solutions**</u>
https://github.com/Akshaya-Amar/LeetCodeSolutions


# **Please UPVOTE if you find the solution helpful :)**

</details>
