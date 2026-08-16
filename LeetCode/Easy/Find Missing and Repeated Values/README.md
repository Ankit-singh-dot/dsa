# Find Missing and Repeated Values

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | August 16, 2026 |
| **Tags** | Array, Hash Table, Math, Matrix |
| **Link** | [View Problem](https://leetcode.com/problems/find-missing-and-repeated-values/) |
| **Runtime** | 0 ms |
| **Memory** | 26.8 MB |

## Approach

 int repeating = -1 , missing = -1 ;
        for(int i= 1 ; i <= n*n ; i++){
            if(hash[i] == 2 ){
                repeating = i ;
            } else if(hash[i] == 0){
                missing = i ;
            }
            if(repeating != -1 && missing != -1){
                break ;
            }
        }
        return {repeating , missing} ;
    }


please do revise it man 

## Problem Description

<p>You are given a <strong>0-indexed</strong> 2D integer matrix <code><font face="monospace">grid</font></code> of size <code>n * n</code> with values in the range <code>[1, n<sup>2</sup>]</code>. Each integer appears <strong>exactly once</strong> except <code>a</code> which appears <strong>twice</strong> and <code>b</code> which is <strong>missing</strong>. The task is to find the repeating and missing numbers <code>a</code> and <code>b</code>.</p>

<p>Return <em>a <strong>0-indexed </strong>integer array </em><code>ans</code><em> of size </em><code>2</code><em> where </em><code>ans[0]</code><em> equals to </em><code>a</code><em> and </em><code>ans[1]</code><em> equals to </em><code>b</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[1,3],[2,2]]
<strong>Output:</strong> [2,4]
<strong>Explanation:</strong> Number 2 is repeated and number 4 is missing so the answer is [2,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[9,1,7],[8,9,2],[3,4,6]]
<strong>Output:</strong> [9,5]
<strong>Explanation:</strong> Number 9 is repeated and number 5 is missing so the answer is [9,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == grid.length == grid[i].length &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= n * n</code></li>
	<li>For all <code>x</code> that <code>1 &lt;= x &lt;= n * n</code> there is exactly one <code>x</code> that is not equal to any of the grid members.</li>
	<li>For all <code>x</code> that <code>1 &lt;= x &lt;= n * n</code> there is exactly one <code>x</code> that is equal to exactly two of the grid members.</li>
	<li>For all <code>x</code> that <code>1 &lt;= x &lt;= n * n</code> except two of them there is exactly one pair of <code>i, j</code> that <code>0 &lt;= i, j &lt;= n - 1</code> and <code>grid[i][j] == x</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Explained - Two approach - Using hash map & using math
**Author**: [@kreakEmp](https://leetcode.com/kreakEmp/)
**Upvotes**: 16 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-missing-and-repeated-values/solutions/4419249/)

---


# Approach 1 (Using hash map) : 
- Basically we count frequency of each item using hash map and then simply check from 1 to n^2 which number is has frequency 2 and which has frequency 0. Return that as answer

### Complexity
- Time complexity: O(n x n)
- Space complexity: O(n x n)
### C++
```
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_map<int, int> freq;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid.size(); ++j){
            freq[grid[i][j]]++;
        }
    }
    int repeat = 0, miss = 0, n = grid.size() * grid.size();
    for(int i = 1; i <= n; ++i){
        if(freq[i] == 2) repeat = i;
        if(freq[i] == 0) miss = i;
    }
    return {repeat, miss};
}
```


# Approach 2 (Using Math) : 
- Here we take sume of all element and equate that to sum of 1 to n^2
- Again we take sum of the square of the numbers and equate that to sum of square of 1 to n^2
- So we will get two equation and we have two variables a(repeated) & b(missing)
- Here we will get two equations with a & b. Now solving them we will get following result :
 a = (c2/c1 + c1)/2   b = (c2/c1 - c1)/2
 where 
    - c1 = (sum of n^2 given numbers) - sum of first n^2 natiural numbers
    - c2 = (sum of square of n^2 given numbers) - sum of first n^2 natural numbers
      

### Complexity
- Time complexity: O(n x n)
- Space complexity: O(1)
- 
### C++
```
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    long long sum = 0, sqrSum = 0, n = grid.size(), N = n*n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            sum += grid[i][j];
            sqrSum += grid[i][j] * grid[i][j];
        }
    }
    long long c1 = sum - N * (N + 1)/2,  c2 = sqrSum - N*(N+1)*(2*N + 1)/6;
    return {(int)(c2/c1 + c1)/2, (int)(c2/c1 - c1)/2};
}
```

### Java
```
public int[] findMissingAndRepeatedValues(int[][] grid) {
    long sum = 0, sqrSum = 0, n = grid.length, N = n*n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            sum += grid[i][j];
            sqrSum += grid[i][j] * grid[i][j];
        }
    }
    long c1 = sum - N * (N + 1)/2,  c2 = sqrSum - N*(N+1)*(2*N + 1)/6;
    return new int[]{(int)(c2/c1 + c1)/2, (int)(c2/c1 - c1)/2};
}
```


---

<b>Here is an article of my last interview experience - A Journey to FAANG Company, I recomand you to go through this to know which all resources I have used & how I cracked interview at Amazon:
https://leetcode.com/discuss/interview-experience/3171859/Journey-to-a-FAANG-Company-Amazon-or-SDE2-(L5)-or-Bangalore-or-Oct-2022-Accepted

---



</details>
