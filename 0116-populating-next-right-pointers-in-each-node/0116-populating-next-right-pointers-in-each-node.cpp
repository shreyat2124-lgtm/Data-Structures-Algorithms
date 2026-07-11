/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   
    Node* connect(Node* root)
    {
        // Empty tree
        if(root == NULL)
        {
            return NULL;
        }

        // Perfect tree me leaf ke alawa sabke 2 children honge
        if(root->left != NULL)
        {
            // -------- SAME PARENT --------
            // Left child ka next hamesha right child hoga
            root->left->next = root->right;

            // -------- DIFFERENT PARENTS --------
            // Agar current node ka next exist karta hai,
            // toh right child ko uske neighbour ke left child se jodo
            if(root->next != NULL)
            {
                root->right->next = root->next->left;
            }
        }

        // Ab left aur right subtree bhi same logic follow karengi
        connect(root->left);
        connect(root->right);

        return root;
    }
};