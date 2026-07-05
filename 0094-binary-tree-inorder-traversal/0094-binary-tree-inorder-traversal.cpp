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

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        // Start from root
        TreeNode* curr = root;

        while(curr != NULL)
        {
            // Case 1:
            // No left child.
            // We can directly visit this node.
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);

                // Move to right subtree
                curr = curr->right;
            }

            // Case 2:
            // Left subtree exists.
            else
            {
                // Find inorder predecessor
                // (rightmost node of left subtree)
                TreeNode* prev = curr->left;

                while(prev->right != NULL &&
                      prev->right != curr)
                {
                    prev = prev->right;
                }

                // First time visiting this subtree.
                // Create a temporary thread.
                if(prev->right == NULL)
                {
                    prev->right = curr;

                    // Explore left subtree
                    curr = curr->left;
                }

                // Second time we came back.
                else
                {
                    // Remove temporary thread
                    prev->right = NULL;

                    // Left subtree finished,
                    // now visit current node
                    ans.push_back(curr->val);

                    // Move to right subtree
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
 
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);

        return ans;
    }

     void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
            return;

        
        // Visit left subtree
        inorder(root->left, ans);
        // Process current node 
        ans.push_back(root->val);
        // Visit right subtree
        inorder(root->right, ans);
        
        
    }
};*/