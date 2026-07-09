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

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // Final answer
        vector<vector<int>> ans;

        // Tree hi nahi hai
        if(root == NULL)
        {
            return ans;
        }

        // Queue BFS ke liye
        queue<TreeNode*> q;

        // Root se traversal start karo
        q.push(root);

        while(!q.empty())
        {
            // Current level me kitne nodes hain
            int size = q.size();

            // Is level ke nodes store karenge
            vector<int> level;

            // Sirf current level ke nodes process karo
            for(int i=0;i<size;i++)
            {
                // Queue ka front node uthao
                TreeNode* temp = q.front();
                q.pop();

                // Current level me add karo
                level.push_back(temp->val);

                // Left child next level ka part banega
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }

                // Right child bhi next level ka part banega
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }

            // Pura level complete ho gaya
            ans.push_back(level);
        }

        return ans;
    }
};