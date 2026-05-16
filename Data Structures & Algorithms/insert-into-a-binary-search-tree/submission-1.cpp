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
    void insertNode(TreeNode* root, int val)
    {

        if(root == NULL)
            return;

        if(root->val <= val)
        {
            if(root->right)
                insertNode(root->right, val);
            else
            {
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }
        }
        else
        {
            if(root->left)
                insertNode(root->left, val);
            else
            {
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {

        if(root == NULL)
        {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        TreeNode* head = root;
        insertNode(head,val);
        return root;    
        
    }
};