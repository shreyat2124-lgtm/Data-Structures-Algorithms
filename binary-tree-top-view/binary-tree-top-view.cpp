//  Binary Tree - Top View
//
// Problem:
// Given the root of a binary tree, return the top view of the binary tree.
// The top view contains the nodes that are visible when the tree is viewed
// from the top. If there are multiple nodes at the same horizontal distance,
// the node that appears first in level order traversal (i.e., highest) is in
// the top view.
//
// Approach / Idea:
// Perform a level-order traversal (BFS) while tracking the horizontal distance
// (HD) of each node relative to the root (root HD = 0). For the left child use
// HD-1; for the right child use HD+1. Maintain an ordered map<int,int> from
// HD -> first-seen node value; during BFS only set the map entry if the HD
// hasn't been seen before. Finally, output values from smallest HD to largest HD.
//
// Algorithm:
// 1. If root is null return empty vector.
// 2. Use queue<pair<TreeNode*,int>> for BFS (node, HD). Push root with HD=0.
// 3. While queue not empty: pop (node, hd). If mp.find(hd) == mp.end() then
//    mp[hd] = node->val. Push children with hd-1 and hd+1 as appropriate.
// 4. Iterate ordered map from smallest HD to largest and append values to result.
//
// Time Complexity: O(N log M) -> O(N log N) worst-case where N = #nodes and M
// is number of distinct horizontal distances (map ops cost log M).
// Space Complexity: O(N) for queue + map.
//
// Example:
// Input:
//      1
//     / \
//    2   3
//     \   \
//      4   5
// Top view: 2 1 3 5

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node (LeetHub / LeetCode style).
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int,int> mp; // hd -> first-seen (top-most) node value
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int hd = p.second;

            // store only first node seen at this HD (top-most)
            if (mp.find(hd) == mp.end())
                mp[hd] = node->val;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto &it : mp) ans.push_back(it.second);
        return ans;
    }
};

// --- Sample main() with testcases ---
#ifdef LOCAL_TEST
int main() {
    // Construct example tree:
    //      1
    //     / \
    //    2   3
    //     \   \
    //      4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    vector<int> out = sol.topView(root);

    for (int v : out) cout << v << " ";
    cout << '\n'; // Expected: 2 1 3 5

    return 0;
}
#endif
