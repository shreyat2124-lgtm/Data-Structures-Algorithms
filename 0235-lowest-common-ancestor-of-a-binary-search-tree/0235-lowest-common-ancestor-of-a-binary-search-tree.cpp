/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        // Jab tak answer na mil jaye
        while(root != NULL)
        {
            // ---------- BOTH LEFT ----------
            // Dono values current node se chhoti hain
            // Toh LCA sirf left subtree me ho sakta hai
            if(p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }

            // ---------- BOTH RIGHT ----------
            // Dono values current node se badi hain
            // Toh LCA sirf right subtree me ho sakta hai
            else if(p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }

            // ---------- SPLIT POINT ----------
            // Ek left me hai, ek right me hai
            // Ya current node hi p/q me se ek hai
            // Yehi Lowest Common Ancestor hai
            else
            {
                return root;
            }
        }

        return NULL;
    }
};
    