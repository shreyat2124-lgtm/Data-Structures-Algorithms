<h2>Binary Tree - Bottom View</h2><h3>Medium</h3><hr>

<p>Given the <code>root</code> of a binary tree, return the <strong>bottom view</strong> of the binary tree. The bottom view contains the nodes that are visible when the tree is viewed from the bottom. If there are multiple nodes at the same horizontal distance, the node that is lower (appears later in level order traversal) is included in the bottom view.</p>

<p><strong>Approach:</strong> Perform a breadth-first search (level-order traversal) while tracking the horizontal distance (HD) of each node relative to the root (root HD = 0). For the left child use HD-1 and for the right child use HD+1. Maintain an ordered mapping from HD to the last node value seen at that HD during BFS. Finally, output the values from the smallest HD to the largest HD.</p>

<hr>

<p><strong class="example">Example 1:</strong></p>
<pre>
Input:
   20
  /  \
 8   22
/ \    \
5  3    25
  / \
 10 14

Output: [5, 10, 3, 14, 25]

Explanation: When viewed from the bottom, the nodes visible from left to right are 5, 10, 3, 14, 25.
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
Input:
    1
     \
      2
       \
        3

Output: [1,2,3]

Explanation: A right-skewed tree's bottom view is all nodes in order.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
<li>The number of nodes in the tree is in the range [0, 10^5].</li>
<li>-10^9 &lt;= Node.val &lt;= 10^9</li>
</ul>

<p>References: This problem is commonly asked in tree and BFS/level-order traversal topics where horizontal distance mapping is used to derive views (top/left/right/bottom) of a binary tree.</p>
