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
    TreeNode* getSuccessor(TreeNode* root) 
    {
        while(root->left)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return NULL;
        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);   
        }
        else
        {
            // No child
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // one child
            if(root->left== NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // two child
            TreeNode* succ = getSuccessor(root->right);
            root->val = succ->val;

            // delete right element
            root->right = deleteNode(root->right,succ->val);

        }

        return root;
        
    }
};