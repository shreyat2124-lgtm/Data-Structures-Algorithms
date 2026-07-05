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

        TreeNode* curr = root;

        while(curr != NULL)
        {
            // If there is no left child,
            // process current node and move right
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);

                curr = curr->right;
            }
            else
            {
                // Find inorder predecessor
                TreeNode* prev = curr->left;

                while(prev->right != NULL &&
                      prev->right != curr)
                {
                    prev = prev->right;
                }

                // Thread not created yet
                if(prev->right == NULL)
                {
                    // Create temporary connection
                    prev->right = curr;

                    curr = curr->left;
                }
                else
                {
                    // Thread already exists

                    // Remove it
                    prev->right = NULL;

                    // Process current node
                    ans.push_back(curr->val);

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