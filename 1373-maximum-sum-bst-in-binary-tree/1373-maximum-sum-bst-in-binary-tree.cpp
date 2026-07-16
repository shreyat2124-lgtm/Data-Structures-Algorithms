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
class NodeValue
{
public:
    int minNode;
    int maxNode;
    int sum;
    bool isBST;

    NodeValue(int minNode, int maxNode, int sum, bool isBST)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
public:

    int maxSum = 0;

    NodeValue solve(TreeNode* root)
    {
        // Empty tree is always a BST.
        // min = +INF, max = -INF
        // so parent comparison never fails.
        if(root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0, true);

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        // Current subtree BST tabhi hogi jab:
        // 1. Left BST ho
        // 2. Right BST ho
        // 3. Left ka maximum < Root
        // 4. Root < Right ka minimum

        if(left.isBST && right.isBST &&
           left.maxNode < root->val &&
           root->val < right.minNode)
        {
            int currentSum = left.sum + right.sum + root->val;

            // Maximum BST sum update karo.
            maxSum = max(maxSum, currentSum);

            return NodeValue(

                // Current subtree ka minimum
                min(root->val, left.minNode),

                // Current subtree ka maximum
                max(root->val, right.maxNode),

                // Current subtree ka total sum
                currentSum,

                // Current subtree is a BST
                true
            );
        }

        // Agar BST nahi bani,
        // bas false return karo.
        // min/max ki value matter nahi karti,
        // kyunki parent pehle isBST check karega.
        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

    int maxSumBST(TreeNode* root)
    {
        solve(root);
        return maxSum;
    }
};