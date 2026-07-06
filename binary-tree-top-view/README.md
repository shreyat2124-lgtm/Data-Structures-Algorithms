<h2>Binary Tree - Top View</h2><h3>Medium</h3><hr>

<p>Given the <code>root</code> of a binary tree, return the <strong>top view</strong> of the binary tree. The top view contains the nodes that are visible when the tree is viewed from the top. If there are multiple nodes at the same horizontal distance, the node that appears first in level order traversal (i.e., highest) is included in the top view.</p>

<p><strong>Approach:</strong> Perform a breadth-first search (level-order traversal) while tracking the horizontal distance (HD) of each node relative to the root (root HD = 0). For the left child use HD-1 and for the right child use HD+1. Maintain an ordered mapping from HD to the first node value seen at that HD during BFS. Because BFS visits nodes level-by-level, storing the first node encountered per HD yields the top-most node for that horizontal distance. Finally, output the values from the smallest HD to the largest HD.</p>

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

Explanation: When viewed from the top, the nodes visible from left to right are 2, 1, 3, 5.
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

Explanation: A wider tree's top view includes the leftmost and rightmost nodes at distinct horizontal distances.
</pre>

<hr>

<p><strong>Algorithm / Implementation notes:</strong></p>
<ul>
<li>Use a queue of pairs (node pointer, horizontal distance) to perform BFS.</li>
<li>Use an ordered map<int,int> (or unordered_map + track min/max HD) to map horizontal distance -> first-seen node value. Only insert into the map when a horizontal distance is seen the first time.</li>
<li>After BFS finishes, iterate the ordered map from smallest HD to largest HD and collect the stored values to form the top view from left to right.</li>
</ul>

<hr>

<p><strong>Complexity:</strong></p>
<ul>
<li>Time: O(N log M) — where N is the number of nodes and M is the number of distinct horizontal distances (map operations cost O(log M)). In practice M ≤ N, so O(N log N) worst-case. Using an unordered_map with tracking of min/max HD can give expected O(N).</li>
<li>Space: O(N) — queue and map/storage may hold up to O(N) elements in the worst case.</li>
</ul>

<hr>

<p><strong>Constraints:</strong></p>
<ul>
<li>The number of nodes in the tree is in the range [0, 10^5].</li>
<li>-10^9 &lt;= Node.val &lt;= 10^9</li>
</ul>

<p>References: This problem is commonly asked in tree and BFS/level-order traversal topics and is solved with a horizontal-distance mapping technique similar to other view problems (top, bottom, left, right).</p>
