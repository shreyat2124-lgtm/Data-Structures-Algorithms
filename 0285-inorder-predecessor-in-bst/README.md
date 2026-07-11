<h2><a href="https://leetcode.com/problems/inorder-predecessor-in-bst">285. Inorder Predecessor in BST</a></h2><h3>Medium</h3><hr><p>Given the <code>root</code> of a binary search tree and a node <code>p</code> in it, return <em>the in-order predecessor of that node in the BST</em>. If the given node has no in-order predecessor in the tree, return <code>null</code>.</p>

<p>The predecessor of a node <code>p</code> is the node with the largest key smaller than <code>p.val</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_1.PNG" style="width: 200px; height: 200px;" />
<pre>
<strong>Input:</strong> root = [2,1,3], p = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The in-order predecessor of node 3 is node 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_2.PNG" style="width: 253px; height: 200px;" />
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,null,1], p = 1
<strong>Output:</strong> null
<strong>Explanation:</strong> There is no in-order predecessor of node 1, so we return <code>null</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>All Nodes will have unique values.</li>
</ul>
