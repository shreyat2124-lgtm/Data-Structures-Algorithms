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
   // DFS returns:
    // "Parent mujhe use kare toh maximum kitna sum le jaa sakta hai?"
    int solve(TreeNode* root, int &maxSum)
    {
        // Tree khatam
        if(root == NULL)
        {
            return 0;
        }

        // Left subtree se best single path lo
        int left = solve(root->left, maxSum);

        // Right subtree se best single path lo
        int right = solve(root->right, maxSum);

        // Negative path kabhi answer improve nahi karega
        // Isliye usse ignore kar do
        left = max(0, left);
        right = max(0, right);

        // Agar path current node pe turn kare
        // Toh dono sides use kar sakte hain
        maxSum = max(maxSum, left + right + root->val);

        // Parent ko sirf ek side hi de sakte hain
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root)
    {
        int maxSum = INT_MIN;

        solve(root, maxSum);

        return maxSum;
    }
};  
