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
   
      // 'i' keeps track of which preorder element we're currently using
    TreeNode* build(vector<int>& preorder, int& i, int bound)
    {
        // ---------- BASE CASE ----------
        // 1. Saare elements use ho gaye
        // 2. Current value is not allowed in this subtree
        if(i == preorder.size() || preorder[i] > bound)
        {
            return NULL;
        }

        // ---------- CREATE ROOT ----------
        // Current preorder element becomes the root
        TreeNode* root = new TreeNode(preorder[i]);

        // Move to the next preorder element
        i++;

        // ---------- BUILD LEFT ----------
        // Left subtree can contain only values < root->val
        root->left = build(preorder, i, root->val);

        // ---------- BUILD RIGHT ----------
        // Right subtree can contain values > root
        // but still within the parent's bound
        root->right = build(preorder, i, bound);

        // Return the completed subtree
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        // Start reading preorder from index 0
        int i = 0;

        // Initially there is no upper limit
        return build(preorder, i, INT_MAX);
    }
};
    