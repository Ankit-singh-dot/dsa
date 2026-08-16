# Merge Intervals

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 16, 2026 |
| **Tags** | Array, Sorting, Quicksort |
| **Link** | [View Problem](https://leetcode.com/problems/merge-intervals/) |
| **Runtime** | 0 ms |
| **Memory** | 8.4 MB |

## Approach

easy _ tho pahele target kr rahe hai bada ahi toh interval he andar le lo agar chota hia toh merage kr lo maxium use kr ke 

## Problem Description

<p>Given an array&nbsp;of <code>intervals</code>&nbsp;where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, merge all overlapping intervals, and return <em>an array of the non-overlapping intervals that cover all the intervals in the input</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>Output:</strong> [[1,6],[8,10],[15,18]]
<strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,4],[4,5]]
<strong>Output:</strong> [[1,5]]
<strong>Explanation:</strong> Intervals [1,4] and [4,5] are considered overlapping.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> intervals = [[4,7],[1,4]]
<strong>Output:</strong> [[1,7]]
<strong>Explanation:</strong> Intervals [1,4] and [4,7] are considered overlapping.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Solution
**Author**: [@deleted_user](https://leetcode.com/deleted_user/)
**Upvotes**: 526 👍
**Link**: [View Original Post](https://leetcode.com/problems/merge-intervals/solutions/3161191/)

---

```C++ []
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
      if(intervals.size()==1)
         return intervals;
      vector<pair<int,int>> p;
      for(int i=0;i<intervals.size();i++)
      {
          p.push_back({intervals[i][0],intervals[i][1]});
      } 
      sort(p.begin(),p.end());

      vector<vector<int>> ans;
      int f=p[0].first,s=p[0].second;
      for(int i=0;i<p.size()-1;i++)
      {
          vector<int> a(2);
          if(s>=p[i+1].first)
          {
              s=max(s,p[i+1].second);
          }
          else
          {
              a[0]=f;
              a[1]=s;
              f=p[i+1].first;
              s=p[i+1].second;
              ans.push_back(a);
          }
      } 
      int n=intervals.size();
      ans.push_back({f,s});
      return ans;
    }
};
```

```Python3 []
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x [0])

        ans = []

        for interval in intervals:
            if not ans or ans[-1][1] < interval[0]:
                ans.append(interval)
            else:
                ans[-1][1] = max(ans[-1][1], interval[1])
        
        return ans
```

```Java []
class Solution {
    public int[][] merge(int[][] intervals) {
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		
		for (int i = 0; i < intervals.length; i++) {
			min = Math.min(min, intervals[i][0]);
			max = Math.max(max, intervals[i][0]);
		}
		
		int[] range = new int[max - min + 1];
		for (int i = 0; i < intervals.length; i++) {
			range[intervals[i][0] - min] = Math.max(intervals[i][1] - min, range[intervals[i][0] - min]); 
		}
		
		int start = 0, end = 0;
		LinkedList<int[]> result = new LinkedList<>();
		for (int i = 0; i < range.length; i++) {
			if (range[i] == 0) {
				continue;
			}
			if (i <= end) {
				end = Math.max(range[i], end);
			} else {
				result.add(new int[] {start + min, end + min});
				start = i;
				end = range[i];
			}
		}
		result.add(new int[] {start + min, end + min});
		return result.toArray(new int[result.size()][]);
	}
}
```


</details>
