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
    
    int maxDepth(TreeNode* root)
    {
        // Empty tree ki height 0 hoti hai
        if(root == NULL)
        {
            return 0;
        }

        // Left subtree kitni depth tak jaa raha hai
        int lh = maxDepth(root->left);

        // Right subtree kitni depth tak jaa raha hai
        int rh = maxDepth(root->right);

        // Jo side zyada deep hai usko choose karo
        return 1 + max(lh,rh);
   
    }
};