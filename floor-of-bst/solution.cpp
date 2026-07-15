/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Iterative approach: same idea as the snippet you provided.
    // Walk the tree: when node->val <= x it is a candidate for floor,
    // so record it and go right to try to find a larger candidate.
    // Otherwise go left.
    int floorInBST(TreeNode* root, int x) {
        int floor = -1; // return -1 when floor doesn't exist
        while (root != NULL) {
            if (root->val == x) return root->val; // perfect match
            if (root->val < x) {
                floor = root->val;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }

    // Recursive version: returns the floor value or -1 if none.
    int floorInBST_recursive(TreeNode* root, int x) {
        if (!root) return -1;
        if (root->val == x) return root->val;
        if (root->val > x) return floorInBST_recursive(root->left, x);
        int rightFloor = floorInBST_recursive(root->right, x);
        if (rightFloor != -1 && rightFloor <= x) return rightFloor;
        return root->val;
    }
};
