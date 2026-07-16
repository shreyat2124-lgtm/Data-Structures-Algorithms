/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
// ---------- SERIALIZE ----------
    string serialize(TreeNode* root)
    {
        // Empty tree
        if(root == NULL)
            return "";

        string ans = "";
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            // NULL bhi store karna zaroori hai.
            // Warna original tree structure reconstruct nahi hoga.
            if(temp == NULL)
            {
                ans += "N ";
            }
            else
            {
                // Current node store karo.
                ans += to_string(temp->val) + " ";

                // Future me inke children process karenge.
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return ans;
    }

    // ---------- DESERIALIZE ----------
    TreeNode* deserialize(string data)
    {
        // Empty string = Empty tree
        if(data == "")
            return NULL;

        stringstream ss(data);

        string value;

        // Pehla value root hoga.
        ss >> value;

        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* parent = q.front();
            q.pop();

            // ---------- LEFT CHILD ----------
            ss >> value;

            if(value != "N")
            {
                parent->left = new TreeNode(stoi(value));

                // Iske children baad me banenge.
                q.push(parent->left);
            }

            // ---------- RIGHT CHILD ----------
            ss >> value;

            if(value != "N")
            {
                parent->right = new TreeNode(stoi(value));

                // Iske children baad me banenge.
                q.push(parent->right);
            }
        }

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));