<h2>Binary Tree - Top View</h2><h3>Medium</h3><hr>

<p>Given the <code>root</code> of a binary tree, return the <strong>top view</strong> of the binary tree. The top view contains the nodes that are visible when the tree is viewed from above. If there are multiple nodes at the same horizontal distance, the node that appears first in level order traversal (the top-most) is included in the top view.</p>

<p><strong>Approach:</strong> Perform a breadth-first search (level-order traversal) while tracking the horizontal distance (HD) of each node relative to the root (root HD = 0). For the left child use HD-1 and for the right child use HD+1. Maintain an ordered mapping from HD to the first node value seen at that HD during BFS. Finally, output the values from the smallest HD to the largest HD.</p>

<hr>

<p><strong class="example">Example 1:</strong></p>
<pre>
Input:
     1
    / \
   2   3
    \   \
     4   5

Output: [2, 1, 3, 5]

Explanation: Top view from left to right is 2,1,3,5.
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
Input:
    1
   / \
  2   3
 /     \
4       5

Output: [4,2,1,3,5]
</pre>

<hr>

<p><strong>Constraints:</strong></p>
<ul>
<li>The number of nodes is in the range [0, 10^5].</li>
<li>-10^9 &lt;= Node.val &lt;= 10^9</li>
</ul>

<p>Notes: This is a BFS + horizontal-distance mapping problem closely related to top/right/left/bottom view variants.</p>
