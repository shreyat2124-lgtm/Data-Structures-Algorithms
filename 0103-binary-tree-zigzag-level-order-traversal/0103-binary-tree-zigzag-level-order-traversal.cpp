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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;

        // Tree empty hai
        if(root == NULL)
        {
            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);

        // Pehla level Left -> Right hoga
        bool leftToRight = true;

        while(!q.empty())
        {
            int size = q.size();

            // Current level ke liye jagah pehle hi bana do
            vector<int> level(size);

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                // Direction ke hisaab se index choose karo
                int index;

                if(leftToRight)
                {
                    index = i;
                }
                else
                {
                    index = size-1-i;
                }

                // Value ko sahi position pe rakho
                level[index] = temp->val;

                // Next level ke nodes queue me daalo
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }

                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }

            // Current level complete
            ans.push_back(level);

            // Agla level opposite direction me hoga
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
    