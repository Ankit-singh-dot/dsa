# Binary Tree Zigzag Level Order Traversal

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 8, 2026 |
| **Tags** | Tree, Breadth-First Search, Binary Tree |
| **Link** | [View Problem](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) |
| **Runtime** | 0 ms |
| **Memory** | 15 MB |

## Approach

testing shit 

## Problem Description

<p>Given the <code>root</code> of a binary tree, return <em>the zigzag level order traversal of its nodes' values</em>. (i.e., from left to right, then right to left for the next level and alternate between).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;">
<pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[20,9],[15,7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [c++] 5ms version: one queue and without reverse operation by using size of each level
**Author**: [@StevenCooks](https://leetcode.com/StevenCooks/)
**Upvotes**: 490 👍
**Link**: [View Original Post](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solutions/33825/)

---

  
Assuming after traversing the 1st level, nodes in queue are {9, 20, 8}, And we are going to traverse 2nd level, which is even line and should print value from right to left [8, 20, 9]. 

We know there are 3 nodes in current queue, so the vector for this level in final result should be of size 3. 
Then,     queue [i] -> goes to ->  vector[queue.size() - 1 - i]
i.e. the ith node in current queue should be placed in (queue.size() - 1 - i) position in vector for that line.
 
For example, for node(9), it's index in queue is 0, so its index in vector should be (3-1-0) = 2. 


    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int> > ();
        }
        vector<vector<int> > result;
    
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
    
        while ( !nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }

</details>
