/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    bool check(TreeNode* root, long long min, long long max)
    {
        // ---------- BASE CASE ----------
        // Empty tree is always a valid BST
        if(root == NULL)
        {
            return true;
        }

        // ---------- INVALID NODE ----------
        // Current value must lie strictly between min and max
        if(root->val <= min || root->val >= max)
        {
            return false;
        }

        // ---------- LEFT SUBTREE ----------
        // Left subtree:
        // Same minimum
        // Current node becomes new maximum
        bool left = check(root->left, min, root->val);

        // ---------- RIGHT SUBTREE ----------
        // Right subtree:
        // Current node becomes new minimum
        // Same maximum
        bool right = check(root->right, root->val, max);

        // BST tabhi valid hogi jab dono subtrees valid ho
        return left && right;
    }

    bool isValidBST(TreeNode* root)
    {
        // Initially koi restrictions nahi hain
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
    