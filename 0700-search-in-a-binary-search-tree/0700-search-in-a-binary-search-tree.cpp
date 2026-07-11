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
       TreeNode* searchBST(TreeNode* root, int val)
    {
        // Jab tak tree khatam na ho
        while(root != NULL)
        {
            // ---------- FOUND ----------
            // Current node hi answer hai
            if(root->val == val)
            {
                return root;
            }

            // ---------- GO LEFT ----------
            // Chhota value sirf left me mil sakta hai
            if(val < root->val)
            {
                root = root->left;
            }

            // ---------- GO RIGHT ----------
            // Bada value sirf right me mil sakta hai
            else
            {
                root = root->right;
            }
        }

        // Value exist hi nahi karti
        return NULL;
    }
};
    