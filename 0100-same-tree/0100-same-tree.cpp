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
    bool isSameTree(TreeNode* p, TreeNode* q) {
           // Dono trees ek saath khatam hue
        if(p== NULL && q== NULL)
        {
            return true;
        }

        // Ek tree khatam hua, dusra nahi
        if(p == NULL || q == NULL)
        {
            return false;
        }

        // Current node ki value alag hai
        if(p->val != q->val)
        {
            return false;
        }

        // Left subtree identical hai ya nahi
        bool left = isSameTree(p->left, q->left);

        // Right subtree identical hai ya nahi
        bool right = isSameTree(p->right, q->right);

        // Current trees tabhi same honge jab dono sides same ho
        return left && right;
    }
};
    