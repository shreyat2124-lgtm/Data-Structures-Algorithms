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
    int widthOfBinaryTree(TreeNode* root) {
        // Empty tree has width 0
if(root == NULL)
{
    return 0;
}

long long ans = 0;

// Queue stores (Node, Complete Binary Tree Index)
queue<pair<TreeNode*, long long>> q;

// Root starts with index 0
q.push({root,0});

while(!q.empty())
{
    // Number of nodes in current level
    int size = q.size();

    // First index of current level (used for normalization)
    long long minIndex = q.front().second;

    // Stores normalized index of first node
    long long first = 0;

    // Stores normalized index of last node
    long long last = 0;

    // Traverse one complete level
    for(int i=0;i<size;i++)
    {
        TreeNode* temp = q.front().first;

        // Normalize index to avoid overflow
        long long index = q.front().second - minIndex;

        q.pop();

        // Save first node's index
        if(i==0)
            first=index;

        // Save last node's index
        if(i==size-1)
            last=index;

        // Left child gets 2i-1
        if(temp->left!=NULL)
            q.push({temp->left,2*index+1});

        // Right child gets 2i+1
        if(temp->right!=NULL)
            q.push({temp->right,2*index+2});
    }

    // Width = Last Index - First Index + 1
    ans=max(ans,last-first+1);
}

// Return maximum width
return (int)ans;
    }
};