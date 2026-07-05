//  Binary Tree - Bottom View
//
// Problem:
// Given the root of a binary tree, return the bottom view of the binary tree.
// The bottom view contains the nodes that are visible when the tree is viewed
// from the bottom. If there are multiple nodes at the same horizontal distance,
// the node that is lower (appears later in level order traversal) is in the
// bottom view.
//
// Approach / Idea:
// Perform a level-order traversal (BFS) while tracking the horizontal distance
// (HD) of each node relative to the root (root HD = 0). For left child, HD-1;
// for right child, HD+1. Maintain an ordered map<int,int> from HD -> node value
// and overwrite the value on each visit. Because BFS visits nodes top-to-bottom,
// the last value written for a given HD will be the bottom-most node.
//
// Algorithm:
// 1. If root is null return empty vector.
// 2. Use queue<pair<TreeNode*,int>> for BFS (node, HD). Push root with HD=0.
// 3. While queue not empty: pop (node, hd), mp[hd] = node->val, push children
//    with hd-1 and hd+1 as appropriate.
// 4. Iterate ordered map from smallest HD to largest and append values to result.
//
// Time Complexity: O(N log M) -> O(N log N) worst-case where N = #nodes and M
// is number of distinct horizontal distances (map ops cost log M).
// Space Complexity: O(N) for queue + map.
//
// Example:
// Input:      20
//            /    \
//           8      22
//          / \       \
//         5   3       25
//            / \      \
//           10  14     
// Bottom view: 5 10 3 14 25

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
    // Keep the function name as bottomView to match other files.
    vector<int> bottomView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        // ordered map: hd -> bottom-most node value
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int hd = p.second;

            // overwrite to ensure we keep the bottom-most node seen so far
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
    // Construct the example tree:
    //      20
    //     /  \
    //    8   22
    //   / \    \
    //  5   3    25
    //     / \
    //    10 14
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right->right = new TreeNode(25);

    Solution sol;
    vector<int> out = sol.bottomView(root);

    for (int v : out) cout << v << " ";
    cout << '\n'; // Expected: 5 10 3 14 25

    return 0;
}
#endif
