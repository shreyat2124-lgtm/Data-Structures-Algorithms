/*
Problem: Bottom View of Binary Tree
Description:
Given the root of a binary tree, return the bottom view of the binary tree. The bottom view contains the nodes that are visible when the tree is viewed from the bottom. If there are multiple nodes at the same horizontal distance, the node that is lower (appears later in level order traversal) is in the bottom view.

Approach / Idea:
We perform a breadth-first search (level order traversal) while tracking the horizontal distance (HD) of each node from the root. The root has HD = 0; left child HD = parent HD - 1; right child HD = parent HD + 1.

Use a map<int,int> to keep the latest (bottom-most) node's value for every HD. Because BFS visits nodes top-to-bottom, overwriting the map entry for a given HD ensures the map stores the bottom-most node encountered at that HD.

Algorithm:
1. If the tree is empty, return an empty vector.
2. Initialize a queue<pair<Node*, int>> and push the root with HD = 0.
3. While the queue is not empty:
   - Pop the front node and its HD.
   - Overwrite mp[hd] with node->data.
   - If left child exists, push it with hd-1.
   - If right child exists, push it with hd+1.
4. Iterate the map from lowest HD to highest HD and append values to the answer vector.
5. Return the answer vector.

Time Complexity: O(N log M)
- N is the number of nodes. Each node is visited once in BFS (O(N)), and each map insertion/assignment is O(log M) where M is number of distinct horizontal distances (<= N). Overall O(N log N) in the worst case.

Space Complexity: O(N)
- Queue may hold up to O(N) nodes in the worst case. The map stores up to O(N) entries.

Structure / Notes:
- Node struct is provided for completeness; on some judge platforms a Node definition may already be given.
- The function name is `bottomView` and returns a vector<int> of node values from leftmost to rightmost bottom view.

*/

#include <bits/stdc++.h>
using namespace std;

// Binary Tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> bottomView(Node* root)
    {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        // map: horizontal distance -> bottom-most node's value
        map<int,int> mp;

        // queue of pairs: node pointer and its horizontal distance
        queue<pair<Node*,int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            // Overwrite: BFS ensures bottom-most node for this HD
            mp[hd] = node->data;

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // Collect results from leftmost HD to rightmost HD
        for (auto &p : mp)
            ans.push_back(p.second);

        return ans;
    }
};
