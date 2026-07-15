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
   // ---------- INORDER ----------
    // BST ka inorder hamesha sorted array deta hai.
    void inorder(TreeNode* root, vector<int>& inorderArray)
    {
        if(root == NULL)
            return;

        inorder(root->left, inorderArray);

        // Current node ko sorted array me store karo.
        inorderArray.push_back(root->val);

        inorder(root->right, inorderArray);
    }

    bool findTarget(TreeNode* root, int k)
    {
        vector<int> inorderArray;

        // Step 1
        // BST -> Sorted Array
        inorder(root, inorderArray);

        // Step 2
        // Exactly same as Two Sum on Sorted Array
        int left = 0;
        int right = inorderArray.size() - 1;

        while(left < right)
        {
            int sum = inorderArray[left] + inorderArray[right];

            // Pair mil gaya.
            if(sum == k)
                return true;

            // Sum chhota hai.
            // Bigger number chahiye.
            // Left pointer ko aage badhao.
            else if(sum < k)
                left++;

            // Sum bada hai.
            // Smaller number chahiye.
            // Right pointer ko peeche lao.
            else
                right--;
        }

        // Koi pair nahi mila.
        return false;
    }

};