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
    // Iterative approach for ceil in BST.
    // When node->val >= x it's a candidate for ceil,
    // so record it and go left to try to find a smaller candidate.
    // Otherwise go right.
    int ceilInBST(TreeNode* root, int x) {
        int ceil = -1; // return -1 when ceil doesn't exist
        while (root != NULL) {
            if (root->val == x) return root->val; // perfect match
            if (root->val > x) {
                ceil = root->val;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ceil;
    }

    // Recursive version: returns the ceil value or -1 if none.
    int ceilInBST_recursive(TreeNode* root, int x) {
        if (!root) return -1;
        if (root->val == x) return root->val;
        if (root->val < x) return ceilInBST_recursive(root->right, x);
        int leftCeil = ceilInBST_recursive(root->left, x);
        if (leftCeil != -1 && leftCeil >= x) return leftCeil;
        return root->val;
    }
};
