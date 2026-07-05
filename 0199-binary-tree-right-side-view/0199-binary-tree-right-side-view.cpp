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

    void solve(TreeNode* root,
               int level,
               vector<int>& ans)
    {
        // Tree finished
        if(root == NULL)
            return;

        // First node reaching this level
        if(level == ans.size())
        {
            ans.push_back(root->val);
        }

        // Visit right first
        solve(root->right, level+1, ans);

        // Then visit left
        solve(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;

        solve(root,0,ans);

        return ans;
    }
};