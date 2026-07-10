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
    unordered_map<int,int> mp;

    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd)
    {
        // Subtree exist nahi karti
        if(postStart > postEnd || inStart > inEnd)
        {
            return NULL;
        }

        // Postorder ka LAST element current root hota hai
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // Inorder me root kaha hai?
        int inRoot = mp[root->val];

        // Left subtree me kitne nodes hain?
        int numsLeft = inRoot - inStart;

        // ---------- RIGHT ----------
        // Right pehle build karna padega,
        // kyunki postorder me root ke just pehle right subtree hoti hai
        root->right = build(postorder,
                            postStart + numsLeft,
                            postEnd - 1,
                            inorder,
                            inRoot + 1,
                            inEnd);

        // ---------- LEFT ----------
        root->left = build(postorder,
                           postStart,
                           postStart + numsLeft - 1,
                           inorder,
                           inStart,
                           inRoot - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        return build(postorder,
                     0,
                     postorder.size()-1,
                     inorder,
                     0,
                     inorder.size()-1);
    }
};
    