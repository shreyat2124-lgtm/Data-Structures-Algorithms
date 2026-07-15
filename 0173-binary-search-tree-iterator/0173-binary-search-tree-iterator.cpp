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
class BSTIterator {
public:
      stack<TreeNode*> st;
    // ---------- PUSH LEFT CHAIN ----------
    // Current node se start karke
    // poori left chain stack me daal do.
    void pushAllLeft(TreeNode* root)
    {
        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root)
    {
        // Initially smallest element chahiye
        // Isliye poori left chain push kar do.
        pushAllLeft(root);
    }

    int next()
    {
        // ---------- NEXT SMALLEST ----------
        // Stack ka top hamesha next smallest hoga.
        TreeNode* temp = st.top();
        st.pop();

        // Agar right subtree exist karti hai,
        // toh us subtree ka smallest element chahiye.
        // Isliye uski poori left chain push kar do.
        if(temp->right != NULL)
        {
            pushAllLeft(temp->right);
        }

        return temp->val;
    }

    bool hasNext()
    {
        // Jab tak stack empty nahi hai,
        // tab tak next element exist karta hai.
        return !st.empty();
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */