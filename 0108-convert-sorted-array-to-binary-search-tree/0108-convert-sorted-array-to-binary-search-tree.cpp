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

    TreeNode* build(vector<int>& nums, int left, int right)
    {
        // ---------- BASE CASE ----------
        // Koi element nahi bacha
        if(left > right)
        {
            return NULL;
        }

        // ---------- ROOT ----------
        // Middle element ko root banao
        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // ---------- LEFT HALF ----------
        // Middle ke left wale elements
        root->left = build(nums, left, mid - 1);

        // ---------- RIGHT HALF ----------
        // Middle ke right wale elements
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};
    