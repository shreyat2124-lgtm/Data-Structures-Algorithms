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

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // Final answer
        vector<vector<int>> ans;

        // Agar tree hi nahi hai
        if(root == NULL)
        {
            return ans;
        }
        
        map<int, map<int, multiset<int>>> mp;
        /*  mp ka structure:
            Horizontal Distance
                    ↓
                Level
                    ↓
            Sorted Nodes

            Example:
            HD = 0
                  |
                  |
              Level 0 -> {1}

              Level 2 -> {9,10}

            Isliye use kiya:map<int, map<int, multiset<int>>>

            Outer Map     -> HD ko sorted rakhega
            Inner Map     -> Levels ko sorted rakhega
            Multiset      -> Same level pe multiple nodes aaye
                             toh automatically sorted rahenge
        */

         queue<pair<TreeNode*, pair<int,int>>> q;
        /*
            Queue me store karenge

            Node
            +
            Horizontal Distance
            +
            Level

            Example

            (1 , {0,0})

            Root ka HD = 0
            Root ka Level = 0
        */

       

        q.push({root,{0,0}});

        // Normal Level Order Traversal
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            TreeNode* temp = curr.first;

            // Current node kis vertical line pe hai
            int hd = curr.second.first;

            // Current node kis level pe hai
            int level = curr.second.second;

            /*
                Is node ko uske  HD aur Level ke andar store kar do.
                Agar same jagah pe already koi node hai
                toh multiset automatically usko sort kar dega.
            */

            mp[hd][level].insert(temp->val);

            // Left child
            if(temp->left != NULL)
            {
                /*
                    Left jaoge HD -1 Level +1 Kyunki ek level niche bhi gaye
                */

                q.push({temp->left,{hd-1,level+1}});
            }

            // Right child

            if(temp->right != NULL)
            {
                /*
                    Right jaoge HD +1 Level +1
                */

                q.push({temp->right,{hd+1,level+1}});
            }
        }

        /*
            Ab map kuch aisa dikhega

            HD -2

                Level2 -> {4}

            HD -1

                Level1 -> {2}

            HD 0

                Level0 -> {1}

                Level2 -> {9,10}

            HD 1

                Level1 -> {3}

            HD 2

                Level2 -> {10}
        */

        // Ek-ek vertical line uthao

        for(auto vertical : mp)
        {
            vector<int> col;

            // Us vertical ke andar saare levels traverse karo
        
            for(auto lvl : vertical.second)
            {

                for(int node : lvl.second)
                {
                    col.push_back(node);
                }
            }

            // Ek poori vertical line answer me daal do
            ans.push_back(col);
        }

        return ans;
    }
};