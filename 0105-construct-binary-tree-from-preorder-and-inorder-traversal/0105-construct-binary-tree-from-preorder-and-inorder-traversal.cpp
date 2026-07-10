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
     // Value -> Index in inorder
    unordered_map<int,int> mp;

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd)
    {
        // Subtree hi exist nahi karti
        if(preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }

        // Preorder ka first element hamesha root hota hai
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Inorder me root kaha hai?
        int inRoot = mp[root->val];

        // Left subtree me kitne nodes hain?
        int numsLeft = inRoot - inStart;

        // -------- Left Subtree --------
        root->left = build(preorder,
                           preStart + 1,
                           preStart + numsLeft,
                           inorder,
                           inStart,
                           inRoot - 1);

        // -------- Right Subtree --------
        root->right = build(preorder,
                            preStart + numsLeft + 1,
                            preEnd,
                            inorder,
                            inRoot + 1,
                            inEnd);

        // Current subtree ban gayi
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // Pehle hi map bana lo
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        return build(preorder,
                     0,
                     preorder.size()-1,
                     inorder,
                     0,
                     inorder.size()-1);
    }
};
    