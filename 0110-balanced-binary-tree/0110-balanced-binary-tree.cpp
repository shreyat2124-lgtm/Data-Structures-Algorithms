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
    bool isBalanced(TreeNode* root)
    {
        // Agar -1 nahi aaya, tree balanced hai
        return height(root) != -1;
    }

    int height(TreeNode* root)
    {
        // Empty tree ki height 0
        if(root == NULL)
        {
            return 0;
        }

        // Left subtree ki height
        int lh = height(root->left);

        // Left subtree already unbalanced hai
        if(lh == -1)
        {
            return -1;
        }

        // Right subtree ki height
        int rh = height(root->right);

        // Right subtree already unbalanced hai
        if(rh == -1)
        {
            return -1;
        }

        // Current node pe balance condition fail ho gayi
        if(abs(lh-rh) > 1)
        {
            return -1;
        }

        // Height parent ko return karo
        return 1 + max(lh,rh);
    }
}; 
    