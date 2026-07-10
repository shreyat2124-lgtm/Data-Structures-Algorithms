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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // Tree khatam ho gaya, yaha answer nahi mila
        if(root == NULL)
        {
            return NULL;
        }

        // Agar p ya q mil gaya, isi node ko upar bhej do
        // Parent decide karega ki ye final answer hai ya nahi
        if(root == p || root == q)
        {
            return root;
        }

        // Left subtree se pooch rahe hain:
        // "Kya tumhare andar p, q ya unka LCA hai?"
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Right subtree se bhi wahi question pooch rahe hain
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Dono taraf kuch nahi mila
        if(left == NULL && right == NULL)
        {
            return NULL;
        }

        // Sirf right subtree ko answer mila
        // Isliye wahi answer upar bhej do
        if(left == NULL)
        {
            return right;
        }

        // Sirf left subtree ko answer mila
        // Isliye wahi answer upar bhej do
        if(right == NULL)
        {
            return left;
        }

        // Left aur right dono taraf ek-ek target mila
        // Matlab current node hi first common ancestor hai
        return root;
    }
};
    