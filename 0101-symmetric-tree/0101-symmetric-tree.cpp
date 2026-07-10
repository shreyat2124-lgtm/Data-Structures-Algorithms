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
    bool isSymmetric(TreeNode* root) {
        // Empty tree hamesha symmetric hoti hai
        if(root == NULL)
        {
            return true;
        }

        // Root ke left aur right subtree ko compare karo
        return mirror(root->left, root->right);
    }

    // Compare TWO subtrees together
    bool mirror(TreeNode* leftTree, TreeNode* rightTree)
    {
        // ---------------- BASE CASES ----------------

        // Dono NULL hain
        // Mirror hai
        if(leftTree == NULL && rightTree == NULL)
        {
            return true;
        }

        // Ek NULL hai, ek nahi
        // Mirror nahi ho sakte
        if(leftTree == NULL || rightTree == NULL)
        {
            return false;
        }

        // Data same hona chahiye
        if(leftTree->val != rightTree->val)
        {
            return false;
        }

        // ---------------- RECURSION ----------------
        // Mirror check:
        // Left ka Left  ↔ Right ka Right
        // Left ka Right ↔ Right ka Left

        return mirror(leftTree->left, rightTree->right)
            && mirror(leftTree->right, rightTree->left);
    }

    
};
    