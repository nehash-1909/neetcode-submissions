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
    int heightTree(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return max(heightTree(root->left), heightTree(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
            return true;
        
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);

        if(abs(rightHeight - leftHeight) > 1 )
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);


        
    }
};
