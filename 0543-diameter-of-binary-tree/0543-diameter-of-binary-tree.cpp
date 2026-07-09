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
    int diameterOfBinaryTree(TreeNode* root) {
       
        // Maximum diameter store karega
        int diameter = 0;

        // Height calculate karte waqt diameter bhi update hoga
        height(root, diameter);

        return diameter;
    }

    int height(TreeNode* root, int &diameter)
    {
        // Empty tree ki height 0
        if(root == NULL)
        {
            return 0;
        }

        // Left subtree ki height
        int lh = height(root->left, diameter);

        // Right subtree ki height
        int rh = height(root->right, diameter);

        // Current node se maximum path check karo
        diameter = max(diameter, lh + rh);

        // Parent ko current subtree ki height return karo
        return 1 + max(lh, rh);
    }
};
   