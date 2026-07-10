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
    void flatten(TreeNode* root) {
        
        // Current node se start karo
        TreeNode* curr = root;

        // Jab tak tree khatam na ho
        while(curr != NULL)
        {
            // Agar left subtree exist karti hai
            if(curr->left != NULL)
            {
                // ---------------- STEP 1 ----------------
                // Left subtree ka rightmost node dhoondo.
                // Ye flatten hone ke baad left subtree ka LAST node hoga.
                TreeNode* prev = curr->left;

                while(prev->right != NULL)
                {
                    prev = prev->right;
                }

                // ---------------- STEP 2 ----------------
                // Original right subtree ko lose mat karo.
                // Isliye usse left subtree ke last node ke baad attach kar do.
                prev->right = curr->right;

                // ---------------- STEP 3 ----------------
                // Ab left subtree ko right side shift kar do.
                curr->right = curr->left;

                // ---------------- STEP 4 ----------------
                // Left pointer ki ab zarurat nahi.
                curr->left = NULL;
            }

            // ---------------- STEP 5 ----------------
            // Preorder ki tarah right side move karte jao.
            curr = curr->right;
        }
    }
};
    