class Solution {
public:

    int widthOfBinaryTree(TreeNode* root)
    {
        // Tree hi nahi hai toh width bhi 0
        if(root == NULL)
        {
            return 0;
        }

        // Maximum width store karega
        long long ans = 0;

        // Queue me node ke saath uska Complete Binary Tree index bhi store karenge
        queue<pair<TreeNode*, long long>> q;

        // Root hamesha index 0 se start karega
        q.push({root,0});

        // Normal Level Order Traversal
        while(!q.empty())
        {
            // Current level me kitne nodes hain
            int size = q.size();

            // Current level ka pehla index
            // Isko subtract karenge taaki bade numbers na bane
            long long minIndex = q.front().second;

            // Level ke first aur last node ke normalized indices
            long long first = 0;
            long long last = 0;

            // Current level ke saare nodes process karo
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front().first;

                // Current node ka normalized index
                long long index = q.front().second - minIndex;

                q.pop();

                // Pehla node mila toh iska index yaad rakho
                if(i==0)
                {
                    first = index;
                }

                // Last node tak update karte jao
                if(i==size-1)
                {
                    last = index;
                }

                // Left child ka Complete Binary Tree index
                if(temp->left != NULL)
                {
                    q.push({temp->left,2*index+1});
                }

                // Right child ka Complete Binary Tree index
                if(temp->right != NULL)
                {
                    q.push({temp->right,2*index+2});
                }
            }

            // Current level ki width nikal lo
            ans = max(ans,last-first+1);
        }

        return (int)ans;
    }
};