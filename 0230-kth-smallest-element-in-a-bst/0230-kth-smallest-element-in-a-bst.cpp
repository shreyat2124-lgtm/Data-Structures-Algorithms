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
    void inorder(TreeNode* root, int& count, int k, int& ans)
    {
        // Tree khatam, ab wapas previous node pe jao
        if(root == NULL)
        {
            return;
        }

        // Pehle poori left subtree complete karo
        inorder(root->left, count, k, ans);

        // Left subtree ho gayi, ab current node visit hui
        count++;

        // Ye kth visited node hai
        if(count == k)
        {
            ans = root->val;
            return;
        }

        // Ab right subtree visit karo
        inorder(root->right, count, k, ans);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        int count = 0;   // Kitne nodes visit hue
        int ans = -1;    // Final answer

        inorder(root, count, k, ans);

        return ans;
    }
};
   