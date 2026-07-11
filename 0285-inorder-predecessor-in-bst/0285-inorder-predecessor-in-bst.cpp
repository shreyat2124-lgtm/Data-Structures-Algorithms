/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* predecessor = NULL;

        while(root != NULL)
        {
            // ---------- POSSIBLE PREDECESSOR ----------
            // Current node p se chhota hai.
            // Ye predecessor ho sakta hai.
            // Lekin aur bada valid predecessor right subtree me mil sakta hai.
            if(root->val < p->val)
            {
                predecessor = root;
                root = root->right;
            }

            // ---------- GO LEFT ----------
            // Current node p se bada ya equal hai.
            // Predecessor sirf left subtree me hi mil sakta hai.
            else
            {
                root = root->left;
            }
        }

        // Largest value smaller than p
        return predecessor;
    }
};
