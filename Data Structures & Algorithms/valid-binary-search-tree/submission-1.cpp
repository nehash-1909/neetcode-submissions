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
    bool ValidTree(TreeNode* root, long lowerLimit, long upperLimit)
    {
        if(!root)
            return true;
        
        if(!(root->val > lowerLimit && root->val < upperLimit))
            return false;
        
        return ValidTree(root->left, lowerLimit , root->val) && ValidTree(root->right, root->val, upperLimit);
    } 
    bool isValidBST(TreeNode* root) 
    {

        if(!root)
            return true;

        return ValidTree(root, LONG_MIN, LONG_MAX);

        
    }
};
