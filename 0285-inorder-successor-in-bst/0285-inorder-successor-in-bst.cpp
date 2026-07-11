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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* successor = NULL;

        while(root != NULL)
        {
            // ---------- POSSIBLE SUCCESSOR ----------
            // Current node p se bada hai.
            // Ye successor ho sakta hai.
            // Lekin aur chhota valid successor left subtree me mil sakta hai.
            if(root->val > p->val)
            {
                successor = root;
                root = root->left;
            }

            // ---------- GO RIGHT ----------
            // Current node p se chhota ya equal hai.
            // Successor sirf right subtree me hi mil sakta hai.
            else
            {
                root = root->right;
            }
        }

        // Smallest value greater than p
        return successor;
    }
};